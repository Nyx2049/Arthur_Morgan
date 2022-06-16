#include <iostream>

class cpu
{
public:
    virtual void calculate() = 0;
};

class gpu
{
public:
    virtual void display() = 0;
};

class memory
{
public:
    virtual void storge() = 0;
};

struct computer
{
public:
    computer(cpu *c, gpu *g, memory *m)
    {
        printf("computor is building!\n");
    }
    void dowork(cpu *c, gpu *g, memory *m)
    {
        c->calculate();
        g->display();
        m->storge();
    }
private:
    cpu *c;
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
    p1.dowork(inteC, inteG, inteM);
    p2.dowork(nvidiaC, inteG, inteM);
    p3.dowork(nvidiaC, nvidiaG, nvidiaM);
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
