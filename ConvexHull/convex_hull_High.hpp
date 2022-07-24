//以下的新算法会使用CGAL的点数据
#include <CGAL/Point_2.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polygon_2.h>
#include <iostream>
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point;
typedef CGAL::Polygon_2<K> Polygon_2;

void test01()
{
    Point points[] = { Point(0,0), Point(0.5,6), Point(5.1,0), Point(0,1)};
    std::cout << "points:" << points[1].x() << std::endl;
}
