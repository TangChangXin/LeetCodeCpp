//
// Created by XKA on 2021/7/28.
// 简单 回文链表

#include"Linkedlist_lc2.cpp"
class Solution234 {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *m慢指针 = head, *k快指针 = head;
        while (k快指针 != nullptr && k快指针->next != nullptr) {
            m慢指针 = m慢指针->next;
            k快指针 = k快指针->next->next;
        }
        ListNode *f反转起点 = m慢指针->next;
        m慢指针->next = nullptr;

        ListNode *新头节点 = nullptr;
    }

    //递归法尝试
    ListNode *f反转链表(ListNode *t头节点){
        if (t头节点 == nullptr || t头节点->next == nullptr) {
            return t头节点;
        }
        ListNode *x新头节点 = f反转链表(t头节点->next);
        t头节点->next->next = t头节点;
        t头节点->next = nullptr;
        return x新头节点;
    }
};