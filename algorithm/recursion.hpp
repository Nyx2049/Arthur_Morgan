#include <iostream>
#include <tuple>
#include <string>
int getN(const int &n)
{   
    int f = 10;
    if (n == 0 || n== 1)
    {   
        f = 1;
    }
    else if (n < 0 )
    {   
        std::cout << "Negative numbers have no factorial!";
    }
    else 
    f = getN(n-1)*n;
    return f;
    
}
void recGetN()
{   
    int n;
    std::cout << "Please enter an integer to calculate the factorial:";
    std::cin >> n;
    int f = getN(n);
    std::cout << "The factorial of "<< n << " is "<< std::to_string(f) << std::endl;
}
