#include <future>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
int download(std::string file) {
  for (int i = 0; i < 10; ++i) {
    std::cout << "Downloading " << file << " (" << i * 10 << "%)..."
              << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
  }
  std::cout << "Download complete: " << file << std::endl;
  return 404;
}

void interact() {
  std::string name;
  std::cin >> name;
  std::cout << "Hi, " << name << std::endl;
}

int main() {
  std::future<int> fut = std::async([&] { return download("hello.zip"); });
  interact();

  while (true) {
    std::cout << "Waiting for download complete..." << std::endl;
    auto stat = fut.wait_for(std::chrono::milliseconds(1000));
    if (stat == std::future_status::ready) {
      std::cout << "Future is ready!!" << std::endl;
      break;
    } else {
      std::cout << "Future is not  ready!!" << std::endl;
    }
  }

  int res = fut.get();
  std::cout << "Download result: " << res << std::endl;

  return 0;
}