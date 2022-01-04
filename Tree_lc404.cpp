//
// Created by XKA on 2021/10/27. 简单 58.5
//

#include <stack>
#include "Tree_lc94.cpp"

using namespace std;

class Solution404 {
public:
    //这题认为只有一个根节点的节点不算左子节点
    int z左叶子求和(TreeNode *root) {
        //递归法
        if (root == nullptr)
            return 0;
        int z左叶子值 = 0;
        int z左子树结果 = z左叶子求和(root->left);
        int y右子树结果 = z左叶子求和(root->right);
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
            z左叶子值 = root->left->val;
        return z左叶子值 + z左子树结果 + y右子树结果;
    }

    int sumOfLeftLeaves(TreeNode *root) {
        stack<TreeNode *> m模拟递归栈;
        int z左叶子之和 = 0;
        if (root != nullptr)
            m模拟递归栈.push(root);
        while (!m模拟递归栈.empty()) {
            TreeNode *j节点 = m模拟递归栈.top();
            m模拟递归栈.pop();
            if (j节点->left != nullptr && j节点->left->left == nullptr && j节点->left->right == nullptr)
                z左叶子之和 += j节点->left->val; //当前访问的节点的左子节点是叶子节点
            else {
                if (j节点->left != nullptr) m模拟递归栈.push(j节点->left);
                if (j节点->right != nullptr) m模拟递归栈.push(j节点->right);
                continue; //当前访问的节点的左子节点不是叶子节点，才将当前节点的左节点和右节点都加入“m模拟递归栈”，并直接进入下一次循环
            }
            if (j节点->right != nullptr) m模拟递归栈.push(j节点->right); //左子节点是叶子节点就只用加入右子节点
        }
        return z左叶子之和;
    }
};