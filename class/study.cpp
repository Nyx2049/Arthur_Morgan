#include "pointAndCircle.hpp"

void check(Circle &c, Point &p1)
{     

    int instance = (c.getCenter().getX() - p1.getX()) * (c.getCenter().getX() - p1.getX()) + 
    (c.getCenter().getY() - p1.getY()) * (c.getCenter().getY() - p1.getY());
    int RR =  c.getR()* c.getR();
  

    if (instance > RR)
    {
        std::cout << "out" << std::endl;
    }
    else if (instance < RR)
    {
         std::cout << "in" << std::endl;
    }
    else
    {
         std::cout << "???????" << std::endl;
    }
        
};
int main()
{   
    Point num;
    num.setX(1);
    num.setY(0);
  
    Point i;
    Circle c1;
    i.setX(0);
    i.setY(0);
    c1.setPoint(i);
    c1.setR(1);
    check(c1, num);

    system("pause");
    return 0;
}