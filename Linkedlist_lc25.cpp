//
// Created by XKA on 2021/6/15.
//
#include "Linkedlist_lc2.cpp"
//困难 K个一组翻转链表
class Solution25 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;//递归结束条件
        //是否需要定义一个新的函数
        ListNode *d当前结点 = head;
        int i = 0;
        while (d当前结点 != nullptr && i < k){
            d当前结点 = d当前结点->next;
        }
    }
};