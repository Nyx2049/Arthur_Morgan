#include <iostream>
#include <string>
//base
int func1(int *a , int b, int c=100)
{
    return *a + b + c;
}

//ռλ����
//Ŀǰ���ò�����������

void func2(int a, std::string)
{
    std::cout << a << std::endl;
}


int main()
{   
    int *_a;
    int c = 10;
    _a = &c;
    func2(100, "����");
    // std::cout << func1(_a, 10) << std::endl;
    system("pause");
    return 0;
}
