#include <iostream>
#include <memory>

struct Foo {
  Foo() {
    std::cout << "Foo:Foo" << std::endl;
  }
  ~Foo() {
    std::cout << "Foo:~Foo" << std::endl;
  }
  void foo() {
    std::cout <<  "foo:foo" << std::endl;
  }
};

void f(const Foo &) {
  std::cout << "f(const Foo&)" << std::endl;
}



int main() {
  std::unique_ptr<Foo> p1(std::make_unique<Foo>());

  if (p1) p1->foo(); //foo:foo
  {
    std::unique_ptr<Foo> p2(std::move(p1));
    f(*p2); //f(const Foo&)
    if (p2) p2->foo();  //foo:foo
    if (p1) p1->foo(); //不输出

    p1 = std::move(p2);
    if (p2) p2->foo(); //不输出
    std::cout << "p2 被销毁" << std::endl;
  }
  if (p1) p1->foo(); //foo:foo
  // Foo 的实例会在离开作用域时被销毁




  return 0;
}
