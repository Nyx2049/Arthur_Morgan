#include <iostream>

int main()
{
    int a = 8;
    int *ptr = &a;
    std::cout <<  ptr << std::endl;
     std::cout <<  *ptr << std::endl;
    //  std::LOG(*ptr)
    return 0;
}