#ifndef MAIN_CPP
#define MAIN_CPP
// #include "ConvexHull/convex_hull_High.hpp"
#include "DataStructure/Array.hpp"
#include "algorithm/recursion.hpp"
#include "algorithm/QuikySort.hpp"
#include "leetcode/test.cpp"
#include "tools.cpp"
#include "leetcode/topo.cpp"
#include "leetcode/verticlPrintWord.cpp"
#include <thread>
#include "MultiThread/CXXThread.hpp"

class ATest
{
public:
    void operator()()
    {
        std::cout << "该线程正在被调用" << std::endl;
    }
};
int main()
{       
    ClassThreadStudy();
    // testArray001(); 
    // testprintVerticl();
    // testSplit();
    // testCanFinish();
    // testDuplicateRemoval();
    // testForAddAdd();
    // test_quikySort_mine();
    // testInsert();
    //testSwap();
    // testint();
    // runQuickSortMy();
    //testInt();
    // while(1);
    return 0;
}
#endif