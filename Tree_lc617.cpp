//
// Created by XKA on 2021/10/28. 简单 78.8
//

#include <iostream>
#include "Tree_lc94.cpp"

using namespace std;

class Solution617 {
public:
    //第一次做 假设默认返回root1，遍历两个节点，然后即使root1空节点也将两者的节点作为root1的节点
    //没完全做出来，看了纯指针法才算有点儿解答我的疑惑，我自己想的是直接“root1 = root2”，这样是不行的
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr)
            return root2;
        if (root2 == nullptr)
            return root1;

        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }


    void process(TreeNode **t1, TreeNode **t2) {
        if ((*t1) == nullptr && (*t2) == nullptr) return;
        if ((*t1) != nullptr && (*t2) != nullptr) {
            (*t1)->val += (*t2)->val;
        }
        if ((*t1) == nullptr && (*t2) != nullptr) {
            *t1 = *t2;
            return;
        }
        if ((*t1) != nullptr && (*t2) == nullptr) {
            return;
        }
        process(&((*t1)->left), &((*t2)->left));
        process(&((*t1)->right), &((*t2)->right));
    }

    TreeNode *调用process(TreeNode *t1, TreeNode *t2) {
        process(&t1, &t2);
        return t1;
    }
};