//
// Created by XKA on 2021/8/5. 中等 删除链表的倒数第 N 个结点 第二次做
//

//输入：head = [1], n = 1
//输出：[]
#include "Linkedlist_lc2.cpp"
class Solution19 {
public:
    //2022年1月27日，链表至少有一个节点，所以头结点不为空
    ListNode *题解(ListNode* head, int n) {
        //这样写无需对头节点进行额外分析。
        ListNode *q前置节点 = new ListNode(0, head), *k快指针 = q前置节点, *m慢指针 = q前置节点;
        for (int i = 0; i < n; ++i) {
            k快指针 = k快指针->next;
        }
        while (k快指针->next != nullptr) {
            k快指针 = k快指针->next;
            m慢指针 = m慢指针->next;
        }
        m慢指针->next = m慢指针->next->next;
        return q前置节点->next;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        ListNode *x虚拟头 = new ListNode(0, head), *m慢指针 = x虚拟头, *k快指针 = x虚拟头;
        for (int i = 0; i < n; ++i) {
            k快指针 = k快指针->next;
        }
        while (k快指针 != nullptr && k快指针->next != nullptr){
            m慢指针 = m慢指针->next;
            k快指针 = k快指针->next;
        }
        //循环结束后，慢指针指向倒数第N个结点的前一个节点。
        m慢指针->next = m慢指针->next->next;
        return x虚拟头->next;
    }
};