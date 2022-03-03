//
// Created by XKA on 2021/6/15.
//
#include "Linkedlist_lc2.cpp"
//困难 K个一组翻转链表
class Solution25 {
public:
    //2022年3月3日
    ListNode *d迭代反转链表(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *x新头节点 = nullptr;
        ListNode *d当前节点 = head;
        while (d当前节点 != nullptr) {
            ListNode *l临时节点 = d当前节点->next;
            d当前节点->next = x新头节点;
            x新头节点 = d当前节点;
            d当前节点 = l临时节点;
        }
        return x新头节点;
    }
    ListNode *d递归反转链表(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *x新头节点 = d递归反转链表(head->next);
        head->next->next = head;
        head->next = nullptr;
        return x新头节点;
    }

    //没完全想出来，看了以前的结果
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *x虚拟头节点 = new ListNode(0, head), *q前驱节点 = x虚拟头节点,*d当前节点 = x虚拟头节点;
        while (d当前节点 != nullptr) {
            for (int i = 0; i < k; ++i) {
                d当前节点 = d当前节点->next;
                if (d当前节点 == nullptr) return x虚拟头节点->next;
            }
            ListNode *d当前子链表头节点 = q前驱节点->next, *x下一子链表头节点 = d当前节点->next;
            d当前节点->next = nullptr; //断开连接
            q前驱节点->next = d迭代反转链表(d当前子链表头节点); //理解为与前一个子链表的尾结点相连
            d当前子链表头节点->next = x下一子链表头节点;
            q前驱节点 = d当前子链表头节点;
            d当前节点 = q前驱节点;
        }
        return x虚拟头节点->next;
    }
};