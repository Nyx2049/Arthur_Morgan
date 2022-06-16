#include <iostream>
#include <string>

class whiteMoonlight
{
public:
    std::string setandReturnName(std::string Name)
    {
        if (Name != "ÁõÌÆË¼Óï")
            Name = "ÁõÌÆË¼Óï";
        name = Name;
        return name;
    };

    int setyears(int Years)
    {
        years = 19;
        if (Years >= 18 || Years <= 26)
            years = Years;
        return years;    
    }

    void gaobai()
    {
        std::cout << "ÎÒÓÀÔ¶°®×Å" << years << "ËêµÄ" << name << std::endl; 
    }

private:

    std::string name;
    int years;
    std::string word;
};

int main()
{
    whiteMoonlight LTSY;
    LTSY.setandReturnName("×ÞÏ¼");
    LTSY.setyears(19);
    LTSY.gaobai();
    system("pause");
    return 0;
}