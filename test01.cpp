#include <iostream>
#include <vector>
#include <time.h>
#include <cmath>

using namespace std;

vector<int> list;
void base()
{
    for (int i = 10000; i > 0; i--)
    {
        list.push_back(i);
    }
}

void test01(vector<int> a)
{
    // for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
    // {
    //     cout << *it << endl;
    // }
    for (int i = 0; i < 10000; i++)
    {
        cout << list[i] << endl;
    }
}
void test02(vector<int> a)
{
    for (int i = 0; i < 10000; i += 5)
    {
        cout << list[i] << endl;
        cout << list[i + 1] << endl;
        cout << list[i + 2] << endl;
        cout << list[i + 3] << endl;
        cout << list[i + 4] << endl;
    }
}
void base2()
{
    vector<vector<int>> list2;
    vector<int> v1, v2, v3, v4, v5, v6, v7, v8, v9, v10;
    
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i+10);
        v3.push_back(i+20);
        v4.push_back(i+30);
        v5.push_back(i+40);
        v6.push_back(i+50);
        v7.push_back(i+60);
        v8.push_back(i+70);
        v9.push_back(i+80);
        v10.push_back(i+90);
    }
    list2.emplace_back(v1);
    list2.emplace_back(v2);
    list2.emplace_back(v3);
    list2.emplace_back(v4);
    list2.emplace_back(v5);
    list2.emplace_back(v6);
    list2.emplace_back(v7);
    list2.emplace_back(v8);
    list2.emplace_back(v9);
    list2.emplace_back(v10);
    // for (vector<int>::iterator &&vit = (v3).begin(); vit != v3.end(); vit++)
    // {
    //     cout << *vit << " ";
    // }
    // cout << endl;
    

    for (vector<vector<int>>::iterator &&it = list2.begin(); it != list2.end(); it++)
    {
        for (vector<int>::iterator &&vit = it->begin(); vit != it->end(); vit++)
        {
            cout << *vit << " ";
        }
        cout << endl;
    }
}
// void test03 (vector<vector<int>> a)
// {
//     for (vector<vector<int>>::iterator &&it = a.begin(); it != a.end(); it++)
//     {
//         for (vector<int>::iterator &&vit = (*it).begin(); vit != (*it).end(); vit++)
//         {
//             cout << *vit << endl;
//         }
//     }   cout << endl;
// }
int main()
{   
    clock_t start, finish;
    start = clock();
    // base();
    base2();
    finish = clock();
    cout << double(finish - start) / CLOCKS_PER_SEC << endl;
    return 0;
}