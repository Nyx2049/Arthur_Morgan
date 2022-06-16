#include <iostream>
#include "pointAndCircle.hpp"


void Point::setX(int _x)
{
    X = _x;
    // std::cout << "x:" << X << std::endl;
};
void Point::setY(int _y)
{
    Y = _y;
};
int Point::getX()
{
    return X;
};
int Point::getY()
{
    return Y;
}




int Circle::getR()
{
    return R;
};
void Circle::setR(int r)
{
    R = r;
};

Point Circle::getCenter()
{
    return a;
}


void Circle::setPoint(Point center)
{
    a = center;
}


