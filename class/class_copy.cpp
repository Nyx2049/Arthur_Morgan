//拷贝构造的调用时机
//1、使用一个已经创建完毕的对象来初始化一个新对象
//2、值穿递的方式
//3、以值方式方式返回局部对象
#include <iostream>

class lover
{
public:
    lover()
    {   
        std::cout << "building is working " << std::endl;
    }
    lover(int _age)
    {
        age = _age;
        std::cout << "building is working with arg" << std::endl;
    }
    // lover(const lover &p)
    // {
    //     age = p.age;
    // }
  
    ~lover()
    {
        std::cout << "destructing is working " << std::endl;
    }
    int age;
};

lover test(lover ppp)
{
    std::cout << (int*)&ppp << std::endl;
    return ppp;
}

int main()
{
    lover lt;
    lover lt1(19);
    lover lt2(lt);
    std::cout << lt.age << std::endl;
    // lover lt2(lt);
    // lover lt1 = test(lt);
    std::cout << lt2.age << std::endl;
    system("pause");
    return 0;
}