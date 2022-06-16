#include <iostream>
#include <string>
// class student
// {
// public:
//     std::string name;
//     int num;
//     void print()
//     {
//         std::cout << "name:" << name << "\n" << "num:" << num << std::endl;
//     };

// };

class student
{

private:

int years;
public:

/*???§Ö???????????????????????
????  ??????? ???????
???  ??????  ???????*/
    std::string name;

    void setname(std::string Name)
    {
        name = Name;
    };

    void setyears(int Years)
    {
        years = Years;
    };  
    void print()
    {
        std::cout << "????:" << name << "\n" << "????:" << years<< std::endl;
    }; 
}; 

int main()
{   
    student LTSY;
    LTSY.setname("???????");
    LTSY.setyears(19);
    // LTSY.years = 19;
    LTSY.print();
    system("pause");
    return 0;
}