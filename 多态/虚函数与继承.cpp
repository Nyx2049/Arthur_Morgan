#include <iostream>

using namespace std;

class animal
{
public:
    virtual void speak()
    {
        printf("animal is speaking!\n");
    }
};

class person : public animal
{
public:
    void speak()
    {
        printf("person is speaking\n");
    }
};

class woman : public person
{
    void speak()
    {
        printf("LTSY is speaking\n");
    }
};

void Dospeak(animal &a)
{
    a.speak();
}

int main()
{
    person p;
    Dospeak(p);

    woman LT;
    Dospeak(LT);
    system("pause");
    return 0;
}