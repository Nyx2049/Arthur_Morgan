/*
 * @Author: ljm_mac lijinmengde@163.com
 * @Date: 2022-06-25 21:53:52
 * @LastEditors: ljm_mac lijinmengde@163.com
 * @LastEditTime: 2022-06-26 14:38:28
 * @FilePath: /Arthur_Morgan/CGAL/Polygon/Polygon.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <CGAL/Point_2.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polygon_2.h>
#include <iostream>
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point;
typedef CGAL::Polygon_2<K> Polygon_2;
using std::cout; using std::endl;
using namespace std;
int main()
{
  Point points[] = { Point(0,0), Point(0.5,6), Point(5.1,0), Point(0,1)};
  Polygon_2 pgn(points, points+4);
  // check if the polygon is simple.
  cout << "The polygon is " <<
    (pgn.is_simple() ? "" : "not ") << "simple." << endl;
  // check if the polygon is convex
  cout << "The polygon is " <<
    (pgn.is_convex() ? "" : "not ") << "convex." << endl;
  return 0;
}