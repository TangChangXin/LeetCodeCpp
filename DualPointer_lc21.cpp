//
// Created by XKA on 2021/7/24. 简单 合并两个有序链表 第二次做
//

#include "Linkedlist_lc2.cpp"
class Solution21 {
public:
    //迭代法
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        ListNode* x新链表 = new ListNode(0), *d当前节点 = x新链表;//前置节点
        while (l1 != nullptr && l2 != nullptr){
            if (l1->val > l2->val){
                d当前节点->next = l2;
                l2 = l2->next;
            } else{
                d当前节点->next = l1;
                l1 = l1->next;
            }
            d当前节点 = d当前节点->next;
        }
        if (l1 == nullptr) d当前节点->next = l2;
        else d当前节点->next = l1;
        return x新链表->next;
    }

    //递归法
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
    }
};