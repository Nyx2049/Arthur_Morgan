//���캯���ķ���
//���ַ��෽ʽ
//1����������Ϊ���вι�����޲ι���
//2�������ͷ��ࣺ��ͨ����Ϳ�������
//���е��÷�ʽ
//1�����ŷ�
//2����ʾfa
//3����ʽת����
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
    lover lt1(17, "����");
    // lover lt2(lt1);
    // lover (19, "liutang");
    // lover lt = (19, "liutang");
    cout << "aaaa" << endl;
    // cout <<" lt0.getname()��"<< lt0.getname() << endl;
    // cout <<" lt1.getname()��"<< lt1.getname() << endl;
    // cout << "lt2.getname():"<< lt2.getname() << endl;
    system("pause");
    return 0;
}