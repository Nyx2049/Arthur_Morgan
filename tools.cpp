#ifndef TOOLS_CPP
#define TOOLS_CPP
#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/syslimits.h>
#include <vector>


// using namespace std;
template <typename T>

void duplicateRemoval(std::vector<T> &array) {
  if (array.size() == 0)
    printf("this Array is Null");
  sort(array.begin(), array.end());
  array.erase(unique(array.begin(), array.end()), array.end());
}

template <typename F>

 void printArray(const std::vector<F> array) {
  if (array.size() == 0)
    printf("this Array is Null");
  int a = 0;
  printf("this Array is:\n");
  for (auto it : array) {
    std::cout << (std::to_string(a))<< ": " << it << std::endl;
    a++;
  }
}


std::vector<std::string> split(const std::string &strOri, const char &b)
{
    std::vector<std::string> strs;
    std::string str;
    std::istringstream istr(strOri);
    while (std::getline(istr, str, b))
    {
        strs.emplace_back(str);
    }
    return strs;
}

void testSplit()
{
    std::string b = "1,2,3 adskjads dad Lucy&David";
    std::vector<std::string> a = split(b, ' ');
    for (std::string i : a)
        printf("%s\n", i.c_str());
}

void testDuplicateRemoval() {
  std::vector<int> a{1, 2, 3, 3, 4, 10, 1, 2, 4, 5};
  printArray(a);
  duplicateRemoval(a);
  printArray(a);
  return;
}
#endif