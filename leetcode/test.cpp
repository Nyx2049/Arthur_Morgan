#include <iostream>
#include <memory>
#include <vector>

using namespace std;

void testForAddAdd() {
  vector<vector<int>> edges = {{4, 2}, {3, 2}, {1, 0}};
  int n = 10;
  vector<vector<int>> g(4);
  vector<int> deg(4);
  for (auto e : edges) 
  {
    int a = e[1], b = e[0];
    g[a].push_back(b);
    deg[b]++;
  }
  for (auto e : g) 
  {
    for (auto a : e)
     printf("now: %d\n", a); 
}

  for (auto e : deg) 
  {
     printf("11now: %d\n", e); 
}
  return;
}
