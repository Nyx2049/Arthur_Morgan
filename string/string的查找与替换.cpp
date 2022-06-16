#include <iostream>
#include <string>
#include <time.h>


using namespace std;

//查找
void test0()
{   
    //find 正着找
    string a = "3.141592681723981723981123981982391831";
    int pos1 = a.find(".");
    cout << a[pos1] << endl;
}

void test1()
{
       //rfind 到着找
    string b = "3.141592681723981723981123981982391831";
    int pos2 = b.rfind(".");
    cout << b[pos2] << endl;
}

//替换
void test2()
{
    string c = "3.141592681723981723981123981982391831";
    c.replace(1, 3, "aaaa");
    // c[0] = "lsty";
    cout << c << endl;
}


int main()
{   
    clock_t start, finish;
    start = clock();
    test2();
    finish = clock();
    cout << double(finish - start)/CLOCKS_PER_SEC << endl;
    system("pause");
    return 0;
}