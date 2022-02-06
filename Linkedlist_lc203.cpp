//
// Created by XK on 2022/2/6.
//

#include "Linkedlist_lc2.cpp"

class Solution203 {
public:
    ListNode *removeElements(ListNode *head, int val) {
        if (head == nullptr) return nullptr; //链表可能为空
        ListNode *q前置节点 = new ListNode(0, head), *d当前节点 = q前置节点;
        while (d当前节点->next != nullptr) {
            //注意如何跳过相同值以及不相同时移动的当前节点
            if (d当前节点->next->val == val) d当前节点->next = d当前节点->next->next;
            else d当前节点 = d当前节点->next;
        }
        return q前置节点->next;
    }
};