//
// Created by XKA on 2021/10/20.
//

#include <vector>
#include <queue>
#include "Tree_lc94.cpp"

using namespace std;

class Solution102 {
public:
    //2022年2月10日
    vector<vector<int>> 层序遍历2(TreeNode* root) {
        vector<vector<int>> c层序遍历结果;
        if (root == nullptr) return c层序遍历结果;
        queue<TreeNode *> m每层树节点;
        m每层树节点.push(root);
        while (!m每层树节点.empty()) {
            int c长度 = m每层树节点.size();
            vector<int> d当前层遍历结果;
            for (int i = 0; i < c长度; ++i) {
                TreeNode *d当前节点 = m每层树节点.front();
                d当前层遍历结果.push_back(d当前节点->val);
                m每层树节点.pop();
                if (d当前节点->left) m每层树节点.push(d当前节点->left);
                if (d当前节点->right) m每层树节点.push(d当前节点->right);
            }
            c层序遍历结果.push_back(d当前层遍历结果);
        }
        return c层序遍历结果;
    }

    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> c层序遍历结果;
        queue<TreeNode *> s树层; //用来保存树一层的结果
        if (root != nullptr) s树层.push(root); //首先加入根结点，保证队列初始非空。

        while (!s树层.empty()) {
            int c层大小 = s树层.size();
            vector<int> d单层遍历结果;
            for (int i = 0; i < c层大小; ++i) {
                TreeNode *d当前节点 = s树层.front(); //front()返回队首元素但是不删除元素
                d单层遍历结果.push_back(d当前节点->val);
                s树层.pop(); //删除队首元素但是不返回元素
                if (d当前节点->left) s树层.push(d当前节点->left);
                if (d当前节点->right) s树层.push(d当前节点->right);
            }
            c层序遍历结果.push_back(d单层遍历结果);
        }
        return c层序遍历结果;
    }
};