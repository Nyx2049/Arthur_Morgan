#include "inherit.hpp"

void Person::mySelf()
{
    printf("I am a Person\n");
}

void Man::mySelf()
{
    printf("I am a Man\n");
}
void Man::mySex()
{
    printf("I have a Dick\n");
}

void work20221204()
{
    Person* p = new Man;
    p->mySelf();
}