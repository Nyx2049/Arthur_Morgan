#include "CuriouslyRecurringTemplatePattern.h"

using namespace CRTP;
template <typename child>
void Parent<child>::function()
{
    static_cast<child *>(this)->func();
}
void ChildOne::func()
{
    printf("childOne func is Work\n");
}

void ChildTwo::func()
{
    printf("childTwo func is Work\n");
}
void CRTP::testCRTP()
{
    ChildOne c1;
    ChildTwo c2;
    c1.function();
    c2.function();
}