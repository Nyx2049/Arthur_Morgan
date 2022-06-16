#include <iostream>

class cpu
{
public:
    virtual void calculate(){return;};
};

class gpu
{
public:
    virtual void display(){return;};
};

class memory
{
public:
    virtual void storge(){return;};
};

struct computer
{
public:
    computer(cpu *c, gpu *g, memory *m)
    {   
        m_c = c;
        m_g = g;
        m_m = m;
        printf("computor is building!\n");
    }
    void dowork()
    {
        m_c->calculate();
        m_g->display();
        m_m->storge();
    }
private:
    cpu *m_c;
    gpu *m_g;
    memory *m_m;
};
// inte
class inteCpu : public cpu
{
public:
    virtual void calculate()
    {
        printf("intel CPU is working\n");
    }
};

class inteGpu : public gpu
{
public:
    virtual void display()
    {
        printf("intel GPU is working\n");
    }
};

class inteMemory : public memory
{
public:
    virtual void storge()
    {
        printf("intel memory is working\n");
    }
};

// navida
class nvidiaCpu : public cpu
{
public:
    virtual void calculate()
    {
        printf("nvidiaCpu is working\n");
    }
};

class nvidiaGpu : public gpu
{
public:
    virtual void display()
    {
        printf("nvidiaGpU is working\n");
    }
};

class nvidiaMemory : public memory
{
public:
    virtual void storge()
    {
        printf("nvidiaMemory is working\n");
    }
};

void test01()
{
    inteCpu *inteC = new inteCpu;
    inteGpu *inteG = new inteGpu;
    inteMemory *inteM = new inteMemory;
    nvidiaCpu *nvidiaC = new nvidiaCpu;
    nvidiaGpu *nvidiaG = new nvidiaGpu;
    nvidiaMemory *nvidiaM = new nvidiaMemory;
    computer p1(inteC, inteG, inteM);
    computer p2(nvidiaC, inteG, inteM);
    computer p3(nvidiaC, nvidiaG, nvidiaM);
    p1.dowork();
    p2.dowork();
    p3.dowork();
    delete inteC;
    delete inteG;
    delete inteM;
    delete nvidiaC;
    delete nvidiaG;
    delete nvidiaM;
}
int main()
{
    test01();
    return 0;
}

//看了自己写的代码，我是傻逼   20220411

//学到了什么 
//1、虚拟基类可用指针来实例化
//2、在最后的组成的computer里，加一个析构函数，来释放成员变量。
//3、可以用父类指针来指向子类对象。
//4、可以直接用new，来构造computer。  20220411 0点左右  记得重写一个final版本。
