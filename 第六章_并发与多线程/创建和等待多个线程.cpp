#include <iostream>
#include <thread>
#include <vector>
using namespace std;

void myprint(int inum) {
  cout << "myprint线程开始执行了。线程编号=" << inum << endl;

  cout << "myprint线程结束执行了。线程编号=" << inum << endl;
  return;
}

int main() {
  vector<thread> mythreads;

  for (int i = 0; i < 10; ++i) {
    mythreads.push_back(thread(myprint, i));
  }
  for (auto iter = mythreads.begin(); iter != mythreads.end(); ++iter) {
    iter->join();
  }
  cout << "I Love China!" << endl;
  return 0;
}