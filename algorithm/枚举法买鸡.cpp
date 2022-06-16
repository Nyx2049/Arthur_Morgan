/*百元买鸡，母鸡一�?3元，公鸡一�?5元，小鸡一�?3只，
现在�?100元买一百只鸡，每种鸡最少一只，问各有几�?
*/

//ö�� = ѭ��+�ж�
#include <iostream>

//方程约束如下
// x+y+z = 100;
// 5x + 3y + 0.33333z = 100;
// x>0 ,y > 0, z > 0;
// z%3 == 0 ;
// x;  //公鸡
// y; //母鸡
// z; //小鸡

void enumerate()
{
    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j < 33; j++)
        {
            for (int q = 1; q < 98; q++)
            {
                if (i + j + q == 100 && 5 * i + 3 * j + q / 3 == 100 && q % 3 == 0)
                {
                    std::cout << "x:" << i << "\n"
                              << "y:" << j << "\n"
                              << "z:" << q << std::endl;
                }
            }
        }
    }
}

void enumerateMore()
{
    for (int i = 1; i < 18; i++)
    {
        for (int j = 1; j < 32; j++)
        {
            for (int q = 3; q < 97; q += 3)
            {
                if (i + j + q == 100 && 5 * i + 3 * j + q / 3 == 100 && q % 3 == 0)
                {
                    std::cout << "x:" << i << "\n"
                              << "y:" << j << "\n"
                              << "z:" << q << std::endl;
                }
            }
        }
    }
}

void enumerateBetter()
{
    for (int i = 1; i < 18; i++)
    {
        for (int j = 1; j < 32; j++)
        {
            int q = 100 - i - j;
            if (5 * i + 3 * j + q / 3 == 100 && q % 3 == 0)
            {
                std::cout << "x:" << i << "\n"
                          << "y:" << j << "\n"
                          << "z:" << q << std::endl;
            }
        }
    }
}

void enumerateFinal()
{
    for (int i = 1; i < 15; i++)
    {
        int j = (100-7*i) / 4;
        int q = 100 - i - j;
        if (q % 3 == 0 && (100 - 7*i) % 4 == 0)
        {
            std::cout << "x:" << i << "\n"
                      << "y:" << j << "\n"
                      << "z:" << q << std::endl;
        }
    }
}
int main()
{
    enumerateFinal();
    // system("pause");
    return 0;
}