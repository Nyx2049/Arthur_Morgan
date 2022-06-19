#include <iostream>
#include <vector>

typedef struct std::pair<double, double> Point;
//测试pair的用法。
void test01()
{
    Point p = std::make_pair(0.0, 1.0);
    std::cout << p.second << std::endl;
}

double getAver(std::vector<bool> &_list)
{
    double sum;
    for (auto &&it : _list)
    {
        sum += it;
    }
    return sum / _list.size();
}

bool getKandB(Point &A, Point &B, double &k, double &b)
{
    if (A.first == B.first && A.second == B.second)
    {
        return false;
    }
    else if (A.first == B.first && A.second != B.second)
    {
        k = NULL;
        b = A.first;
        return true;
    }
    else if (A.first != B.first && A.second == B.second)
    {
        k = A.second;
        b = NULL;
        return true;
    }
    k = (B.second - A.second) / (B.first - A.first);
    b = (B.second + A.second) / 2 - k * (A.first + B.first);
    return true;
}

bool PointEquation_1_0(double &k, double &b, Point &p)
{
    if (k == NULL)
    {
        if (p.first <= b)
            return true;
        return false;
    }
    else if (b == NULL)
    {
        if (p.second <= k)
            return true;
        return false;
    }
    else
    {
        if (p.second - k * p.first - b <= 0)
            return true;
        return false;
    }
}

void getConvexHull_1_0(std::vector<Point> &pts, std::vector<Point> &edgePts)
{
    bool rightEdge = false;
    for (int num = 0; num < pts.size(); num++)
    {
        for (int _num = 0; _num < pts.size(); _num++)
        {
            std::vector<bool> justice;
            double k, b;
            if (!getKandB(pts[num], pts[_num], k, b))
                continue;
            for (auto &&pt : pts)
            {
                justice.push_back(PointEquation_1_0(k, b, pt));
            }
            double value = getAver(justice);
            std::cout << "value:" << value << std::endl;
            if ((value == 0) || (value == 1))
            // if (getAver(justice) == 0|| (getAver(justice) == 1)) //为什么结果不同 和上一句
            {
                //std::cout << "getAver(justice):" << getAver(justice) << std::endl;
                rightEdge = true;
                break;
            }
        }
        std::cout << "rightEdge: " << rightEdge << std::endl;
        if (rightEdge)
        {
            edgePts.push_back(pts[num]);
        }
    }
}

void test02()
{
    Point p1 = std::make_pair(0.0, 0.0);
    Point p2 = std::make_pair(1.0, 1.0);
    Point p3 = std::make_pair(0.25, 0.5);
    Point p4 = std::make_pair(0.0, 1.0);
    Point p5 = std::make_pair(1.0, 0.0);
    std::vector<Point> pts, edgePts;
    pts.push_back(p1);
    pts.push_back(p2);
    pts.push_back(p3);
    pts.push_back(p4);
    pts.push_back(p5);
    getConvexHull_1_0(pts, edgePts);
    std::cout << "edgePts.size():" << edgePts.size() << std::endl;
    int a = 1;
    for (auto &&it : edgePts)
    {
        char b = a + '0';
        std::cout << "edgePts[" << b << "]:" << it.first << ", " << it.second << std::endl;
        a++;
    }
}

void test_getAver()
{
    std::vector<bool> vb;
    vb.push_back(true);
    vb.push_back(true);
    vb.push_back(true);
    vb.push_back(true);
    vb.push_back(false);
    vb.push_back(true);
    vb.push_back(true);
    vb.push_back(true);
    std::cout << " getAver(vb):" << getAver(vb) << std::endl;
}

// bool PointEquation_2_0(std::vector<Point> &vP, const double &k, const double &b)
// {

// }
//测试Point函数是否正确
void test_PointEquation_1_0()
{
    double k = 3;
    double b = NULL;
    Point p1 = std::make_pair(1, 100);
    Point p2 = std::make_pair(1.5, 3);
    PointEquation_1_0(k, b, p1);
    PointEquation_1_0(k, b, p2);
    std::cout << "PointEquation(k, b, p1):" << PointEquation_1_0(k, b, p1) << std::endl;
    std::cout << "PointEquation(k, b, p2):" << PointEquation_1_0(k, b, p2) << std::endl;
}
int main()
{
    test02();
    // test_getAver();
    //test_PointEquation_1_0(); //经过测试，没有问题，同一方向的返回值一致
    return 0;
}