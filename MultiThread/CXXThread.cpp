#include "CXXThread.hpp"
#include <chrono>
#include <cstdio>
#include <mutex>
#include <thread>
/*
1、一个合格的程序，应该保证主线程结束之前，所有的子线程也已经完成。
*/
/***************************************thread**join*****************************************/
void ThreadStudy01()
{
    //整个进程执行完毕的标志是主线程是否执行完，如果主线程完毕了，就代表你整个进程执行完毕。
    //一般情况下：如果主线程结束了，子线程还在运行，那么这些子线程也会被操作系统强行终止。
    //所以，一般情况洗哦啊如果大家想保持子线程的运行状态的话，就要让主线程一直保持运行，不要让主线程运行完毕。
    //这种情况有例外，后续再了解。
    std::cout << "i love china!" << std::endl;
    std::thread myobj1(threadFunc01,
                       10);  //创建了一个线程，同时该线程开始执行，记住，此时已经执行了。
    myobj1.join();           //阻塞主线程，让主线程等待子线程threadFunc01函数执行完毕，然后主线程和子线程汇合。
    // std::thread myobj2(threadFunc02);
    // myobj2.join();
    printf("I love Japan!\n");
    return;
}
/***************************************detach
 * joinable***********************************/

// detach & joinable
void ThreadStudy02()
{
    printf("主线程开始\n");
    std::thread thr1(threadFunc01, 6879);
    thr1.detach();  //一旦使用了detach（），你就失去了对该线程的掌控，无法再使用join，用了后，系统会直接异常。实际工作中最后使用join
                    //主线程结束后，子线程就与这个主线程失去了关联，就驻留在后台运行，这个子线程相当于被系统接管了。当子线程执行完毕后，由运行时库负责来清理该子线程相关资源，称为（守护线程），脱缰的野马。
    if (thr1.joinable())
    {
        thr1.join();
    }
    for (int i = 0; i < 10; i++)
    {
        printf("主线程运行中\n");
    }
    printf("主线程结束\n");
    return;
}
// joinable:
// 判断能否使用join或是detach，返回bool值，如果该线程未使用过join或是detach，就可以是true，反之则为false；

// 1.传递临时对象作为线程参数

// 1.1 要避免的陷阱
void ThreadWithParas01()
{
    printf(" now is Main thread!\n");
    int mvar     = 1;
    int &mvarr   = mvar;
    char mybuf[] = "this is a test!";
    std::thread myobj(threadFunc03, mvarr, mybuf);
    // myobj.join();
    myobj.detach();  //使用了detach了之后，绝对不能用指针，可以用引用（但是依然存在一定的风险）。
    printf("Main thread is over!\n");
    return;
}
// 1.2 要避免的陷阱2
void ThreadWithParas02()
{
    printf(" now is Main thread!\n");
    int mvar     = 1;
    int &mvarr   = mvar;
    char mybuf[] = "this is a test!";
    // std::thread myobj(threadFunc04, mvarr, mybuf);
    // //这个写法不如下面的写法，因为可能在拷贝转换之前，主线程就结束了
    std::thread myobj(threadFunc04, mvarr, std::string(mybuf));  //
    // myobj.join();
    myobj.detach();  //虽然使用string进行了转换，但是到底是什么时候转换的不知道
    for (int i = 0; i < 100; i++)
    {
        printf("thread is working!\n");
        sleep(10);
    }

    printf("Main thread is over!\n");
    return;
}

