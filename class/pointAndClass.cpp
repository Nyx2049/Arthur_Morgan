#include <iostream>

class Person
{
public:
    int age;
    static int b; 
    // int name2;
    std::string name;
};

int Person::b = 100;

void test()
{
    Person p;
    int a;
    std::string name;
    std::cout << "sizeof(name):" << sizeof(name) << std::endl;
    std::cout << "sizeof(a):" << sizeof(a) << std::endl;
    std::cout << "sizeof(p):" << sizeof(p) << std::endl;
    std::cout << "sizeof(static):" << sizeof(Person::b) << std::endl;
}

int main()
{
    test();
    system("pause");
    return 0;
}