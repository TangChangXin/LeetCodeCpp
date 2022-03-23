//
// Created by XK on 2022/1/23.
//

#include "Linkedlist_lc2.cpp"
class Solution141 {
public:
    //2022年3月23日
    bool hasCycle2(ListNode *head) {
        ListNode *m慢指针 = head, *k快指针 = head;
        while (k快指针 != nullptr && k快指针->next != nullptr) {
            m慢指针 = m慢指针->next;
            k快指针 = k快指针->next->next;
            if (m慢指针 == k快指针)
                return true;
        }
        //默认没有环
        return false;
    }

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