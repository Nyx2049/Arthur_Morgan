
#include "ArrayTest.hpp"
int *ptr;
int length;

void init() {
  ptr = NULL;
  length = 0;
}

void push(const int &b) {
    int *ptrNew = new int[length + 1];
  if (ptr) {
    memcpy(ptrNew, ptr, sizeof(int) * length);
    delete[] ptr;
  }
    ptr = ptrNew;
    ptr[length++] = b;
}
void pop(const int &location) { return; }

void travel() {
  printf("元素个数为%d个:\t", length);
  for (int i = 0; i < length; i++) {
    printf("%d ", ptr[i]);
  }
  printf("\n");
}

void TestInt001() {
  init();
  for (int i = 0; i < 10; i++)
  {
  push(i);
    travel();
  }
  return;
}
// int main()
// {
//     TestInt();
//     while(1);
//     return 0;
// }
