#include <iostream>
#include <thread>
#include <future>


int main() {
  //将一个返回值为7的lambad表达式封装到task中
  //std::packaged_task的模板参数为要封装函数的类型
  std::packaged_task<int()> task([](){return 7;});
  //获得task的期物
  //在封装好要调用的目标后，可以使用 get_future() 来获得一个 std::future 对象，以便之后实施线程同步。
  std::future<int> result = task.get_future();//在一个线程中执行task
  std::thread(std::move(task)).detach();
  std::cout << "waiting...";
  result.wait(); //在此设置屏障，阻塞到期物的完成
  std::cout << "done!" << std::endl << "future result is " << result.get() << std::endl;
  return 0;
}
