//
// Created by XKA on 2021/7/28.第二次做，依旧有小问题
// 简单 相交链表

#include"Linkedlist_lc2.cpp"
class Solution160 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *z指针A = headA, *z指针B = headB;
        while (z指针A !=  z指针B){
            if (z指针A == nullptr) {
                z指针A = headB;
            } else z指针A = z指针A->next;
            if (z指针B == nullptr) {
                z指针B = headA;
            } else z指针B = z指针B->next;
        }
        return z指针A;//如果有交点那么“z指针A”或“z指针B”最终都指向交点，返回哪个都可以。若无交点，则两者都指向空。





        /*这种写法似乎有问题
        while (z指针A != nullptr || z指针B != nullptr){
            if (z指针A->val != z指针B->val) { //这里报警告，z指针A可能是空指针
                z指针A = z指针A->next;
                z指针B = z指针B->next;
            } else return z指针A;
            if (z指针A == nullptr) z指针A = headB;
            if (z指针B == nullptr) z指针B = headA;
        }
        return nullptr;
         */
    }
};