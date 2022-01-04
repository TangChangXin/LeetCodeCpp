//
// Created by XKA on 2021/6/6.
//
//中等 前序遍历二叉树
#include <iostream>
#include <vector>
#include <stack>
#include "Tree_lc94.cpp"

using namespace std;

class Solution144 {
public:
    //迭代法
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> j结果;
        if (root == nullptr) return j结果;//返回一个空的数组
        stack<TreeNode *> z暂存栈;
        z暂存栈.push(root);

        while (!z暂存栈.empty()) {
            TreeNode *d当前结点 = z暂存栈.top(); //去栈顶元素
            z暂存栈.pop(); //弹出栈顶元素
            j结果.push_back(d当前结点->val);
            if (d当前结点->right) z暂存栈.push(d当前结点->right);
            if (d当前结点->left) z暂存栈.push(d当前结点->left);
        }
        return j结果;
    }

    vector<int> 调用递归函数法(TreeNode *root) {
        if (root == nullptr) return {};//返回一个空的数组
        vector<int> j结果;
        q前序遍历_递归(root, j结果);
        return j结果;
    }

    void q前序遍历_递归(TreeNode *g根结点, vector<int> &f返回数组) {
        if (g根结点 == nullptr) return;
        f返回数组.push_back(g根结点->val);
        q前序遍历_递归(g根结点->left, f返回数组);
        q前序遍历_递归(g根结点->right, f返回数组);
    }
};