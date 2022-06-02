#include <chrono>
#include <iostream>
#include <thread>

int main() {
  auto t = std::chrono::steady_clock::now() + std::chrono::milliseconds(400);
  std::this_thread::sleep_until(t);
  return 0;
}