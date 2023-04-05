#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string.h>
#include <cmath>
#include <sys/_types/_size_t.h>
#include <vector>
#include <thread>

template <typename T>

class Array
{
private:
    
    T* m_ptrData; // 当前存放数据的地址
    size_t m_size; //当前存放的元素
    size_t m_capacity; //当前申请的数组的容量 
public:
    void Insert(const size_t &location, T value);
    inline size_t Size(); //记录当前数组具体的元素个数 （目前放了多少）
    void PushBack(const T& value);
    // void PushFirst(const T& value);
    void reverse();
    inline size_t Capacity(); //记录当前数组申请到的容量空间（可以放多少）
    void Remove(const size_t& location);
    void Remove(const T& value);
    void FreeSpace();
    size_t Find(const T& vlaue);
    void Print();
    void Clear();
    size_t findValue(const T& value);
    inline T operator[](const size_t& index);
    inline const T operator[](const size_t& index) const;
    void operator()() const;
    Array();
    Array(size_t& capacity);
    Array(const Array &array);
    ~Array();
};
void testArray001();
//用可调用对象的方法
void ClassThreadStudy();

#endif