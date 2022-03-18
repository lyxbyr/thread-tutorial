#include <iostream>
#include <mutex>
#include <string>
#include <thread>
using namespace std;

std::once_flag g_flag;  //系统定义的标记

class Person {
  //只调用一次
  static void CreateInstance() {
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
    // std::call_once()，ｃ++11引入的函数，该函数的第二个参数是一个函数名func();
    // std::call_once()功能保证func()函数只能调用一次
    // std::call_once()具备互斥量这种能力，而且效率上，比互斥量消耗的资源更少；
    // std::call_once()需要一个标记结合使用，这个标记std::once_flag(一个结构);
    // std::call_once()是通过这个标记来决定对应的函数func()是否执行，调用call_once()成功后，
    // call_once()就把这个标记设置为一种已调用状态
    // 后续再调用call_once()后，因为标记"已调用状态"，那么对应的函数func()就不会再执行了；

    std::call_once(g_flag, CreateInstance);
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