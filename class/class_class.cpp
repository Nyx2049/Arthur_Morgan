//构造函数的分类
//两种分类方式
//1、按参数分为：有参构造和无参构造
//2、按类型分类：普通构造和拷贝构造
//三中调用方式
//1、括号法
//2、显示fa
//3、隐式转换法
#include <iostream>
#include <string>
using namespace std;

class lover
{
public:
    lover()
    {   
        cout << "building is working" << endl;
    }
    lover(const int &a, const string &b)
    // lover(const int &a)
    {   
        age = a;
        // name = b;
        cout << "building is working with arg" << endl;
    }
    lover(const lover &c)
    {   
        age = c.age;
        name = c.name;
        cout << "copy building is working with arg" << endl;
    }
    ~lover()
    {   
        cout << "destruct is working" << endl;
    }

    string getname()
    {
        return name;
    }
private:
    int age;
    string name;
};

int main()
{   
    // lover lt0;
    lover lt1(17, "刘唐");
    // lover lt2(lt1);
    // lover (19, "liutang");
    // lover lt = (19, "liutang");
    cout << "aaaa" << endl;
    // cout <<" lt0.getname()："<< lt0.getname() << endl;
    // cout <<" lt1.getname()："<< lt1.getname() << endl;
    // cout << "lt2.getname():"<< lt2.getname() << endl;
    system("pause");
    return 0;
}