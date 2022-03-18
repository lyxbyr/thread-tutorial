#include <iostream>
#include <mutex>
#include <string>
#include <thread>
using namespace std;

std::mutex resource_mutex;

class Person {
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
    if (m_instance == NULL) {
      std::unique_lock<std::mutex> mymutex(resource_mutex);

      if (m_instance == NULL) {
        m_instance = new Person();
        static PersonRlease pr;
      }
    }
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