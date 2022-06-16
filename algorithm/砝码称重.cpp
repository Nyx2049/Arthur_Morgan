#include <iostream>
#include <vector>
/*问题描述
设有1g， 2g ， 3g ，5g, 10g, 20g的砝码若干，（总重 < 1000g),
求用这些砝码能称出不同重量的个数。

输入：输入1g， 2g ， 3g ，5g, 10g, 20g 的个数，例如【1， 1， 0， 0， 0， 0】

输出：能称出的不同重量的个数 ， 例如以上输出为：3.*/
using namespace std;

const int g1 = 1;
const int g2 = 2;
const int g3 = 3;
const int g4 = 5;
const int g5 = 10;
const int g6 = 20;

vector<bool> a;
vector<int> b{10, 0, 0, 0, 5, 1000};

int enumerate(const vector<int> &b)
{
    int y = 0;
    a.resize(1001);
    for (int i = 0; i <= b[0]; i++)
    {
        for (int j = 0; j <= b[1]; j++)
        {
            for (int k = 0; k <= b[2]; k++)
            {
                for (int l = 0; l <= b[3]; l++)
                {
                    for (int m = 0; m <= b[4]; m++)
                    {
                        for (int n = 0; n <= b[5]; n++)
                        {
                            a[i + j * 2 + k * 3 + l * 5 + m * 10 + n * 20] = true;
                        }
                    }
                }
            }
        }
    }
    for (auto &&x : a)
    {
        if (x)
        {
            y++;
        }
    }
    return y - 1;
}
/*分析：

比如2 1 2 1 1 1 的输入数据，就是表示1 1 2 3 3 5 10 20

问题就转化为 1 1 2 3 3 5 10 20 的砝码。

对里面的每一个取或者不取， 可以组成多少总重量

那么这就是一个标准的01背包问题。
*/
int enumerateMore(const vector<int> &b)
{
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;
    int a6;
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
    int all = a1 + a2 + a3 + a4 + a5 + a6;
    int k;
    int a[];
    for (int i = 0; i < all; i++)
    {
        
    }
}

int main()
{
    cout << enumerate(b) << endl;
    ;
    return 0;
}