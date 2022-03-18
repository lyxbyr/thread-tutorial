#include <iostream>
#include <string>
using namespace std;

class Person {
 private:
  Person() : age_(35), name_("Bob") {}

 private:
  static Person *m_instance;
  int age_;
  string name_;

 public:
  static Person *GetInstance() {
    if (m_instance == NULL) {
      m_instance = new Person();
      static PersonRlease pr;
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

int main() {
  Person *p_s = Person::GetInstance();
  p_s->func();
  p_s->setAge(24);
  p_s->setName("jack");
  p_s->someFunction();

  return 0;
}