// 4、创建多个线程，数据共享问题分析
// * 创建多个线程
// * 数据共享问题分析
//      A、只读的数据
//      B、有读有写
//      C、其他案例
void CreateMultiThread()
{
    // 1 、create many threads
    std::list<std::thread> threads;
    //入口函数全为threadFunc05
    for (int i = 0; i < 5;)
    {
        threads.push_back(std::thread(threadFunc05, i++));  // create & run
    }
    //多个线程的执行顺序是乱的，和操作系统的调度有关。
    for (auto iter = threads.begin(); iter != threads.end(); iter++)
    {
        iter->detach();  //等待10个线程都返回
    }
    printf("main is ending!\n");
    return;
}
//数据共享问题分析
std::list<int> listInt  = {1, 2, 3, 4, 5, 6};
std::vector<int> vecInt = {1, 2, 3, 4, 5, 6};
void ThreadsDataShare()
{
    std::list<std::thread> threads;
    int i = 0;
    // printf("%d\n", *(vecInt.end()++));
    while (i < 1000)
    {
        threads.push_back(std::thread(threadFunc06, ++i));
    }
    for (auto iter = threads.begin(); iter != threads.end(); iter++)
    {
        iter->join();  //等待10个线程都返回
    }
    printf("main is ending!\n");
    return;
}
//使用成员函数来创建线程
void ThreadsDataShareClass()
{
    ThreadObj obj;
    std::thread getInMsgObj(&ThreadObj::getMsgRecvQueue, &obj, 6879);
    std::thread myInMsgObj(&ThreadObj::inMsgRecvQueue, &obj);  //第二个参数是引用，才能保证线程里用的同一个对象
    getInMsgObj.join();
    myInMsgObj.join();
    return;
}
void ThreadsDataShareClassDead()
{
     ThreadObjWithMutex obj;
    std::thread getInMsgObj(&ThreadObjWithMutex::getMsgRecvQueue, &obj, 6879);
    std::thread myInMsgObj(&ThreadObjWithMutex::inMsgRecvQueueDead, &obj);  //第二个参数是引用，才能保证线程里用的同一个对象
    getInMsgObj.join();
    myInMsgObj.join();
    return;
}

//保护共享数据，操作时，用代码把共享数据锁住，其他想操作共享线程的线程必须等待；
//一、 互斥量(mutex)的基本概念
// mutex就是一个类对象， 理解为一把锁， 多个线程尝试用lock（）成员函数来加锁这把锁头，只有一个线程能锁定成功（成功的标志）
// 如果没有锁定成功，那么流程就会卡在这里，不断的尝试锁住；
// 解锁unlock()
// lock这个行为只保护需要保护的数据，保护的多了 就会让程序非常慢。
// 二、互斥量（mutex）的用法代码如下
// lock(), unlock() 必须成对使用，不然就完了。
void ThreadsDataShareClassSolve()
{
    ThreadObjWithMutex obj;
    std::thread getMsgObj(&ThreadObjWithMutex::getMsgRecvQueue, &obj, 6879);
    std::thread InMsgObj(&ThreadObjWithMutex::inMsgRecvQueue, &obj);  //第二个参数是引用，才能保证线程里用的同一个对象
    getMsgObj.join();
    InMsgObj.join();
    return;
}

void threadFunc01(const int &b)
{
    printf("目前是线程%d在运行\n", b);
    printf("Func01正在运行11111111!\n");
    printf("Func01正在运行222!\n");
    printf("Func01正在运行333!\n");
    printf("Func01正在运行444!\n");
    printf("Func01正在运行555!\n");
    printf("Func01正在运行666!\n");
    printf("Func01正在运行777!\n");
    printf("Func01正在运行888!\n");
    printf("Func01运行完毕!\n");
    return;
}
void threadFunc02()
{
    printf("Func02正在运行!\n");
    // while(1);
    printf("Func02运行完毕!\n");
    return;
}
void threadFunc03(const int &i, char *b)
{
    printf("now is threadFunction03 ! \n");
    printf("i: %d\n", i);
    printf("b: %s\n", b);
    return;
}

void threadFunc04(const int &i, const std::string &b)
{
    printf("now is threadFunction03 ! \n");
    printf("i: %d\n", i);
    printf("b: %s\n", b.c_str());
    return;
}

void threadFunc05(const int &i)
{
    printf("Thread %d is starting!\n", i);
    printf("Thread %d is working!\n", i);
    printf("Thread %d is ending!\n", i);
    return;
}

void threadFunc06(const int &i)
{
    // std::cout << "threadId"<< "0" << i << ": " << std::this_thread::get_id()
    // <<"printListInt" << *listInt.begin() << "..." << *listInt.end()
    // <<std::endl;
    std::cout << "threadId"
              << "0" << i << ": " << std::this_thread::get_id() << " *vecInt[4]: " << vecInt[4] << std::endl;
    vecInt.push_back(10);
}

