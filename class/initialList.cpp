//初始化列表

#include <iostream>
#include <string>
using namespace std;

class lover
{
public:
    lover(int _age, string _name):age(_age), name(_name){};
    int age;
    string name;
};

int main()
{
    lover lt(19, "ltsy");
    cout << lt.name << endl;
    return 0;
}