#include <iostream>

using namespace std;

class Singleton {
 private:
  Singleton() {}

 private:
  static Singleton *m_instance;  //静态成员变量

 public:
  static Singleton *GetInstance() {
    if (m_instance == NULL) {
      m_instance = new Singleton();
      static SingletonRlease SR;
    }

    return m_instance;
  }
  //类中嵌套类，用来释放对象
  class SingletonRlease {
   public:
    ~SingletonRlease() {
      if (Singleton::m_instance) {
        delete Singleton::m_instance;
      }
      Singleton::m_instance = NULL;
    }
  };

  void func() { cout << "---Singleton Test---" << endl; }
};

//类静态变量初始化
Singleton *Singleton::m_instance = NULL;

int main() {
  //创建一个对象，返回该类Singleton对象的指针
  Singleton *p_s = Singleton::GetInstance();
  p_s->func();

  return 0;
}
