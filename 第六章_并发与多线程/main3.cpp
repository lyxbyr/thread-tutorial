#include <iostream>
#include <map>
#include <string>
#include <thread>

using namespace std;

class A {
 public:
  int m_i;
  A(int a) : m_i(a) { cout << "[A::A(const A)构造函数执行]" << endl; }
  A(const A &a) : m_i(a.m_i) {
    cout << "[A::A(const A)拷贝构造函数执行]" << endl;
  }
  ~A() { cout << "[A::~A()拷贝构造函数执行]" << endl; }

  void thread_works(int num) {
    cout << "[子线程thread_work执行]"
         << "threadid=" << std::this_thread::get_id() << std::endl;
  }

  void operator()(int num) {
    cout << "[子线程()执行]"
         << "threadid=" << std::this_thread::get_id() << std::endl;
  }
};

void myprint(const int &i, char *pmybuf) {
  cout << i << endl;       // i并不是mvar的引用，实际是值传递
  cout << pmybuf << endl;  //指针在detach子线程时会有问题
}

void myprint1(const int i, const string &pmybuf) {
  cout << i << endl;
  cout << pmybuf << endl;
}

void myprint2(const int i, const A &pmybuf) { cout << &pmybuf << endl; }
int main() {
  // int mvar = 1;
  // int &mvary = mvar;
  // char mybuf[] = "this is a test!";
  // thread mytobj(myprint, mvar, mybuf);
  // thread mytobj(myprint1, mvar, string(mybuf));
  // mytobj.join();

  int mvar = 1;
  int mysecondpar = 12;
  // thread mytobj1(myprint2, mvar, mysecondpar);
  thread mytobj1(myprint2, mvar, A(mysecondpar));

  mytobj1.join();
  // mytobj1.detach();

  A myobj(10);
  //用成员函数指针作为线程函数
  //std::thread myTobj(&A::thread_works, myobj, 15);
  std::thread myTobj(myobj, 15);

  myTobj.join();

  cout << "=============" << endl;
  return 0;
}
