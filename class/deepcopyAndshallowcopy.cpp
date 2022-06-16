//深拷贝和浅拷贝

#include <iostream>
#include <string>
using namespace std;

class lover
{
public:
    lover()
    {   
        std::cout << "building is working " << std::endl;
    }
    lover(int _age, int _name)
    {
        age = _age;
        name = new int(_name);
        std::cout << "building is working with arg" << std::endl;
    }
    // lover(const lover &p)
    // {
    //     age = p.age;
    //     name = p.name; 
    //     std::cout << "building is working with copy" << std::endl;
    // }
  
    ~lover()
    {   
        // cout << name << endl;
        if (name != NULL)
        {   
            // cout << *name << endl;

            delete name;
            // cout << "111111:" << *name << endl;
            // cout <<"22222:" <<  name << endl;
            name = NULL;
            // cout << "333333:" << *name << endl;
            // cout << name << endl;
        }
        std::cout << "destructing is working " << std::endl;
    }
    int age;
    int *name;

};

void test()
{
    lover lt(19, 6879);
    cout << *lt.name << endl;
    lover lt2(lt);
    cout << *lt2.name << endl;
}


int main()
{   
    test();
    system("pause");
    return 0;
}