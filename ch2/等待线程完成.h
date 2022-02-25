//
// Created by lyx on 2021/10/29.
//

#ifndef CH2_等待线程完成_H
#define CH2_等待线程完成_H

struct func;

void f() {
  int some_local_state = 0;
  func my_func(some_local_state);
  std::thread t(my_func);
  try {
    do_something_in_current_thread();
  }
  catch(...) {
    t.join();
    throw;
  }
  t.join();
}














#endif //CH2_等待线程完成_H
