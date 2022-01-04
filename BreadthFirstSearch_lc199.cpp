//
// Created by XKA on 2021/10/20. 中等 65.3%
//

#include <vector>
#include <queue>
#include "Tree_lc94.cpp"

using namespace std;

class Solution199 {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> y右视图结果;
        queue<TreeNode* > s树层;
        if (root != nullptr) s树层.push(root);

        while (!s树层.empty()) {
            int d大小 = s树层.size();
            for (int i = 0; i < d大小; ++i) {
                TreeNode *d当前节点 = s树层.front();
                if (i == d大小 - 1)
                    y右视图结果.push_back(d当前节点->val);
                s树层.pop();
                if (d当前节点->left) s树层.push(d当前节点->left);
                if (d当前节点->right) s树层.push(d当前节点->right);
            }
        }
        return y右视图结果;
    }
};