#ifndef _SINGLEOBJ_HPP_
#define _SINGLEOBJ_HPP_
// #include "../DataStructure/Array.hpp"
#include "../head.hpp"
#include <iosfwd>
#include <mutex>

//单例详解
std::mutex mytex;
class MySingle
{
  private:
    MySingle() {}  //私有化构造函数

  private:
    static MySingle *m_instance;

  public:
    static MySingle *getInstance()
    {   
        
        if (!m_instance)  //双重锁定，可以加快程序速度，只在第一次调用时加锁。
        {
            std::lock_guard<std::mutex> mtx(mytex);
            if (!m_instance)
            {
                m_instance = new MySingle;
                // static
                static DeleteMysingle d1;
            }
        }

        return m_instance;
    }
    class DeleteMysingle  // 类中套类，用来释放对象
    {
      public:
        ~DeleteMysingle()
        {
            if (MySingle::m_instance)
            {
                delete MySingle::m_instance;
                MySingle::m_instance = nullptr;
            }
        }
    };
    void funcTest() { printf("TEST\n"); }
};
//二、call_once() ,c++11 的函数，能保证在多线程情况下，能保证这个传入的函数只被调用一次。具备互斥量的能力，同时效率比互斥量更高
//需要与一个标记一起使用std::once_flag()

void buildSingle();

#endif