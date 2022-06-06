#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

int main() {
  std::mutex mtx;
  std::condition_variable cv;

  std::thread t1([&] {
    std::unique_lock lck(mtx);
    cv.wait(lck);
    std::cout << "t1 is awake..." << std::endl;
  });

  std::this_thread::sleep_for(std::chrono::milliseconds(400));

  std::cout << "notifying..." << std::endl;
  cv.notify_one();

  t1.join();

  return 0;
}