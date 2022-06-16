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

class computer
{
public:
    computer(cpu *c, gpu *g, memory* m)
    {
        this->m_c = c;
        this->m_g = g;
        this->m_m = m;
        printf("building is working!\n");
    }
    ~computer()
    {
        if (m_c != NULL)
        {
            delete m_c;
            m_c = NULL;
        }
        if (m_g != NULL)
        {
            delete m_g;
            m_g = NULL;
        }
        if (m_m != NULL)
        {
            delete m_m;
            m_m = NULL;
        }
        printf("destroy is working!\n");
    }
    void doWork()
    {
        this->m_c->calculate();
        this->m_g->display();
        this->m_m->storge();
    }
private:
    cpu *m_c;
    gpu *m_g;
    memory *m_m;
};

class inteCpu : public cpu
{
public:
    void calculate()
    {
        printf("inteCPu is cal!\n");
    }
};

class integpu : public gpu
{
public:
    void display()
    {
        printf("integPu is dosplay!\n");
    }
};
class intememory : public memory
{
public:
    void storge()
    {
        printf("intememory is storge!\n");
    }
};

class NvCpu : public cpu
{
public:
    void calculate()
    {
        printf("nvCPu is cal!\n");
    }
};

class Nvgpu : public gpu
{
public:
    void display()
    {
        printf("nvgPu is dosplay!\n");
    }
};
class Nvmemory : public memory
{
public:
    void storge()
    {
        printf("nvmemory is storge!\n");
    }
};

void test01()
{
    inteCpu *c1 = new inteCpu;
    integpu *g1 = new integpu;
    intememory *m1 = new intememory;    
    computer comp1(c1, g1, m1);
    computer comp2(new inteCpu, new Nvgpu, new intememory);
    computer comp3(new NvCpu, new Nvgpu, new Nvmemory);
    comp1.doWork();
    comp2.doWork();
    comp3.doWork();
    return;
}

int main()
{
    test01();
    system("pause");
    return 0;
}
