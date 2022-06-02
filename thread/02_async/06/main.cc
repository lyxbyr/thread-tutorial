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
  std::promise<int> pret;
  std::thread t1([&] { auto res = download("hello.zip");
      pro });

  interact();
  fut2.wait();

  std::cout << "Download completed" << std::endl;

  return 0;
}