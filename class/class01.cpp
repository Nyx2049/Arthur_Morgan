//�������Ϊ���Ա

//̽��һ�£�������class B�д���һ��class A������ʵ����Bʱ�����ȴ���A�������ȴ���B������ʱ�䣬��������A����������B

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
    a.setName("����˼��");
    a.setAge(19);
    lover lt;
    lt.set(a);
    std::cout << lt.get().printname() << std::endl;
    std::cout << a.printname() << std::endl;
    system("pause");
    return 0;
    

}