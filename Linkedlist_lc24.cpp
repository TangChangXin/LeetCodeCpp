//
// Created by XK on 2022/2/8.
//

#include "Linkedlist_lc2.cpp"

class Solution {
public:
    //大致思路没问题，但是实现细节有小问题
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *x虚拟头节点 = new ListNode(0, head), *q前驱节点 = x虚拟头节点;
        while (q前驱节点->next != nullptr && q前驱节点->next->next != nullptr) {
            ListNode  *d当前节点 = q前驱节点->next, *h后继节点 = q前驱节点->next->next;
            d当前节点->next = h后继节点->next;
            q前驱节点->next = h后继节点;
            h后继节点->next = d当前节点;
            q前驱节点 = d当前节点;
        }
        return x虚拟头节点->next;
    }
};