void ThreadObj::inMsgRecvQueue()
{
    for (int i = 0; i < 100; ++i)
    {
        printf("inMsgRecvQueue() running!, insert a obj%d\n", i);
        msgRecvQueue.push_back(i);  //假设这个数字就是玩家的命令
    }
    printf("inMsgRecvQueue() is ending!\n");
}
void ThreadObj::getMsgRecvQueue(const int &a)
{
    for (int i = 0; i < 100; ++i)
    {
        if (!msgRecvQueue.empty())
        {
            //不为空
            int coomand = msgRecvQueue.front();  //先进先出，让玩家不等待。并且不检查元素是否存在
            msgRecvQueue.pop_front();            //移除已经取出的元素，但不返回
            //考虑处理数据...
            //...
            printf("order: %d is deal\n", coomand);
        }
        else
        {
            printf("getMsgRecvQueue running succed, but msgRecvQueue is empty! %d\n", i);
        }
    }
    printf("%dgetMsgRecvQueue() is ending\n", a);
}

void ThreadObjWithMutex::inMsgRecvQueue()
{
    for (int i = 0; i < 500000; ++i)
    {
        {  // z加一个大括号让lock_guard只在这个当前的作用域下运行
            // std::unique_lock<std::mutex> sbguard(myMutex, std::try_to_lock);  
            //unique_lock可以带很多种第二参数， 
            //1、adopt_lock：用来标记这个互斥量已经lock了， 即上文已经有lock操作
            //2、std::try_to_lock():我们会尝试用mutex的lock去锁定这个mutex，但是如果没有锁定成功，我也会立即返回，并不会阻塞。
             // std::unique_lock<std::mutex> sbguard(myMutex, std::try_to_lock);  //创建一个没有加锁的mutex
             // if (sbguard.owns_lock())
            // {
            //      printf("inMsgRecvQueue() running!, insert a obj'%d'\n", i);
            //       msgRecvQueue.push_back(i);  //假设这个数字就是玩家的命令
            // }
            // else 
            // {
            //     //没拿到锁，就打印点东西
            //     printf("inMsgRecvQueue is running, but dont get mutex,只能干点别的事\n");
            // }
            //用try_to_lock的前提是你不能自己先去lock，意思是这两个不能共存， lock和try_to_lock
            //3、defer_lock：前提依然是不能先自己lock
            //初始化一个不加锁的mutex。
            //存在的一些成员函数 
            //3.1、lock
            //3.2 unlock
           // std::unique_lock<std::mutex> sbguard(myMutex, std::defer_lock);  //创建一个没有加锁的mutex
            // sbguard.lock();//用这个不需要解锁unlock，因为用的是智能的unique_lock
            // sbguard.unlock();  //实际开发中，你锁住的数据段越少，代码的效率越高。，有人把锁住的代码多少用粒度来表示，锁住的代码多，贼粒度粗，锁住的代码少，粒度细。
            //要选择合适的粒度保护代码。
            //这里有一些不想处理共享的数据
            //  sbguard.lock();

            //3.3 try_lock
            // if (sbguard.try_lock())
            // {
            //     printf("inMsgRecvQueue() running!, insert a obj'%d'\n", i);
            //       msgRecvQueue.push_back(i);  //假设这个数字就是玩家的命令
            // }
            // else{
            //       //没拿到锁，就打印点东西
            //     printf("inMsgRecvQueue is running, but dont get mutex,只能干点别的事\n");
            // }

            //3.4 release
            //返回它所管理的mutex对象的指针，并释放所有权；也就是说这个unique_lock和mutex没有关系的，和unlock严格区分
            //如果原来的mutex处于加锁状态，此处需要自己unlock
            // std::unique_lock<std::mutex> sbguard(myMutex);
            //  printf("inMsgRecvQueue() running!, insert a obj'%d'\n", i);
            // msgRecvQueue.push_back(i);  //假设这个数字就是玩家的命令
            // std::mutex *ptx = sbguard.release();
           
            // ptx->unlock();
            //4、unique_lock所有权的传递.
             //std::unique_lock<std::mutex> sbguard(myMutex);  //sbguard拥有myMutex的所有权，它可以转移给其他的unique_lock,可以转移，但是不能复制。
             //1、方法一
             //std::unique_lock<std::mutex> sbguard2(std::move(sbguard));  //用move函数转移所有权。此时sbguard指向空了。
             //2、方法二， 使用成员函数
              std::unique_lock<std::mutex> sbguard2 = return_uniqueLock();

        }
        //假设这里还有其他代码
        //...
    }
    printf("inMsgRecvQueue() is ending!\n");
}
void ThreadObjWithMutex::getMsgRecvQueue(const int &a)
{
    int command = 0;
    for (int i = 0; i < 500000; ++i)
    {
        // if (outMsgRecvQueueDead(command))
        if (outMsgRecvQueueLockGuard(command))
        {
            printf("order: %d is deal\n", command);
        }
        else
        {
            printf("getMsgRecvQueue running succed, but msgRecvQueue is empty! %d\n", i);
        }
    }
    printf("%dgetMsgRecvQueue() is ending\n", a);
    return;
}

