#include <iostream>
#include <string>

template<typename T>

void print(T a)
{
    std::cout << a << std::endl;   
}

int main()
{
    std::string a = "lt";
    print(a);
}