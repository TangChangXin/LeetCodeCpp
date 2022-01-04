//
// Created by XKA on 2021/10/28. 中等 62.8
//

#include <vector>
#include "Tree_lc94.cpp"

using namespace std;


class Solution113 {
public:
    //第一次做
    vector<vector<int>> l路径总结果;
    vector<int> l路径;
    void h回溯函数(TreeNode *root, int m目标数) {
        l路径.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (m目标数 == 0) //令目标数不断减去节点值，如果在叶子节点减到0，说明该路径和与目标数相等
                l路径总结果.push_back(l路径);
            return;
        }

        if (root->left != nullptr) {
            h回溯函数(root->left, m目标数 - root->left->val);
            l路径.pop_back();
        }
        if (root->right != nullptr) {
            h回溯函数(root->right, m目标数 - root->right->val);
            l路径.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        if (root == nullptr)
            return l路径总结果;
        h回溯函数(root, targetSum - root->val);
        return l路径总结果;
    }
};