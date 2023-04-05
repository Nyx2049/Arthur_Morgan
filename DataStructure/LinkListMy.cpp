#include "LinkListMy.hpp"

template <typename T>
node* node::next()
{
    return ptr;
}
template <typename T>
T node::getValue()
{
    return t;
}
