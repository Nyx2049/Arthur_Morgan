#include "stu.h"
#include <iostream>
void Lamda::lamdatest()
{
    int a    = 10;
    int b    = 1000;
    auto add = [&](const int &c, const int &d) {
        a = 1000;
        return a + b + c + d;
    };
    printf("a + b = %d\n", add(1, 3));
    printf("heiheihei is runing!\n");
}