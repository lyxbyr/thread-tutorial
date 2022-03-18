#include <chrono>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
using namespace std;

std::mutex resource_mutex;
std::once_flag g_flag;  //系统定义的标记

class Person {
  //只调用一次
  static void CreateInstance() {
    std::chrono::milliseconds dura(20000);
    std::this_thread::sleep_for(dura);

    cout << "CreateInstane()被执行了" << endl;
    m_instance = new Person();
    static PersonRlease pr;
  }

 private:
  Person() : age_(35), name_("Bob") {}

 private:
  static Person *m_instance;
  int age_;
  string name_;

 public:
  static Person *GetInstance() {
    //提高效率
    //ａ) if(m_instance != NULL) 条件成立，则m_instance肯定被new过了
    // b) if(M_instance == NULL)
    // 条件成立，则不能代表m_instance一定没有new过(可能new过或者没有new过)
    //双重锁定(双重检查)

    // if (m_instance == NULL) {
    //   std::unique_lock<std::mutex> mymutex(resource_mutex);

    //   if (m_instance == NULL) {
    //     m_instance = new Person();
    //     static PersonRlease pr;
    //   }
    // }

    //假如两个线程，两个线程同时执行到这里，其中一个线程要等另外一个线程执行完毕CreateInstance()
    std::call_once(g_flag, CreateInstance);

    cout << "call_once() end" << endl;
    return m_instance;
  }

  void setAge(int age) { age_ = age; }
  void setName(string name) { name_ = name; }

  int getAge() { return age_; }
  string getName() { return name_; }

  void func() {
    cout << "age:" << age_ << endl;
    cout << "name:" << name_ << endl;
  }
  void someFunction() {
    Person *p_a = Person::GetInstance();
    p_a->func();
  }

  class PersonRlease {
   public:
    ~PersonRlease() {
      if (Person::m_instance) {
        delete m_instance;
      }
      Person::m_instance = NULL;
    }
  };
};

Person *Person::m_instance = NULL;

void mythread() {
  cout << "---thread begin---" << endl;
  Person *ps = Person::GetInstance();
  cout << "---thread end---" << endl;
  return;
}

int main() {
  std::thread myjob1(mythread);
  std::thread myjob2(mythread);
  myjob1.join();
  myjob2.join();

  return 0;
}