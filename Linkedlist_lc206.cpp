//
// Created by XKA on 2021/8/26. 简单 反转链表
//

#include "Linkedlist_lc2.cpp"
class Solution206 {
public:
    //2022年4月4日
    ListNode* reverseList2(ListNode* head) {
        //迭代法反转链表
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *x新头节点 = nullptr;
        while (head != nullptr) {
            ListNode *l临时节点 = head->next;
            head->next = x新头节点;
            x新头节点 = head;
            head = l临时节点;
        }
        return x新头节点;
    }

    //2022年3月21日
    ListNode* d迭代法反转链表5(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *x新头节点 = nullptr;
        while (head != nullptr) {
            ListNode *l临时节点 = head->next;
            head->next = x新头节点;
            x新头节点 = head;
            head = l临时节点;
        }
        return x新头节点;
    }

    ListNode *d递归法反转链表5(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *x新头节点 = d递归法反转链表5(head->next);
        head->next->next = head;
        head->next = nullptr;
        return x新头节点;
    }

    //2022年2月25日，5分钟
    ListNode *d迭代法反转链表4(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *x新头节点 = nullptr, *d当前节点 = head;
        while (d当前节点 != nullptr) {
            ListNode *l临时节点 = d当前节点->next;
            d当前节点->next = x新头节点;
            x新头节点 = d当前节点;
            d当前节点 = l临时节点;
        }
        return x新头节点;
    }

    //3分钟
    ListNode *d递归法反转链表4(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *x新头节点 = d递归法反转链表4(head->next);
        head->next->next = head;
        head->next = nullptr;
        return x新头节点;
    }

    //2022年2月23日
    //不完全
    ListNode* d迭代法反转链表3(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *x新头节点 = nullptr, *d当前节点 = head;
        while (d当前节点 != nullptr) {
            ListNode *l临时节点 = d当前节点->next;
            d当前节点->next = x新头节点;
            x新头节点 = d当前节点;
            d当前节点 = l临时节点;
        }
        return x新头节点;
    }

    //完整的想出来了
    ListNode *d递归法反转链表3(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *x新头节点 = d递归法反转链表3(head->next);
        head->next->next = head;
        head->next = nullptr;
        return x新头节点;
    }

    //第三次做
    ListNode* d迭代法反转链表2(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head; //注意链表为空或者链表只有一个元素的情况
        ListNode *x新头节点 = nullptr, *d当前节点 = head;
        while (d当前节点 != nullptr){
            ListNode *l临时节点 = d当前节点->next; //保留当前节点和后一个节点的连接
            d当前节点->next = x新头节点; //断开当前节点与后一节点的连接，使当前节点连接前一个节点
            x新头节点 = d当前节点; //移动新头节点
            d当前节点 = l临时节点; //移动当前节点
        }
        return x新头节点;
    }

    //递归
    ListNode* d递归法反转链表2(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head; //注意递归结束条件
        ListNode *x新头节点 = d递归法反转链表2(head->next); //认为当前访问的节点后面的所有节点已经反转完了;
        head->next->next = head; //反转当前节点
        head->next = nullptr;
        return x新头节点;
    }

    //第四次做
    ListNode* d迭代法反转链表1(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *x新头节点 = nullptr, *d当前节点 = head;
        while (d当前节点 != nullptr) {
            ListNode *l临时节点 = d当前节点->next;
            d当前节点->next = x新头节点;
            x新头节点 = d当前节点;
            d当前节点 = l临时节点;
        }
        return x新头节点;
    }

    // 递归法没有完整想出来
    ListNode* d递归法反转链表1(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *x新头节点 = d递归法反转链表1(head->next);
        head->next->next = head;
        head->next = nullptr;
        return x新头节点;
    }
};