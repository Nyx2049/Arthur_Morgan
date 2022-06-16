#include <iostream>
#include <vector>
#include <string> 
using namespace std;

class Lover
{
public:
    Lover();
    Lover(const string& name, const string&age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    void show()
    {
        cout << "name:" << this->m_Name << endl;
        cout << "age:" << this->m_Age << endl;
    }
    string m_Name;
    string m_Age;
};

void test01()
{
    Lover lt("刘唐", "18");
    Lover lt2("刘唐", "19");
    vector<Lover> list;
    list.emplace_back(lt);
    list.emplace_back(lt2);
    for (vector<Lover>::iterator &&it = list.begin(); it != list.end(); it++)
    {
        cout << it->m_Age << endl;
        cout << (*it).m_Age << endl;
    }
}

void test02()
{
    Lover lt("刘唐", "18");
    Lover lt2("刘唐", "19");
    vector<Lover *> list;
    list.emplace_back(&lt);
    list.emplace_back(&lt2);
    for (vector<Lover *>::iterator &&it = list.begin(); it != list.end(); it++)
    {
        cout << (*it)->m_Age << endl;
        // cout << (**it).m_Age << endl;
    }
}

int main()
{   
    test02();
    system("pause");
    return 0;
}