//类对象作为类成员

//探讨一下，当我在class B中创建一个class A，在我实例化B时，是先创造A，还是先创造B，析构时间，是先析构A，还是析构B

#include <iostream>

class Person
{
public:
    Person()
    {
        std::cout << "build is working!" << std::endl;
    }
    ~Person()
    {
        std::cout << "destruct is working!" << std::endl;
    }

    void setAge(const int &_age)
    {
        age = _age;
    }
     void setName(const std::string &_name)
    {
        name = _name;
    }
    std::string printname()
    {
        return name;
    }
private:
    int age;
    std::string name;
};

class lover
{
public:
    lover()
    {
        std::cout << "lover's build is worked!" << std::endl;
    }
    ~lover()
    {
        std::cout << "lover's destruct is worked!" << std::endl;
    }
    void set(Person &love)
    {
        LT = love;
    } 
    Person get()
    {
        return LT;
    }
private:
    Person LT;
    int time;
};


int main()
{
    Person a;
    a.setName("刘唐思语");
    a.setAge(19);
    lover lt;
    lt.set(a);
    std::cout << lt.get().printname() << std::endl;
    std::cout << a.printname() << std::endl;
    system("pause");
    return 0;
    

}