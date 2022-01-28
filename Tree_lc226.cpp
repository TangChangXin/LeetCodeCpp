//
// Created by XK on 2021/5/30.
//
//简单 翻转二叉树
#include <iostream>
#include "Tree_lc94.cpp"

using namespace std;

class Solution226 {
public:
    //2022年1月28日
    TreeNode* z直接递归翻转(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode *l临时节点 = root->left;
        root->left = z直接递归翻转(root->right);
        root->right = z直接递归翻转(l临时节点);
        return root;
    }
    //2022年1月28日
    void d递归翻转(TreeNode *g根节点) {
        if (g根节点 == nullptr) return;
        TreeNode *l临时节点 = g根节点->left;
        g根节点->left = g根节点->right;
        g根节点->right = l临时节点;
        d递归翻转(g根节点->left);
        d递归翻转(g根节点->right);
    }

    //第二次做
    TreeNode *迭代法(TreeNode *root) {
        //采用前序遍历的迭代法 根左右
        stack<TreeNode *> m模拟递归栈;
        if (root == nullptr) return root;
        else m模拟递归栈.push(root);

        while (!m模拟递归栈.empty()) {
            TreeNode *d当前节点 = m模拟递归栈.top();
            m模拟递归栈.pop();
            swap(d当前节点->left, d当前节点->right);
            if (d当前节点->right) m模拟递归栈.push(d当前节点->right);
            if (d当前节点->left) m模拟递归栈.push(d当前节点->left);
        }
        return root;
    }

    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr || (root->left)) return nullptr;
        /* 效果一样，只是无法体现出遍历顺序？
        TreeNode *l临时结点 = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = l临时结点;
        */

        TreeNode *l临时结点1 = invertTree(root->left);
        TreeNode *l临时结点2 = invertTree(root->right);
        //后序遍历，即对结点的操作放在递归调用之后。
        root->left = l临时结点2;
        root->right = l临时结点1;
        return root;
    }
};
