#include <iostream>
#include <string>

class whiteMoonlight
{
public:
    std::string setandReturnName(std::string Name)
    {
        if (Name != "����˼��")
            Name = "����˼��";
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
        std::cout << "����Զ����" << years << "���" << name << std::endl; 
    }

private:

    std::string name;
    int years;
    std::string word;
};

int main()
{
    whiteMoonlight LTSY;
    LTSY.setandReturnName("��ϼ");
    LTSY.setyears(19);
    LTSY.gaobai();
    system("pause");
    return 0;
}