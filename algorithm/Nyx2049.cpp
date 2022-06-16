#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>
#include <cmath>

//构造近似相等函数
bool Approximate_Equality(double& a, double& b)
{   
    if (abs(a - b) < 0.5)  return true;
    else return false;
}


//笨比双循环
std::vector<double>  getWanted(std::vector<double> &num)
{
    std::vector<double> num2;
    num2.push_back(num[0]);
    for (int a = 1; a < num.size() ;a++)
    {   
        bool yes = false;
        for (auto &&_it = num2.begin(); _it < num2.end(); _it++)
        {   
            if (Approximate_Equality(num[a], *_it))
            {   
                yes = true;
                break;
            }
        }
        if (!yes)
        {
            num2.push_back(num[a]);
        }
    }
    return num2;
}
void test01()
{   
    //初始化用到的数据
    std::vector<double> num{1, 1.1, 2, 2.1, 3.5, 3, 3.9, 3.72, 1.3,  17, 13.1, 13.9};
    // std::vector<double> num{1, 1.1, 2, 2.1};
   std::vector<double>  wanted = getWanted(num);
    for (auto &&it : wanted)
    {
        std::cout << it << std::endl;
    }
    // std::map<double, int> m1;

    //初始化一个无序set，存我要的整数
    // std::unordered_set<int> _wanted;
    // for (int i = 0; i < num.size() ; i++)
    // {
    //     if (Approximate_Equality(m1[i], ))
    // }
}


int main()
{
    test01();
    return 0;
}










// int main()
// {
//     double a = 10.7;
//     double b = 10.3;
//     std::cout << Approximate_Equality(a, b) << std::endl;
//     return 0;
// }