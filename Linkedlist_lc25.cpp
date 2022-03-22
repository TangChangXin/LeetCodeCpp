//
// Created by XKA on 2021/6/15.
//
#include "Linkedlist_lc2.cpp"
//困难 K个一组翻转链表
class Solution25 {
public:
    //todo 返回头节点和尾节点的方法
    ListNode *reverseKGroup3(ListNode* head, int k) {
        ListNode *x虚拟头节点 =new ListNode(0, head), *q前置节点 = x虚拟头节点, *d当前节点 = x虚拟头节点;
        while (d当前节点 != nullptr) {
            for (int i = 0; i < k; ++i) {
                d当前节点 = d当前节点->next;
                if (d当前节点 == nullptr)
                    return x虚拟头节点->next; // 不足K个不用再反转了直接返回
            }
            //前置节点的下一个节点才是的当前子链表的头节点
            ListNode *x下一子链表头节点 = d当前节点->next, *f反转前子链表头节点 = q前置节点->next;
            d当前节点->next = nullptr; // 断开连接
            //前置节点连上反转后的子链表
            q前置节点->next = d迭代反转链表(f反转前子链表头节点);
            d当前节点 = f反转前子链表头节点;
            q前置节点 = d当前节点;
            q前置节点->next = x下一子链表头节点;
        }
        return x虚拟头节点->next;
    }

    ListNode* reverseKGroup2(ListNode* head, int k) {
        ListNode *x虚拟头节点 = new ListNode(0, head), *f反转前子链表头节点 = head, *q前置节点 = x虚拟头节点, *d当前节点 = x虚拟头节点;
        while (d当前节点 != nullptr) {
            for (int i = 0; i < k; ++i) {
                d当前节点 = d当前节点->next;
                if (d当前节点 == nullptr)
                    return x虚拟头节点->next;
            }
            // ListNode *f反转前子链表尾节点 = d当前节点, *x下一子链表头节点 = d当前节点->next;
            ListNode *x下一子链表头节点 = d当前节点->next;
            d当前节点->next = nullptr; // 断开子链表之间的连接
            q前置节点->next = d迭代反转链表(f反转前子链表头节点);
            q前置节点 = f反转前子链表头节点;
            d当前节点 = f反转前子链表头节点;
            f反转前子链表头节点->next = x下一子链表头节点;
            f反转前子链表头节点 = x下一子链表头节点;
        }
        return x虚拟头节点->next;
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
            d当前子链表头节点->next = x下一子链表头节点; // 子链表反转之后又连接上了后续子链表
            q前驱节点 = d当前子链表头节点;
            d当前节点 = q前驱节点;
        }
        return x虚拟头节点->next;
    }

    //2022年3月3日,只返回了头节点
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
};