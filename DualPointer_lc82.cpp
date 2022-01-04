//
// Created by XKA on 2021/7/25. 第二次做还是没做出来
//
//中等 删除排序链表中的重复元素 II
//存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，只保留原始链表中没有重复出现的数字。
//返回同样按升序排列的结果链表。
#include"Linkedlist_lc2.cpp"

class Solution82 {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *x虚拟头节点 = new ListNode(0, head);
        ListNode *q前节点 = x虚拟头节点;
        ListNode *d当前节点 = head;

        while (d当前节点 != nullptr && d当前节点->next != nullptr){
            if (d当前节点->val != d当前节点->next->val){
                q前节点 = d当前节点;
                d当前节点 = d当前节点->next;
            } else{
                //内层循环的时候无法利用外层循环条件来进行非空判断，所以这里应该加一个
                while (d当前节点->next != nullptr && d当前节点->val == d当前节点->next->val)
                {
                    d当前节点->next = d当前节点->next->next;//注意移动“d当前节点->next”别移动“d当前节点”
                }
                d当前节点 = d当前节点->next;
                q前节点->next = d当前节点;
            }
        }
        return x虚拟头节点->next;
    }
};