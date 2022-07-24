#include <iostream>
#include <vector>

typedef struct std::pair<double, double> Point;
enum Ternary
{
    Yin = -1,
    Yang = 1,
    Yuan = 0,
};
//测试pair的用法。
void test01()
{
    Point p = std::make_pair(0.0, 1.0);
    std::cout << p.second << std::endl;
}

//判等函数
double getAver(std::vector<bool> &_list)
{
    double sum;
    for (auto &&it : _list)
    {
        sum += it;
    }
    return sum / _list.size();
}

//这是三元的情况。
double getAver_2_0(std::vector<int> &_list)
{
    double sum;
    for (int a = 0; a < _list.size(); a++)
    {
        if (_list[a] == Yuan)
        {
            if (a == 0)
            {
                _list[a] = _list[a + 1];
            }
            _list[a] = _list[a - 1];
        }
        sum += _list[a];
    }
    return sum / _list.size();
}
// 经过自己测试，第二版本 依然不正确，如果上一一个值，也是Yuan,那么无法正确,下为第三版本。
double getAver_3_0(std::vector<int> &_list)
{
    double sum;
    int v = 0;
    for (auto &&_v : _list)
    {
        if (_v != 0)
        {
            v = _v;
            break;
        }
    }
    if (v == 0)
    {
        return 1.0;
    }
    for (int a = 0; a < _list.size(); a++)
    {
        if (_list[a] == 0)
        {
            _list[a] = v;
        }
        sum += _list[a];
    }
    return sum / _list.size();
}
//根据两个点坐标湖获取对应的k，b值。
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

// 2.0版本考虑到，点数据正好在线上的功能，选择采用枚举+二次判断的方式来作解法，同时需要一个新的justice_2.0来作判断
Ternary PointEquation_2_0(double &k, double &b, Point &p)
{
    if (k == NULL)
    {
        if (p.first < b)
            return Yang;
        else if (p.first > b)
            return Yin;
        return Yuan;
    }
    else if (b == NULL)
    {
        if (p.second < k)
            return Yang;
        else if (p.second > k)
            return Yin;
        return Yuan;
    }
    else
    {
        if (p.second - k * p.first - b < 0)
            return Yang;
        else if (p.second - k * p.first - b > 0)
            return Yin;
        return Yuan;
    }
}

void getConvexHull_1_0(std::vector<Point> &pts, std::vector<Point> &edgePts)
{
    //双循环遍历所有的点与点连线的可能
    for (int num = 0; num < pts.size(); num++)
    {
        bool rightEdge = false;
        for (int _num = 0; _num < pts.size(); _num++)
        {
            if (pts[num].first == 0.25)
            {
                int aksldja = 0;
            }
            std::vector<int> justice;
            double k, b;
            if (!getKandB(pts[num], pts[_num], k, b))
                continue;
            for (auto &&pt : pts)
            {
                justice.push_back(PointEquation_2_0(k, b, pt));
            }
            double value = getAver_3_0(justice);
            std::cout << "value:" << value << std::endl;
            if ((value == -1) || (value == 1))
            // if (getAver(justice) == 0|| (getAver(justice) == 1)) //为什么结果不同 和上一句
            {
                // std::cout << "getAver(justice):" << getAver(justice) << std::endl;
                rightEdge = true;
                break;
            }
        }
        std::cout << "rightEdge: " << rightEdge << std::endl;
        if (rightEdge)
        {
            std::cout << "pts[num]:" << pts[num].first << ", " << pts[num].second << std::endl;
            edgePts.push_back(pts[num]);
        }
    }
}

void test02()
{
    Point p3 = std::make_pair(0.25, 0.5);
    Point p1 = std::make_pair(0.0, 0.0);
    Point p2 = std::make_pair(1.0, 1.0);
    Point p4 = std::make_pair(0.0, 1.0);
    Point p5 = std::make_pair(1.0, 0.0);
    Point p6 = std::make_pair(2.0, 2.0);
    Point p7 = std::make_pair(0.0, 4.0);
    Point p8 = std::make_pair(4.0, 0.0);
    Point p9 = std::make_pair(0.1, 0.5);
    Point p10 = std::make_pair(0.5, 0.5);

    std::vector<Point> pts, edgePts;
    // pts = {p1, p2, p3, p4, p5, p5, p6, p7, p8, p1, p7, p8, p9, p10};
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

void test04()
{
    Point p1 = std::make_pair(1.0, 0.1);
    Point p2 = std::make_pair(0.0, 0);
    Point p3 = std::make_pair(100.0, 0);
    Point p4 = std::make_pair(1.0, 0.0);
    Point p5 = std::make_pair(40.0, 0);
    Point p6 = std::make_pair(27.0, 0);
    Point p7 = std::make_pair(30.0, 0);
    Point p8 = std::make_pair(50, 100);

    std::vector<Point> pts, edgePts;
    pts.push_back(p1);
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
    //使用枚举变量的心得， 整数型的枚举可以自动转换成整型，但是整形不能直接当作枚举
    std::vector<int> vb;
    vb.push_back(0);
    vb.push_back(0);
    vb.push_back(0);
    vb.push_back(0);
    vb.push_back(0);
    vb.push_back(0);
    // vb.push_back(1);
    // vb.push_back(1);
    // vb.push_back(0);
    // vb.push_back(Yang);
    vb.push_back(Yuan);
    double c = getAver_3_0(vb);
    std::cout << " getAver(vb):" << c << std::endl;
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
    test04();
    // test_getAver();
    // test_PointEquation_1_0(); //经过测试，没有问题，同一方向的返回值一致
    return 0;
}

/*study：
一、使用枚举变量的心得， 整数型的枚举可以自动转换成整型，但是整形不能直接当作枚举

*/
