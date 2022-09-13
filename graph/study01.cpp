//图结构：多对多的关系

//点：数据
//边： 点之间的关系

//临接矩阵： 数组 
/* 
用一维数组存储所有定点
用一个二维数组来储存所有的边
*/
//临接表： 链表
/*
用一个一维数组或事一个链表来存储所有顶点
每个顶点都是一个链表的头节点，后面跟着所有能通过边能到达的顶点
*/
#include <iostream>
#include <vector>
using namespace std;
void test01()
{
    vector<int> vecInt{1, 2, 3, 9, 10};
}