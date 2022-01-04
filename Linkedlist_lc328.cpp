//
// Created by XK on 2021/5/30.
//

//中等 分离奇偶链表
#include"Linkedlist_lc2.cpp"
#include <iostream>
using namespace std;

class Solution328 {
public:
    ListNode *oddEvenList(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode *j奇结点 = head, *o偶结点 = head->next, *d第一个偶结点 = head->next;
        while (o偶结点 != nullptr && o偶结点->next != nullptr) {
            j奇结点->next = j奇结点->next->next;
            o偶结点->next = o偶结点->next->next;
            j奇结点 = j奇结点->next;
            o偶结点 = o偶结点->next;
        }
        j奇结点->next = d第一个偶结点;
        return head;
    }
};