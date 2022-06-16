#include <iostream>

class lover
{   
    // friend void test1(const int &a, const int &b);
private:
    int age = 10;

};

void test1(const int &a, const int &b)
{   
    lover lt;
    lt.age = 10;
    std::cout << a + b << std::endl;
}

int main()
{
    test1(10, 10);
    system("pause");
    return 0;
}

