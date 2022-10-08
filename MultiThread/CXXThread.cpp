#include "CXXThread.hpp"
/*
1、一个合格的程序，应该保证主线程结束之前，所有的子线程也已经完成。
*/
/***************************************thread**join*****************************************/
void ThreadStudy01() {
  //整个进程执行完毕的标志是主线程是否执行完，如果主线程完毕了，就代表你整个进程执行完毕。
  //一般情况下：如果主线程结束了，子线程还在运行，那么这些子线程也会被操作系统强行终止。
  //所以，一般情况洗哦啊如果大家想保持子线程的运行状态的话，就要让主线程一直保持运行，不要让主线程运行完毕。
  //这种情况有例外，后续再了解。
  std::cout << "i love china!" << std::endl;
  std::thread myobj1(
      threadFunc01,
      10); //创建了一个线程，同时该线程开始执行，记住，此时已经执行了。
  myobj1
      .join(); //阻塞主线程，让主线程等待子线程threadFunc01函数执行完毕，然后主线程和子线程汇合。
  // std::thread myobj2(threadFunc02);
  // myobj2.join();
  printf("I love Japan!\n");
  return;
}
/***************************************detach  joinable***********************************/

// detach & joinable
void ThreadStudy02() {
  printf("主线程开始\n");
  std::thread thr1(threadFunc01, 6879);
  thr1.detach(); //一旦使用了detach（），你就失去了对该线程的掌控，无法再使用join，用了后，系统会直接异常。实际工作中最后使用join
                 //主线程结束后，子线程就与这个主线程失去了关联，就驻留在后台运行，这个子线程相当于被系统接管了。当子线程执行完毕后，由运行时库负责来清理该子线程相关资源，称为（守护线程），脱缰的野马。
  if (thr1.joinable())
  {
    thr1.join();
  }
  for(int i = 0; i < 1000; i++)
  {
    printf("主线程运行中\n");
  }
  printf("主线程结束\n");
  return;
}
//joinable: 判断能否使用join或是detach，返回bool值，如果该线程未使用过join或是detach，就可以是true，反之则为false；

//用其他的方法实现多线程，比如可调用的对象。
void ClassThreadStudy()
{   
    printf("主线程开始\n");
    for(int i = 0; i < 1000; i++)
    {
        printf("主线程运行中\n");
    }
    Array<double> Az;
    std::thread thr2(Az); //此处这个Az是被复制到了这个子线程中，所以使用detach也不会有问题，但是引用和指针不行
    thr2.join();
    printf("主线程结束\n");
    return;
}

void threadFunc01(const int &b) {
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

void threadFunc02() {
  printf("Func02正在运行!\n");
  // while(1);
  printf("Func02运行完毕!\n");
  return;
}


