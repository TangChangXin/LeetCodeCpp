//
// Created by XK on 2022/1/23.
//

#include "Linkedlist_lc2.cpp"
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //有瑕疵
        ListNode *k快指针 = head, *m慢指针 = head;
        while (k快指针 != nullptr && k快指针->next != nullptr) {
            m慢指针 = m慢指针->next;
            k快指针 = k快指针->next->next;
            if (m慢指针 == k快指针) return true;
        }

        return false;
    }
};