# 第一节 并发基本概念及实现，进程，线程基本概念

## 并发、进程、线程的基本概念和综述

### 并发
- 两个或更多的任务同时发生

### 可执行程序

### 进程
- 可执行文件运行起来即是一个进程
  
### 线程
-每个进程(执行起来的可执行程序)，都有一个主线程，这个主线程是唯一的，也就是一个进程中只能有一个主线程
- 当你执行可执行文件时，产生了一个进程后，这个主线程就随着这个进程程序默默地启动起来了
  

### 总结
- 线程是用来执行代码的
- 把线程理解一条代码的执行通路，一个新线程代表一个新的通路
- 一个进程自动包含一个主线程，主线程随着进程默默的启动并运行，可以通过编码来创建多个其他线程(非主线程)
- 主线程是自动启动的，所以一个进程中最少也是有一个线程(主线程)



## 并发的实现方法

### 多进程并发

- 多进程并发：word启动后就是进程，ie浏览器启动后就是进程；进程之间通信(同一个电脑上：管道、文件、消息队列、共享内存)
### 多线并发
- 多线程并发:每个线程都有自己独立的运行路径，但是一个进程中的所以线程共享地址空间(共享内存)，全局变量，指针，引用，都可以在线程之间传递，所以使用多线程的开销远小于多进程；共享内存带来的新问题，数据一致性的问题
  
### 总结
- 系统资源开销更少，执行速度更快
- 数据一致性问题

## c++11新标准线程库

- c++11新标准增加了对多线程的支持，可移植性(跨平台)


# 第二节 线程启动、结束、创建线程、join、detach

## 演示线程运行的开始和结束

### thread

### join()

### detach()

### joinable()


## 其他创建线程的方法


### 用类，以及一个问题范例

```
TA ta;
thread myjobs(ta);
myjobs.join();

```

### 用lambda表达式
```
auto mylamthread = [] {
  cout << "=========" << endl;
}
thread myjobs(mylamthread);
myjobs.join();

```
  
# 第三节 线程传递详解，成员函数作为线程函数
## 传递临时对象作为线程参数

### 线程id的概念

### 临时对象构造

## 传递类对象、智能指针作为线程参数

- std::ref 不调用拷贝构造函数

## 用成员函数指针作为线程函数



# 第四节 创建多个线程、数据共享问题、案例代码

## 创建和等待多个线程
```
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
```

## 数据共享问题分析

### 只读的数据
- 只读的数据，是安全稳定的，不需要特别处理手段就可以直接读

```
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
```

### 有读有写

### 其他案例

## 共享数据的保护案例代码


# 第五节 互斥量概念、用法、死锁演示及解释详解

## 互斥量(mutex)的基本概念

-  互斥量是个类对象，理解成一把锁，多个线程尝试用lock()成员函数来加锁这把锁头，只有一个线程能够锁定成功
-  如果没有锁成功，那么流程卡在lock()这里不断的尝试去锁这把锁头
-  互斥量使用需要小心
-  一个互斥量一把锁
  

## 互斥量的用法
- #include<mutex>
- lock(), unlock(), 先lock(),操作数据,unlock()
- 成对使用
- 
### lock(), unlock()

### std::lock_guard类模板-RAII
- 直接取代lock(), unlock()
- lock_guard构造函数执行了mutex::lock()
- lock_guard析构函数执行了mutex::unlock()
  

## 死锁

- 是由至少两个锁头也就是两个互斥量才能产生
- 

### 死锁演示

### 死锁的一般解决方案

- 保持上锁先后顺序一致，解锁顺序可以不需要一致

### std::lock()函数模板


- 一次锁住两个或者两个以上的互斥量(至少两个， 多了不限)即处理多个互斥量
- 不存在这种因为多个线程中 锁的顺序问题导致死锁的风险问题
- std::lock():如果互斥量中有一个没有锁住，它就在那里等着，等所有互斥量都锁住，他才能往下走
- 要么两个互斥量都锁住，要么两个互斥量都没有锁住，因为只要有一个没有锁住就会把锁住的解锁释放，一直尝试
- 一次锁定多个互斥量，谨慎使用

### std::lock_guard的std::adopt_lock参数

- 当使用std::lock解决两个互斥量的死锁问题时，后续都需要写上unlock()代码，比较麻烦，故引出这两个参数
- adopt_lock:是个结构体对象，起一个标记作用，作用就是表示这个互斥量已经lock()，不需要在std::lock_guard<std::mutex>构造函数里再对对象进行lock()了；


# 第六节 unique_lock详解

## unique_lock取代lock_guard
- 工作中，一般用lock_guard(推荐使用)
- lock_guard取代了mutex的lock()和unlock()
- unique_lock比lock_guard灵活很多，效率上差一点，内存占用多一点

## unique_lock的第二个参数
- lock_guard可以带第二个参数：std::lock_guard<std::mutex> abguard(my_mutex, std::adopt_lock) //adopt_lock标记使用
- unique_lock也可以带std::adopt_lock标记，含义相同就不需要在unique_lock()构造函数中lock()了

### std::adopt_lock
- std::adopt_lock标记的效果是“假设调用方 线程已经拥有了互斥的所有权”-已经lock()成功了，通知lock_guard不需要在构造函数中lock这个互斥量了

### std::try_to_lock
- 会尝试用mutex的lock()去锁定这个mutex, 但如果没有锁定成功，也会立即返回，并不会阻塞在那里
- 用这个try_to_lock的前提是自己不能先去lock(),不然会重复使用lock()

### std::defer_lock
- 用这个defer_lock的前提是不能自己先lock，否则会包异常
- defer_lock并没有给mutex加锁，初始化了一个没有加锁的mutex

