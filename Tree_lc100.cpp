//
// Created by XKA on 2021/10/21. 简单
//

#include <stack>
#include "Tree_lc94.cpp"

using namespace std;

class Solution100 {
public:
    //第一次做 和101题很像
    bool isSameTree(TreeNode *p, TreeNode *q) {
        stack<TreeNode *> m模拟递归栈;
        m模拟递归栈.push(p);
        m模拟递归栈.push(q);

        while (!m模拟递归栈.empty()) {
            TreeNode *j节点1 = m模拟递归栈.top();
            m模拟递归栈.pop();
            TreeNode *j节点2 = m模拟递归栈.top();
            m模拟递归栈.pop();
            if (!j节点1 && !j节点2) continue; //同时为空则直接进入下一次循环
            if (!j节点1 || !j节点2 || (j节点1->val != j节点2->val)) return false;
            m模拟递归栈.push(j节点1->left);
            m模拟递归栈.push(j节点2->left);
            m模拟递归栈.push(j节点1->right);
            m模拟递归栈.push(j节点2->right);
        }
        return true;
    }
};