bool ThreadObjWithMutex::outMsgRecvQueue(int &index)
{
    myMutex.lock();
    if (!msgRecvQueue.empty())
    {
        //不为空
        index = msgRecvQueue.front();  //先进先出，让玩家不等待。并且不检查元素是否存在
        msgRecvQueue.pop_front();      //移除已经取出的元素，但不返回
        //考虑处理数据...
        //...
        myMutex.unlock();
        return true;
    }
    myMutex.unlock();
    return false;
}

bool ThreadObjWithMutex::outMsgRecvQueueLockGuard(int &index)
{
    // lock_guard里执行了一个构造函数，构造函数里有lock操作，析构函数里有unlock操作。
    // std::lock_guard<std::mutex> sbguard(myMutex);  // 把myMutex搞成一个参数传进去
    std::unique_lock<std::mutex> sbguard(myMutex);  // 用unique_lock取代lock_guard
    // std::chrono::milliseconds dura(200); //20000ms
    // std::this_thread::sleep_for(dura);
    if (!msgRecvQueue.empty())
    {
        //不为空
        index = msgRecvQueue.front();  //先进先出，让玩家不等待。并且不检查元素是否存在
        msgRecvQueue.pop_front();      //移除已经取出的元素，但不返回
        //考虑处理数据...
        //...
        return true;
    }
    return false;
}

void ThreadObjWithMutex::inMsgRecvQueueDead()
{
    for (int i = 0; i < 500000; ++i)
    {

        myMutex.lock();
        /**********/         //此处有代码
        myMutexDead.lock();  //实际工程中，这两个锁头不一定挨着，可能需要保护不同的数据共享块
        printf("inMsgRecvQueue() running!, insert a obj'%d'\n", i);
        msgRecvQueue.push_back(i);  //假设这个数字就是玩家的命令
        myMutex.unlock();
        myMutexDead.unlock();

        //假设这里还有其他代码
        //...
    }
    printf("inMsgRecvQueue() is ending!\n");
}
  bool ThreadObjWithMutex::outMsgRecvQueueDead(int &index)
  {
    //  myMutex.lock();
    // myMutexDead.lock();

    //上锁的顺序不一致导致死锁
    // myMutexDead.lock();
    //  myMutex.lock();
    //用std::lock()解决上锁顺序不一致的问题。（用来处理多个互斥量，解决死锁问题，防止上锁顺序不一致）
    std::lock(myMutex, myMutexDead); //可以接受多个参数

    std::lock_guard<std::mutex> lock01(myMutex, std::adopt_lock); //加了这两行，可以不用unlock
     std::lock_guard<std::mutex> lock02(myMutexDead, std::adopt_lock);

    if (!msgRecvQueue.empty())
    {
        //不为空
        index = msgRecvQueue.front();  //先进先出，让玩家不等待。并且不检查元素是否存在
        msgRecvQueue.pop_front();      //移除已经取出的元素，但不返回
        //考虑处理数据...
        //...
        //  myMutexDead.unlock();
        //   myMutex.unlock();
        return true;
    }
    // myMutexDead.unlock();
    // myMutex.unlock();
    return false;
  }