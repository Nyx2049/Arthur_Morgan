#include <iostream>

using namespace std;
//1、解决名称冲突
//2、返回对象本身

class lover
{
public:
    lover(int age)
    {
        this->age = age;
    }
    lover& loverAddAge(const lover &p)
    {
        this->age += p.age;
        return *this;
    }
    int age;
};
//1、解决名称冲突
void test01()
{
    lover lt(18);
    cout << lt.age << endl;
}
//2、返回对象本身
void test02()
{
    lover lt1(19);
    lover lt2(19);
    cout << &lt1.loverAddAge(lt2) << endl;
    cout << &lt1.loverAddAge(lt2).loverAddAge(lt2) << endl;
    lt1.loverAddAge(lt2).loverAddAge(lt2).loverAddAge(lt2).loverAddAge(lt2);
    cout << lt1.age << endl;
}
// int num = 10;
// int _add(const int &a)
// {
//     num += a;
//     return num;
// }
// void test03()
// {
//     cout<<  _add(_add(_add(10))) << endl;
// }
int main()
{
    // test01();
    test02();
    // test03();
    system("pause");
    return 0;
}