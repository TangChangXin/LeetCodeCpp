//
// Created by XKA on 2021/10/21. 简单 48.7%
//
#include <iostream>
#include <queue>
#include "Tree_lc94.cpp"
using namespace std;

class Solution111 {
public:
    //第一次做
    int minDepth(TreeNode *root) {
        int z最小深度 = 1;
        queue<TreeNode *> s树层;
        if (root == nullptr) return 0;
        s树层.push(root);

        while (!s树层.empty()) {
            int d大小 = s树层.size();
            for (int i = 0; i < d大小; ++i) {
                TreeNode *d当前节点 = s树层.front();
                s树层.pop();
                if (d当前节点->left == nullptr && d当前节点->right == nullptr) return z最小深度;
                if (d当前节点->left) s树层.push(d当前节点->left);
                if (d当前节点->right) s树层.push(d当前节点->right);
            }
            ++z最小深度;
        }
        return z最小深度;
    }
};

int main() {
    TreeNode *aaa = nullptr;
    queue<TreeNode *> abc;
    abc.push(aaa);
    if (!abc.empty())
        cout << "非空";
    return 0;
}