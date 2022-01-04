//
// Created by XKA on 2021/10/29. 中等 35.1
//
#include "Tree_lc94.cpp"
#include <vector>
#include <stack>

using namespace std;

class Solution98 {
public:
    //第一次做,可以说是完全没思路，直接看了随想录
    bool isValidBST(TreeNode *root) {
        if (root == nullptr)
            return false;
        stack<TreeNode *> m模拟递归栈;
        TreeNode *d当前节点 = root;
        vector<int> z中序遍历;
        while (d当前节点 != nullptr || !m模拟递归栈.empty()) {
            while (d当前节点 != nullptr) {
                m模拟递归栈.push(d当前节点);
                d当前节点 = d当前节点->left;
            }
            d当前节点 = m模拟递归栈.top();
            m模拟递归栈.pop();
            z中序遍历.push_back(d当前节点->val);
            d当前节点 = d当前节点->right;
        }
        for (int i = 1; i < z中序遍历.size(); ++i) {
            if (z中序遍历[i] <= z中序遍历[i - 1])
                return false;
        }

        return true;
    }
};