//
// Created by lijm62 on 2023/9/4.
//

#ifndef CATHCHWIND_CURIOUSLYRECURRINGTEMPLATEPATTERN_H
#define CATHCHWIND_CURIOUSLYRECURRINGTEMPLATEPATTERN_H

#include <iostream>
#define CRTP CuriouslyRecurringTemplatePattern
namespace CRTP
{
template <typename child>
class Parent
{
  public:
    //    void function() { static_cast<child *>(this)->func(); }
    void function();
};

class ChildOne : public Parent<ChildOne>
{
  public:
    void func();
};

class ChildTwo : public Parent<ChildTwo>
{
  public:
    void func();
};

void testCRTP();

}  // namespace CRTP
// #define CRTP CuriouslyRecurringTemplatePattern
#endif  // CATHCHWIND_奇怪的设计模式_CURIOUSLYRECURRINGTEMPLATEPATTERN_H
