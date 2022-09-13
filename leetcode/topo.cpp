#include <iostream>
#include <vector>
#include <unordered_map>
#include "../tools.cpp"
using namespace std;

typedef vector<int> topoline;
bool canFinish(int numCourses, vector<vector<int>> &prerequisites) 
{   
    // if (prerequisites.size() == 1)
    // {
    //     if (numCourses >= 2)
    //     {
    //         return true;
    //     }
    // }
    vector<int> array;
    bool is_ring = true;
    for (auto &info : prerequisites)
    {   
        array.emplace_back(info[0]);
        array.emplace_back(info[1]);
    }
    duplicateRemoval(array);

    std::cout << " already get the Array!" << std::endl;

    for (auto &num : array)
    {   
        vector<int> _array;
        _array.emplace_back(num);
        int _num = num;
        int count = 0;
        // while (count < prerequisites.size())
        // {  
        //     if (prerequisites[count][1] == _num)
        //     {
        //         _array.emplace_back(prerequisites[count][0]);
        //     _num = prerequisites[count][0];
        //     }
        //     else if (prerequisites[count][0] == _num)
        //     {
        //         _array.emplace_back(prerequisites[count][1]);
        //     _num = prerequisites[count][1];
        //     }
        //     count++;
        // }
        for (auto &edge : prerequisites)
        {
            if (edge[1] == _num)
            {
                _array.emplace_back(edge[0]);
                _num = edge[0];
            }
            else if (edge[0] == _num)
            {
                _array.insert(_array.begin(), edge[1]);
                _num = edge[1];
            }
        }
        if (_array[0] == _array[_array.size() - 1])
        {
            is_ring =  false;
        }
        printArray(_array);
    }
    std::cout << " already get bool Result!" << std::endl;
    if (is_ring && numCourses >= array.size())
    {
        return true;
    }
    else return false;
};

void testCanFinish()
{   
    vector<vector<int>> a = {{0, 1}, {2, 3}, {1, 2}, {3, 0}};
    int b = 5;
    if (canFinish(b, a))
    {
        std::cout << " 能上完所有课！ " << std::endl;
    }
    else 
    {
         std::cout << " bu能上完所有课！ " << std::endl;
    }
    return;
}
//广度优先搜索
// bool canFinishOut(int numCourses, vector<vector<int>> &prerequisites) = default;
