//函数重载，可以让函数名相同，提高复用性�?
// 函数重载满足条件
// 1、同一个作用域�? 2、函数名称相�? 3�? 函数的参数类型不同或者个数不同或者顺序不�?

#include <iostream>
using namespace std;
void func()
{
    cout << "func()��������" << endl;
}

// void func(int a = 10)
// {
//     cout << "func(int a = 10)��������" << endl;
// }
void func(int a)
{
    cout << "func(int a��������" << endl;
}
void func(int a, double b)
{
    cout << "func(int a, double b)��������" << endl;
}
void func(double a, double b)
{
    cout << "func(double a, double b)��������" << endl;
}


int main()
{   
    func(10.1, 3);
    system("pause");
    return 0;

}