## unique_lock的成员函数

### lock()

### unlock()

### try_lock()
- 尝试给互斥量加锁，如果拿不到锁，则返回false,　如果拿到了锁，则返回true, 这个函数不阻塞的 

### release()
- 返回它所管理的mutex对象指针，并释放所有权，与unique_lock和mutex不再有关系。
- 严格区分unlock()和release()的区别，不要混淆
-　如果原来mutex对象处于加锁状态，你有责任接管过来并负责解锁

```
std::unique_lock<std::mutex> sbguard1(my_mutex1);
std::mutex *ptx = sbguard1.release(); //有责任接管过来并负责解锁
//处理数据
//.....

ptx->unlock();//需要加这个解锁
```

## unique_lock的所有权的传递
### 两种方法
- 1、std::move

```
std::unique_lock<std::mutex> sbguard1(my_mutex1);
sbgurad1拥有ｍy_mutex1的所有权，可以把所有权转移到其他的unique_lock对象
```
- unique_lock对象这个mutex的所有权可以转移，但不可以复制
```
std:;unique_lock<std::mutex> sbguard1(my_mutex1);
std:;unique_lock<std::mutex> sbguard2(sbguard1); //错误
std:;unique_lock<std::mutex> sbguard２(std::move(sbguard1)); //正确，移动语义,相当于sbguard2和my_mutex1绑定到一起了。现在sbguard1指向为空，sbguard2指向my_mutex1

```
- 2、return
```
std::unique_lock<std::mutex> rtn_unique_lock()
{
  std::unique_lock<std::mutex> tmpgurad(my_mutex1);
  return tmpguard;//从函数返回一个局部的unique_lock对象是可以的，
  //因为这种局部对象tmpguard导致系统生成临时unique_lock对象，并调用unique_lock的移动构造函数
}
```

# 第七节 单例设计模式共享数据分析、解决、call_once

## 单例设计模式

##　单例设计模式共享数据分析、解决

- 创建这个单例类的对象，这种线程可能不止一个(最少２个)
- 可能会面临GetInstance()这种成员函数互斥

## call_once()
- std::call_once()，ｃ++11引入的函数，该函数的第二个参数是一个函数名func();
- std::call_once()功能保证func()函数只能调用一次
- std::call_once()具备互斥量这种能力，而且效率上，比互斥量消耗的资源更少；
- std::call_once()需要一个标记结合使用，这个标记std::once_flag(一个结构);
- std::call_once()是通过这个标记来决定对应的函数func()是否执行，调用call_once()成功后，
call_once()就把这个标记设置为一种已调用状态
- 后续再调用call_once()后，因为标记"已调用状态"，那么对应的函数func()就不会再执行了；



# std::future的其他成员函数
# std::shared_future
# 原子操作std::atomic
- 原子操作概念引出范例
- 基本的std::atomic用法范例
- 心得



# 原子操作std::atomic续谈
- 一般atomic原子操作，针对++, --,+=, -=， &=， |=，^=是支持的，其他的可能不支持

# std::async深入谈
## std::async参数详述
- async用来创建 一个异步任务
```
int mythread() {
  cout << std::this_thread::get_id() << endl;

  return 1;
}

int main() {

  cout << std::this_thread::get_id() << endl;
  std::future<int> result = std::async(mythread);
  cout << result.get() << endl;

}
```


- std::async()我们一般不叫创建线程(解释async能够创建线程)， 我们一般叫创建 一个异步任务
  

###
std::launch::deferred
- 延迟调用，并且不创建线程，延迟到future对象调用.get()或者.wait的时候才执行mythread(), 如果没有调用.get()或.wait()，mythread函数不会执行
  ```
  std::future<int> result = std::async(std::launch::deferred, mythread);
  ```
###
std::launch::async
- 强制创建一个线程，强制这个异步任务在新线程上执行，这意味着系统要给我创建出的新线程来运行mythread()


### std::launch::deferred | std::launch::async
- 意味着aysnc的行为可能是"创建新线程并立即执行" 或者没有创建新线程并且延迟到调用result.get()才开始执行入口函数，两者其一
  

### 不带额外参数，只给aysnc函数一个 入口函数名
```
std::aysnc(mythread);
```
- 默认值为std::launch::deferred | std::launch::async
- 系统会自行决定异步(创建线程)还是同步(不创建线程)方式运行



## std::async和std::thread的区别
- std::thread()如果系统资源紧张，那么可能创建线程会失败，那么std::thread()时整个程序可能崩溃
- std::thread创建线程的方式，如果线程返回值，(ˇˍˇ) 想拿到这个值不太容易
- std::async创建异步任务，可能创建也可能不创建线程，并且aysnc调用方法很容易拿到线程入口函数的返回值
- 由于系统资源限制：(1) 如果用std::thread创建的线程太多，则可能创建失败，系统报告异常，崩溃。(2) 如果用std::async，一般不会报异常和崩溃，因为系统资源紧张导致无法创建新线程的时候，std::async这种不加额外参数的调用就不会创建新线程，而是后续谁调用看了result.get()来请求结果，那么这个异步任务mythead就运行在执行这条get()语句所在的线程上。
- 如果你强制std::async一定要创建新线程,那么就必须调用std::launch::async,承受的代价是系统资源紧张是，程序崩溃
- 经验：一个程序里 线程数量不宜超过100~200，时间片
  



## std::async不确定性问题的解决
- 不加额外参数的std::async，让系统自行决定是否创建新线程





## 第十二节 windows临界区、其他这种mutex互斥量
- windows临界区
- 多次进入临界区试验
- 自动析构技术
- recursive_mutex递归的独占互斥量
- 带超时的互斥量std::timed_mutex和std::recursive_timed_mutex
