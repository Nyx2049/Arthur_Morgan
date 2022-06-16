#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;



vector<int> test01(vector<int> &a, int b)
{
    unordered_map<int, int> c;
    for (int i = 0; i < a.size(); ++i)
    {
        auto &&it = c.find(b - a[i]);
        if (it != c.end())
        {
            return {i, it->second};
        }
        c[a[i]] = i;
    }
    return {};
}

int main()
{
    vector<int> a{1, 3, 45, 123};
    int b = 48;
    cout << test01(a, b)[0] << " " << test01(a, b)[1] << " " << test01(a, b)[2] << endl;
}