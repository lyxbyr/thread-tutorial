//
// Created by lyx on 2021/10/29.
//

#ifndef CH2_FUNC_H
#define CH2_FUNC_H

struct func {
  int& i;
  func*(int& i_) : i(i_) {

  }
  void operator() () {
    for (unsigned  j = 0; j < 10000000; ++j) {
      do_something(i);
    }
  }
};

void oops() {
  int some_local_state = 0;
  func my_func(some_local_state);
  std::thread my_thread(my_func);
  my_thread.detach();
}

#endif //CH2_FUNC_H
