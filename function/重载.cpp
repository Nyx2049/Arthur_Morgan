#include <iostream>
#include <string>

//一个函数是否相同，关键是名字，和返回类型无关，重载时必须保持参数不一致（数量或者类型，weizhi）
void getName(std::string &name, int &age)
{
    std::cout << "name:" << name <<std::endl; 
}

int getName(int &age)
{
    return age;
}


template<class kernel>

void print(kernel &k)
{
    std::cout << k << std::endl;
}

int main()
{
    int a = 18;
    print(a);
    std::cout << typeid(a) << 
    return 0;
}