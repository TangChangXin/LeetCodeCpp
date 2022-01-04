//
// Created by XK on 2021/5/30.
//

//中等 分隔链表
#include"Linkedlist_lc2.cpp"
#include <iostream>
using namespace std;

class Solution86 {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == nullptr) return nullptr;
        ListNode *x小链表头结点 = new ListNode(0), *x小指针 =x小链表头结点, *d大链表头结点 = new ListNode(0), *d大指针 = d大链表头结点;
        while (head != nullptr){
            if (head->val < x){
                x小指针->next = head;
                x小指针 = x小指针->next;
            } else{
                d大指针->next = head;
                d大指针 = d大指针->next;
            }
            head = head->next;
        }
        d大指针->next = nullptr;
        x小指针->next = d大链表头结点->next;
        return x小链表头结点->next;
    }
};