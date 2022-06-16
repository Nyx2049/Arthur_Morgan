#include <iostream>

// template<typename P>
// template<typename Pb>

// void print(const P &p)
// {
//     std::cout << p << std::endl;
// }
Pb a;
int& func01()
{   
    a = 100;
    return a;
}

int main()
{
    int &b = func01();
   std::cout << b << std::endl;
}