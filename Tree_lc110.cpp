//
// Created by XKA on 2021/10/26. 简单 56.4%
//

#include "Tree_lc94.cpp"

using namespace std;

/* 测试用例如下时会出错。
[1,2,2,3,null,null,3,4,null,null,4]
int s树高度(TreeNode *root) {
    queue<TreeNode *> s树层;
    if (root == nullptr)
        return 0;
    else
        s树层.push(root);
    int g高度 = 0;
    while (!s树层.empty()) {
        int d大小 = s树层.size();
        for (int i = 0; i < d大小; ++i) {
            TreeNode *j节点 = s树层.front();
            s树层.pop();
            if (j节点->left != nullptr) s树层.push(j节点->left);
            if (j节点->right != nullptr) s树层.push(j节点->right);
        }
        ++g高度;
    }
    return g高度;
}

bool isBalanced(TreeNode *root) {
    if (root == nullptr) return true;
    if (abs(s树高度(root->left) - s树高度(root->right)) > 1)
        return false;
    if (root->left != nullptr)
        isBalanced(root->left);
    if (root->right != nullptr)
        isBalanced(root->right);
    return true;
}
 */

class Solution110 {
public:
    //开始做错了，后来看了随想录。这题定义叶子节点的高度为1
    int g高度(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int z左子树高度 = g高度(root->left);
        if (z左子树高度 == -1)
            return -1;
        int y右子树高度 = g高度(root->right);
        if (y右子树高度 == -1)
            return -1;
        if (abs(z左子树高度 - y右子树高度) > 1)
            return -1;
        else
            return max(z左子树高度, y右子树高度) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (g高度(root) != -1) return true;
        else
            return false;
    }
};

