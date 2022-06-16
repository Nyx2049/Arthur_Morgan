#include <iostream>

class Person
{
public:
    Person()
    {
        std::cout << "构造函数的调用" << std::endl;
    }

    ~Person()
    {
        std::cout << "析构函数的调用" << std::endl;
    }
};

int main()
{
    Person p;
    system("pause");
    return 0;
}