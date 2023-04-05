/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     long long val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(long long x) : val(x), next(nullptr) {}
 *     ListNode(long long x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include "study.h"

ListNode* getList( const std::vector<long long>& vecInt)
{
    long long num = vecInt.size();
    ListNode *a = nullptr;
    ListNode *b = nullptr;
    ListNode *c = nullptr;
    for (long long i = 0; i < num; i++)
    {   
        c = new ListNode(vecInt[i]);
        if(b)
        {
            b->next=c;
            b =c;
        }
        else {
            a=b=c;
        }

    }
    return a;

}
ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
{
    long long count = 1;
    long long count2 = 1;
    long long l1Num, l2Num;
    ListNode *_l1 = l1;
    ListNode *_l2 = l2;
    l1Num         = _l1->val;
    l2Num         = _l2->val;
    while (1)
    {
        if (_l1->next == nullptr && _l2->next == nullptr)
            break;
        //  printf("Firstl1num: %d\n", l1Num);
         if (_l1->next)
         {
            l1Num += _l1->next->val * pow(10, count);
            count++;
            _l1 = _l1->next;
         }
        if (_l2->next)
        {
            l2Num += _l2->next->val * pow(10, count2);
            count2++;
             _l2 = _l2->next;
        }
    }
    // printf("l1num: %d\n", l1Num);
    // printf("l2num: %d\n", l2Num);
    long long l3Num = l1Num + l2Num;
    long long _l3num = l3Num;
    std::vector<long long> vecList;
    while (l3Num)
    {
        long long a = l3Num % 10;
        l3Num /= 10;
        // printf("%d\n", a);
        vecList.emplace_back(a);
    }
    std::cout << "l3Num: "<< _l3num << std::endl;
    if (_l3num == 0)
    {   
        ListNode *a = new ListNode(0);
        return a;
    }
    return getList(vecList);
}
void PrintListNode(ListNode* l2)
{   
    ListNode *a = nullptr;
    a = l2;
    while (1)
    {
        printf("%d ", a->val);
        if (a->next)
            a = a->next;
        else
            break;
    }
}
void testaddTwoNumbers()
{
    // ListNode l1(1);
    // ListNode l2(3, &l1);
    // ListNode l3(7, &l2);
    //  ListNode l11(1, &l3);
    // ListNode l12(3, &l11);
    // ListNode l13(7, &l12);
    ListNode *l14 = getList(std::vector<long long>{9});
    // ListNode l15(4, &l14);
    // ListNode l16(2, &l15);

    std::vector<long long> l2{1, 9,9, 9, 9 , 9, 9, 9,9 ,9};
    ListNode *l6 = getList(l2);
    ListNode *a = addTwoNumbers(l14, l6);
    PrintListNode(a);
    // std::vector<long long> nu2wq{3, 6, 7};
    // ListNode *gg = getList(nu2wq);
    // printf("%d ", gg->val);
    //  printf("%d ", gg->next->val);
    //   printf("%d ", gg->next->next->val);
}
