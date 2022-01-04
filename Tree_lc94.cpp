//
// Created by XK on 2021/5/31.
//
//中序遍历二叉树
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//2021 10 21 第二次 左根右 没完全写出来
vector<int> 迭代法(TreeNode *root) {
    vector<int> b遍历结果;
    stack<TreeNode *> m模拟递归栈;
    if (root == nullptr) return b遍历结果;
    else m模拟递归栈.push(root);
    TreeNode *d当前节点 = root;
    while (d当前节点 != nullptr || !m模拟递归栈.empty()) {
        while (d当前节点 != nullptr) {
            m模拟递归栈.push(d当前节点->left);
            d当前节点 = d当前节点->left;
        }
        d当前节点 = m模拟递归栈.top();
        m模拟递归栈.pop();
        b遍历结果.push_back(d当前节点->val);
        d当前节点 = d当前节点->right;
    }
    return b遍历结果;
}

class Solution94 {
public:
    //迭代法
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> j结果;
        stack<TreeNode *> z暂存栈;
        TreeNode *d当前结点 = root;
        if (root == nullptr) return j结果;

        while (d当前结点 != nullptr || !z暂存栈.empty()) {
            //从根结点开始不断遍历左节点并入栈，退出循环时只能说明当前节点的左子结点为空，右子结点还未访问过，因此下方会将指针指向右子结点。
            while (d当前结点 != nullptr) {
                z暂存栈.push(d当前结点);
                d当前结点 = d当前结点->left; //访问左结点
            }
            d当前结点 = z暂存栈.top();
            j结果.push_back(d当前结点->val);
            z暂存栈.pop();
            d当前结点 = d当前结点->right;
        }
        return j结果;
    }

    vector<int> 调用递归函数法(TreeNode *root) {
        vector<int> j结果;
        z中序遍历(root, j结果);
        return j结果;
    }

    void z中序遍历(TreeNode *g根结点, vector<int> &f返回数组) {
        if (g根结点 == nullptr) return;
        z中序遍历(g根结点->left, f返回数组);
        f返回数组.push_back(g根结点->val);
        z中序遍历(g根结点->right, f返回数组);
    }
};