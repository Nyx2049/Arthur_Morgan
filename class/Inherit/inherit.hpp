#ifndef INHERIT_HPP
#define INHERIT_HPP

#include <iostream>
class Person
{
    public:
    virtual void mySelf();
};

class Man : public Person
{
    public:
    virtual void mySelf();
    void mySex();
    
};

void work20221204();

#endif