//
// Created by XK on 2021/5/30.
//

#include <iostream>

using namespace std;

//中等 两数相加
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
*/
class Solution2 {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr && l2 == nullptr) return nullptr;

        ListNode *h和的前置结点 = new ListNode(0), *d当前结点 = h和的前置结点;
        int j加数1, j加数2, l临时和, j进位 = 0; //如果不用这两个临时变量来存储l1和l2的值，那么当l1或者l2为空时，引用l1或者l2就会出错。
        while (l1 != nullptr || l2 != nullptr || j进位 != 0) {
            if (l1 == nullptr) j加数1 = 0;
            else {
                j加数1 = l1->val;
                l1 = l1->next;
            }

            if (l2 == nullptr) j加数2 = 0;
            else {
                j加数2 = l2->val;
                l2 = l2->next;
            }

            l临时和 = (j加数1 + j加数2 + j进位) % 10; //对10取余得当前结点的值。
            j进位 = (j加数1 + j加数2 + j进位) / 10; //对10取整得进位的值。
            d当前结点->next = new ListNode(l临时和); //
            d当前结点 = d当前结点->next;
        }
        return h和的前置结点->next;
    }
};

