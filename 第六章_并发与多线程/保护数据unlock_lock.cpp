#include <iostream>
#include <list>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;

vector<int> g_v = {1, 2, 3};  //共享数据，只读

void myprint1(int inum) {
  cout << "id为" << std::this_thread::get_id() << "的线程 打印g_v值" << g_v[0]
       << " " << g_v[1] << " " << g_v[2] << endl;
}

class A {
 public:
  //把收到的消息(玩家命令)入到一个队列的线程
  void inMsgRecvQueue() {
    for (int i = 0; i < 100000; ++i) {
      cout << "inMsgRecvQueue()执行，插入一个元素" << i << endl;
      my_mutex.lock();
      msgRecvQueue.push_back(i);
      my_mutex.unlock();
    }
  }

  bool outMsgULProc(int &command) {
    my_mutex.lock();
    if (!msgRecvQueue.empty()) {
      int command = msgRecvQueue.front();
      msgRecvQueue.pop_front();
      my_mutex.unlock();
      return true;
    }
    my_mutex.unlock();
    return false;
  }

  void outMsgRecvQueue() {
    int command = 0;
    for (int i = 0; i < 100000; ++i) {
      bool result = outMsgULProc(command);
      if (result) {
        cout << "outMsgRecvQueue()执行，取出一个元素" << i << endl;
      } else {
        cout << "outMsgRecvQueue()执行，但目前消息队列中为空" << i << endl;
      }
    }
    cout << "end" << endl;
  }

 private:
  std::list<int> msgRecvQueue;  //容器。专门用于代表玩家给咱们发过来的命令
  std::mutex my_mutex;
};

int main() {
  A myobj;
  std::thread myOutMsgObj(
      &A::outMsgRecvQueue,
      &myobj);  //第二个参数是引用，才能保证线程里用的是同一个对象
  std::thread myInMsgObj(&A::inMsgRecvQueue, &myobj);
  myOutMsgObj.join();
  myInMsgObj.join();
  cout << "I Love China!" << endl;
  return 0;
}