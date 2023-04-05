#ifndef CLASSSTUDY_H
#define CLASSSTUDY_H

#include <iostream>
#include <string>
class Test
{
  private:
    int m_age;
    std::string m_name;

  public:
    static void swap(int &a, int &b)
    {
        int c = a;
        a     = b;
        b     = c;
    }
};
void testClassSwap()
{
    int a, b;
    a = 10, b = 100;
    printf("a:%d, b:%d", a, b);
    Test::swap(a, b);
    printf("a:%d, b:%d", a, b);
}
#endif