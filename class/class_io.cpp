#include <iostream>

class Person
{
public:
    Person()
    {
        std::cout << "���캯���ĵ���" << std::endl;
    }

    ~Person()
    {
        std::cout << "���������ĵ���" << std::endl;
    }
};

int main()
{
    Person p;
    system("pause");
    return 0;
}