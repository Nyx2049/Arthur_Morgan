#include <iostream>

class person
{
public:
    virtual void speak()=0;
    int m_Age;
    int m_Name;
};

class women : public person
{
public:
    void speak()
    {
        printf("LT is speaking!\n");
    }
};
void test01()
{
    person *p = new women;
    p->speak();
    delete p;
}
int main()
{   
    test01();
    return 0;
}