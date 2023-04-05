#include "SingleObj.hpp"

MySingle *MySingle::m_instance = nullptr;

void buildSingle()
{
    MySingle *p_a = MySingle::getInstance();  //创建对象
    p_a->funcTest();
    MySingle::getInstance()->funcTest();
}