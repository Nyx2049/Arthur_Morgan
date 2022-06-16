#include <iostream>
#include <string>
#include <time.h>

using namespace std;

void test01()
{
    // char *a = "LTS";
    const char *b = "LTSY with LJM";
    // string a_(a);
    string b_(b);
    // string c_(a_);
    string c(10, 's');
    // a_ += "Y";
    b_ += "LOVE";
    // cout << "a_:" << a_ ;
    // cout << endl;
    // cout << "a:" << a;
    cout << endl;
    cout << "b_:" << b_ ;
    cout << endl;
    cout << "b:" << b;
    cout << endl;
    // cout << "c_:" << c_;
    cout << endl;
    cout << "c:" << c;
}


int main()
{
    test01();
    cout << endl;
    system("pause");
    return 0;
}