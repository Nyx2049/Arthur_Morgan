#include "stdio.h"

void test()
{
    printf("      **\n\
    ********************\n\
******************************\n\
***********     *****************\n\
!@#123sdfsdfgsty        **\n");
}
void testfinal()
{
    int a = 100;
    char* b;
    b = "LTSY";
    float c = 1.4888;
    char e = '9';
    double f = 3.1415926;
    printf("int a: %d\n", a);
    printf(" 我爱的女人叫做 %c , h哈哈\n", b[3]);
    printf(" 我爱的女人叫做 %s , h哈哈\n", b);
    printf(" 圆周率是: %5.3f\n", f);
    printf(" 浮点类型是: %.10f\n", c);
    return;
}
int main()
{
    printf("hello c World\n");
    test();
    testfinal();
    return 0;
}
