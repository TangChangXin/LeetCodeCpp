//
// Created by XKA on 2021/7/24. 简单 合并两个有序链表 第二次做
//

#include "Linkedlist_lc2.cpp"
class Solution21 {
public:
    //2022年3月23日
    ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) return nullptr;
        ListNode *x新头节点 = new ListNode(0, nullptr), *d当前节点 = x新头节点;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val >= list2->val) {
                d当前节点->next = list2;
                list2 = list2->next;
            } else {
                d当前节点->next = list1;
                list1 = list1->next;
            }
            d当前节点 = d当前节点->next;
        }
        if (list1 == nullptr)
            d当前节点->next = list2;
        else
            d当前节点->next = list1;
        return x新头节点->next;
    }

    //迭代法
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        ListNode* x新链表 = new ListNode(0), *d当前节点 = x新链表;//前置节点
        while (l1 != nullptr && l2 != nullptr){
            if (l1->val > l2->val){
                d当前节点->next = l2;
                l2 = l2->next;
            } else{
                d当前节点->next = l1;
                l1 = l1->next;
            }
            d当前节点 = d当前节点->next;
        }
        if (l1 == nullptr) d当前节点->next = l2;
        else d当前节点->next = l1;
        return x新链表->next;
    }

    //递归法
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {

    }

    //2022年1月22日，有小瑕疵
    ListNode* h合并链表(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        ListNode *q前置节点 = new ListNode(0, nullptr), *d当前节点 = q前置节点;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                d当前节点->next = l1;
                l1 = l1->next;
            }
            else {
                d当前节点->next = l2;
                l2 = l2->next;
            }
            d当前节点 = d当前节点->next;
        }
        if (l1 == nullptr) d当前节点->next = l2;
        else d当前节点->next = l1;
        return q前置节点->next;
    }
};