#include "Array.hpp"

// template <typename T>
// void Array<T>::Insert(const size_t &location, T value) {}
template <typename T>
inline size_t Array<T>::Size() //记录当前数组具体的元素个数 （目前放了多少）
{
  return m_size;
}
template <typename T> void Array<T>::PushBack(const T &value) {
  if (m_size + 1 > m_capacity) {
    m_capacity = m_capacity + ((m_capacity >> 1) > 1 ? (m_capacity >> 1) : 1);
    // m_capacity = m_capacity + (((m_capacity >> 1) + 1)  > 1? ((m_capacity >>
    // 1) + 1) : 1);
    T *ptrMew = new T[sizeof(T) * m_capacity];
    memcpy(ptrMew, m_ptrData, sizeof(T) * m_size);
    delete[] m_ptrData;
    m_ptrData = ptrMew;
  }
  m_ptrData[m_size++] = value;
}
// template <typename T>
// void Array<T>::PushFirst(const T &value) {return;}
template <typename T>
inline size_t Array<T>::Capacity() //记录当前数组申请到的容量空间（可以放多少）
{
  return m_capacity;
}
template <typename T> void Array<T>::Remove(const size_t &location) 
{   
    return; 
}

template <typename T> void Array<T>::FreeSpace() { return; }
template <typename T> size_t Array<T>::Find(const T &vlaue) { return 0; }
template <typename T> void Array<T>::Print() {
  std::cout << "Size: " << m_size << " Capacity: " << m_capacity << " :";
  for (int i = 0; i < m_size; i++) {
    std::cout << m_ptrData[i] << " ";
  }
  std::cout << std::endl;
}
template <typename T> inline T Array<T>::operator[](const size_t &index) {
  return m_ptrData[index];
}
template <typename T>
inline const T Array<T>::operator[](const size_t &index) const {
  return m_ptrData[index];
}

// template <typename T> 
// void Array<T>::operator()() const
// {
//   std::cout << "该数组已被调用" << std::endl;
// }
template <typename T> void Array<T>::Clear() {
  m_size = 0;
  return;
}
template <typename T> void Array<T>::reverse() {
  for (int i = 0; i < m_size / 2; i++) {
    T tSwap = m_ptrData[i];
    m_ptrData[i] = m_ptrData[m_size - 1 - i];
    m_ptrData[m_size - 1 - i] = tSwap;
  }
}
template <typename T> void Array<T>::Insert(const size_t &location, T value) {
  if (m_size + 1 > m_capacity) {
    m_capacity = m_capacity + ((m_capacity >> 1) <= 2 ? 1 : (m_capacity >> 1));
    T *ptrNew = new T[sizeof(T) * m_capacity];
    memcpy(ptrNew, m_ptrData, sizeof(T) * m_size);
    delete[] m_ptrData;
    m_ptrData = ptrNew;
  }
  for (int i = m_size; i > location; --i) {
    m_ptrData[i] = m_ptrData[i - 1];
  }
  m_ptrData[location] = value;
  m_size++;
}



template <typename T>
Array<T>::Array() {
  m_ptrData = nullptr;
  m_capacity = m_size = 0;
  printf("默认无参构造函数的调用完成\n");
}
template <typename T> 
 Array<T>::Array(T* ptrData, const size_t& size, const size_t& capacity)
 {
    m_ptrData = ptrData;
    m_size = size;
    m_capacity = capacity;
    printf("有参构造函数的调用完成\n");
 }
template <typename T> 
Array<T>::Array(const Array<T> &array)
{
  this->m_ptrData = array.m_ptrData;
  this->m_size = array.m_size;
  this->m_capacity = array.m_capacity;
  printf("拷贝构造函数的调用完成\n");
}
template <typename T> Array<T>::~Array() {
  if (m_ptrData) {
    delete[] m_ptrData;
    m_ptrData = nullptr;
  }
  printf("析构函数的调用完成\n");
}
void testArray001() {

  // size_t aa = 3;
  // aa = ceil(aa / 2);
  // int b = 3;
  // b = ceil(b / 2);
  Array<double> a;
  int c = 2;
  for (int i = 0; i < c; i++) {
    a.PushBack(i + 0.314);
  }
  a.Print();
  a.reverse();
  a.Print();
  a.Insert(4, 0.9912938132);
  a.Print();
  // a.Clear();
  // a.Print();
  // a.PushBack(5.3);
  // a.Print();
  // Array<int> e;
  // e.Clear();
  // e.Print();
  // std::vector<int> cc{1,2,3};
  // cc.clear();
  // printf("size: %d\n", int(cc.size()));
  // printf("cpa: %d\n", int(cc.capacity()));
  // printf("cc[2]: %d", cc[2]);
  // printf("-----\n");
  // for (int i = 0; i < 10;)
  // {
  //     printf(" %d ", i++);
  // }
  // printf("              \n");
  // for (int i = 0; i < 10;)
  // {
  //     printf(" %d ", ++i);
  // }
  return;
}
