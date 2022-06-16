#include <iostream>

template<class Ta>

Ta &func(Ta &a, Ta &b)
{
    return b;
}

int main()
{
    int x = 7;
    int y = 3;
    std::cout << func(y, x) << std::endl;
}
