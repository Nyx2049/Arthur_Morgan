#include <iostream>

class Circle
{
public:
    // Circle();
    // Circle(const double PI, int R);
    // const double PI = pi;
    // int R = r;
    int R;
    const double PI = 3.14;
    double get_ZC(){
        return 2 * PI * R;
    };
};


int main()
{
    Circle c1;
    c1.R = 5;
    std::cout << c1.get_ZC() << std::endl;
    system("pause");
    return 0;
}
