//
// Created by XKA on 2021/10/20.
//
#include <vector>
#include <queue>
#include "Tree_lc94.cpp"
using namespace std;

class Solution107 {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> c层序遍历结果;
        queue<TreeNode *> s树层;
        if (root != nullptr) s树层.push(root);

        while (!s树层.empty()) {
            int c层大小 = s树层.size();
            vector<int> d单层遍历结果;
            for (int i = 0; i < c层大小; ++i) {
                TreeNode *d当前节点 = s树层.front();
                d单层遍历结果.push_back(d当前节点->val);
                s树层.pop();
                if (d当前节点->left) s树层.push(d当前节点->left);
                if (d当前节点->right) s树层.push(d当前节点->right);
            }
            c层序遍历结果.push_back(d单层遍历结果);
        }
        reverse(c层序遍历结果.begin(), c层序遍历结果.end());
        return c层序遍历结果;
    }
};