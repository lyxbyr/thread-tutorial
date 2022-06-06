#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

int main() {
  std::mutex mtx;
  std::condition_variable cv;
  bool ready = false;

  std::thread t1([&] {
    std::unique_lock lck(mtx);
    cv.wait(lck, [&] { return ready; });
    std::cout << "t1 is awake..." << std::endl;
  });

  std::thread t2([&] {
    std::unique_lock lck(mtx);
    cv.wait(lck, [&] { return ready; });
    std::cout << "t2 is awake..." << std::endl;
  });

  std::thread t3([&] {
    std::unique_lock lck(mtx);
    cv.wait(lck, [&] { return ready; });
    std::cout << "t3 is awake..." << std::endl;
  });

  std::this_thread::sleep_for(std::chrono::milliseconds(400));

  std::cout << "notifying... one" << std::endl;
  ready = true;
  cv.notify_one();

  std::this_thread::sleep_for(std::chrono::milliseconds(400));

  std::cout << "notifying... all" << std::endl;
  cv.notify_all();

  t1.join();
  t2.join();
  t3.join();

  return 0;
}