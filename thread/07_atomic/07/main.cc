#include <atomic>
#include <iostream>

int main() {
  std::atomic<int> counter;
  counter.store(0);

  int old = counter.exchange(444);

  std::cout << "old= " << old << std::endl;

  int now = counter.load();

  std::cout << "cnt= " << now << std::endl;

  return 0;
}