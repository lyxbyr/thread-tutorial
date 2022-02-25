#include <iostream>
#include <memory>


/*
 * 如果使用shared_ptr
 * 运行结果是 A, B 都不会被销毁，这是因为 a,b 内部的 pointer 同时又引用了 a,b，
 * 这使得 a,b 的引用计数均变为了 2，而离开作用域时，a,b 智能指针被析构，却只能造成这块区域的引用计数减一，
 * 这样就导致了 a,b 对象指向的内存区域引用计数不为零，而外部已经没有办法找到这块区域了，也就造成了内存泄露
 */
struct A;
struct B;
struct A {
  std::weak_ptr<B> pointer;
  ~A() {
    std::cout << "A被销毁" << std::endl;
  }
};

struct B {
  std::weak_ptr<A> pointer;
  ~B() {
    std::cout << "B被销毁" << std::endl;
  }
};



int main() {
  auto a = std::make_shared<A>();
  auto b = std::make_shared<B>();
  a->pointer = b;
  b->pointer = a;
  std::cout << "a pointer use count:" << b.use_count() << std::endl;
  std::cout << "a pointer use count:" << a.use_count() << std::endl;

  return 0;
}
