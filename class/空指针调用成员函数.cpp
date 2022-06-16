#include <iostream>

using namespace std;
class lover
{
public:
    void showAge()
    {   
        if (this != NULL)
        {
            cout << age << endl;
        }
        else
        {
            cout << "error" << endl;
        }
    }
    int age;
};

void test()
{
    lover *lt = NULL;
    lt->showAge();
}

int main()
{
    test();
    system("pause");
    return 0;
}

