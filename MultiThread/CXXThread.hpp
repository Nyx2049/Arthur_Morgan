#ifndef CXXTREAD_HPP
#define CXXTREAD_HPP

#include "../DataStructure/Array.hpp"
#include "../head.hpp"
#include "ThreadTest.hpp"
#include <mutex>

// thread、join、 detach
void ThreadStudy01();
void ThreadStudy02();

//引用和指针的风险
void ThreadWithParas01();
void ThreadWithParas02();

//创建多个线程
void CreateMultiThread();
//  数据共享问题
// 1、只读数据十分的安全
// 2、有读有写就很危险
void ThreadsDataShare();

void ThreadsDataShareClass();  //该程序会导致崩溃，因为没有加🔒
// mutex
void ThreadsDataShareClassSolve();

void ThreadsDataShareClassDead();
extern std::list<int> listInt;
extern std::vector<int> vecInt;
//基础线程函数
void threadFunc01(const int &b);
void threadFunc02();
void threadFunc03(const int &i, char *b);
void threadFunc04(const int &i, const std::string &b);
void threadFunc05(const int &i);
void threadFunc06(const int &i);
//用成员函数作为线程对象、
class ThreadObj
{
  public:
    void inMsgRecvQueue();
    void getMsgRecvQueue(const int &a);
    // ThreadObj()
    // {
    //     std::list<int> msgRec
    // }
  private:
    std::list<int> msgRecvQueue; //专门用于代表玩家给我我们发送来的命令
};
class ThreadObjWithMutex
{   
  public:
    void inMsgRecvQueue();
    void inMsgRecvQueueDead();
    void getMsgRecvQueue(const int &a);
    bool outMsgRecvQueue(int &index);
    bool outMsgRecvQueueLockGuard(int &index);//引入std::lock_guard() 可以直接取代lock() unlock()
     bool outMsgRecvQueueDead(int &index);
    // ThreadObj()
    // {
    //     std::list<int> msgRec
    // }
    std::unique_lock<std::mutex> return_uniqueLock()
    {
        std::unique_lock<std::mutex> tempGuard(myMutex);
        return tempGuard;
    }
  private:
    std::list<int> msgRecvQueue; //专门用于代表玩家给我我们发送来的命令
    std::mutex myMutex; //c创建了一个互斥量
    std::mutex myMutexDead; //用于死锁演示  //只要上锁的顺序一致就不会发生死锁
};

//死锁演示
//std::lock() :如果互斥量中有一个没锁住，他就在那里等着，等所有互斥量都锁住，它才能往下走
//std::lock_guard<std::mutex> gaurd 的adopt_lock()参数，表示这个互斥量已经lock（）过了，在代码和中不需要再次lock了，只需要在析构函数unlock即可。


//用unique_lock取代lock_guard
//是个类模版，和lock_guard差不多，工作中，推荐使用lock_guard，有特殊需求就用unique_lock,unique_lock使用起来很灵活，代价就是效率低一点，内存占用多一点。
#endif
