#ifndef TOOLS_CPP
#define TOOLS_CPP
#include <array>
#include <iostream>

#include <string>
#include <sys/syslimits.h>
#include <vector>


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

void testDuplicateRemoval() {
  std::vector<int> a{1, 2, 3, 3, 4, 10, 1, 2, 4, 5};
  printArray(a);
  duplicateRemoval(a);
  printArray(a);
  return;
}
#endif