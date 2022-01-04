//
// Created by XKA on 2021/10/28. 简单 76.1
//

#include "Tree_lc94.cpp"

class Solution700 {
public:
    //利用二叉搜索树的性质
    TreeNode *searchBST(TreeNode *root, int val) {
        //迭代法,时间和空间表现更好
        while (root != nullptr) {
            if (root->val == val)
                return root;
            else if (root->val < val)
                root = root->right;
            else
                root = root->left;
        }
        return nullptr;
    }

    //利用二叉搜索树的性质
    TreeNode *递归法(TreeNode *root, int val) {
        if (root == nullptr || root->val == val)
            return root;
        if (root->val < val)
            return searchBST(root->right, val);
        else
            return searchBST(root->left, val);
    }


    //第一次做，没考虑到二叉搜索树的性质
    TreeNode *直接搜索(TreeNode *root, int val) {
        if (root == nullptr || root->val == val)
            return root;
        if (root->left != nullptr) {
            TreeNode *j节点 = searchBST(root->left, val);
            if (j节点 != nullptr)
                return j节点;
        }
        if (root->right != nullptr) {
            TreeNode *j节点 = searchBST(root->right, val);
            if (j节点 != nullptr)
                return j节点;
        }

        return nullptr;
    }
};