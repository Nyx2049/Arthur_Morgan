#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include "../tools.cpp"
using namespace std;
std::vector<std::string> printVerticl(std::string s)
{
    vector<string> splitWords = split(s, ' ');
    int max = -INT_MAX;
    for (auto str : splitWords)
    {
        printf("str.length(): %d\n", int(str.length()));
        // max = max > str.length() ? max : str.length(); 
        if (max < int(str.size()))
        {
            max = int(str.size());
        }
    }
    printf("max = %d\n", max);
    for (int i = 0; i < splitWords.size(); i++)
    {
        if (splitWords[i].length() < max)
        {
            int num = max - splitWords[i].length(); 
            // for (int j = 1; j <= max - splitWords[i].length(); j++)
            for (int j = 1; j <= num; j++)
            {
                splitWords[i]+=' ';
            }
        }
    }
    printf("第一次填充的结果: \n");
    printArray(splitWords);
    vector<string> results;
    for (int i = 0; i < max; i++)
    {  
        string re;
         for (int j = 0; j < splitWords.size(); j++)
         {
            re += splitWords[j][i];
         }
         results.emplace_back(re);
    }
    for (auto it : results)
    {
       for (int i = it.size() - 1; i >= 0; i--)
       {
        if (it[i] == ' ')
        {
            int c = it.size();
            it.pop_back();
            int ad = it.size();
        }
        else {
            break;
        }
       }
    }
    return results;
}

void testprintVerticl()
{
    printf("App is working\n");
    string c = "TO BE OR NOT TO BE";
    vector<string> d = printVerticl(c);
    printArray(d);
    printf("App is Downing\n");
    return;
}