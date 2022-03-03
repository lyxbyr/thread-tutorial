#include <iostream>
#include <thread>
#include <vector>
using namespace std;

vector<int> g_v = {1, 2, 3};  //共享数据，只读

void myprint1(int inum) {
  cout << "id为" << std::this_thread::get_id() << "的线程 打印g_v值" << g_v[0]
       << " " << g_v[1] << " " << g_v[2] << endl;
}

int main() {
  vector<thread> mythreads;

  for (int i = 0; i < 10; ++i) {
    mythreads.push_back(thread(myprint1, i));
  }
  for (auto iter = mythreads.begin(); iter != mythreads.end(); ++iter) {
    iter->join();
  }
  cout << "I Love China!" << endl;
  return 0;
}