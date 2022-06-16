#include <iostream>

//静态成员变量
//1、所有对象共享一份数据
//2、在编译阶段分配内存
//3、类内申明，类外初始化。
class lover 
{
public:
   static int a;  
private:
    static std::string name;
};
int lover::a = 100;
std::string lover::name = "ltsy";

//静态成员函数
//1、所有对象共享一个函数
//2、静态成员函数只能访问静态成员变量

int main()
{
    lover p;
    std::cout << p.a << std::endl;
    p.a = 200;
    // std::cout << p.name << std::endl;
    lover p2;
    p2.a = 300;
    std::cout << p.a << std::endl;
    system("pause");
    return 0;
}