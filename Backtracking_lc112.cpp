//
// Created by XKA on 2021/10/28. 简单 52.6
//

#include "Tree_lc94.cpp"
class Solution112 {
public:
    //第一次做，大致思路没问题，注意小技巧令代码更简洁
    bool h回溯函数(TreeNode *root, int m目标数) {
        if (root->left == nullptr && root->right == nullptr) {
            if (m目标数 == 0) //令目标数不断减去节点值，如果在叶子节点减到0，说明该路径和与目标数相等
                return true;
            else
                return false;
        }
        if (root->left != nullptr) {
            //注意形参“目标数”传的是值而不是地址，所以递归返回后“目标数”值不变，隐含了回溯时撤销选择的操作
            if (h回溯函数(root->left, m目标数 - root->left->val))
                return true;
        }
        if (root->right != nullptr) {
            if (h回溯函数(root->right, m目标数 - root->right->val))
                return true;
        }
        return false; //默认返回false，因为如果满足条件在前面的语句就返回了
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;
        int l路径总和 = 0;
        return h回溯函数(root, targetSum - root->val);
    }
};