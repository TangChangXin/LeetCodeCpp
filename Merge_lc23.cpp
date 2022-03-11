//
// Created by XK on 2022/3/10.
//
#include <vector>
#include "Linkedlist_lc2.cpp"
using namespace std;

class Solution {
public:
    //升序合并两个链表
    ListNode *h合并链表(ListNode *list1, ListNode *list2) {
        ListNode *x新头节点 = new ListNode(0), *d当前节点 = x新头节点;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val > list2->val) {
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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //如何用递归实现分治 归并？
        if (lists.size() == 0)
            return nullptr;
        int j间隔 = 1; //每次归并之后，保存的头节点对应的索引逐渐倍增。
        while (j间隔 < lists.size()) {
            //"间隔"*2则到了下一组待归并链表的起点
            for (int i = 0; i + j间隔 < lists.size(); i += (j间隔*2)) {
                lists[i] = h合并链表(lists[i], lists[i + j间隔]);
            }
            j间隔 <<= 1; //间隔乘2，左移更快
        }
        return lists[0];
    }

    // https://leetcode-cn.com/problems/merge-k-sorted-lists/solution/c-fei-di-gui-fen-zhi-you-hua-kai-xiao-by-aw9o/1073333
    ListNode *t题解(vector<ListNode *> &lists) {
        if (lists.size() == 0)
            return nullptr;
        //双指针，从首尾向中间遍历并合并
        int z左指针 = 0, y右指针 = lists.size() - 1;
        while (true) {
            while (z左指针 <= y右指针) {
                if (z左指针 == y右指针)
                    break;
                lists[z左指针] = h合并链表(lists[z左指针], lists[y右指针]);
                ++z左指针, --y右指针; //每次循环结束后右指针应该指向中间
            }
            if (y右指针 == 0)
                break;
            z左指针 = 0; //左指针重置为0，开始下一次的拼接
        }
        return lists[0];
    }
};