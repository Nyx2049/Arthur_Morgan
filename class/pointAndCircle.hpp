#pragma once
#include <iostream>

class Point
{
private:
    int X;
    int Y;
public:
    void setX(int _x);
   
    void setY(int _y);
 
    int getX();
  
    int getY();
  
};

class Circle
{
private:
    Point a;
    int R;

public:
    int getR();
 
    void setR(int r);
 
    Point getCenter();

    void setPoint(Point center);
};

