//
// Created by XKA on 2021/6/12.
//
//后序遍历二叉树 左右根
#include <iostream>
#include <vector>
#include <stack>
#include "Tree_lc94.cpp"

class Solution145 {
public:
    //2022年2月9日
    void d递归法后序(TreeNode *g根节点, vector<int> &h后序结果) {
        if (g根节点 == nullptr) return;
        d递归法后序(g根节点->left, h后序结果);
        d递归法后序(g根节点->right, h后序结果);
        h后序结果.push_back(g根节点->val);
    }

    //2022年2月9日
    vector<int> d迭代法后序(TreeNode *g根节点) {
        vector<int> j结果;
        if (g根节点 == nullptr) return j结果;
        stack<TreeNode *> m模拟栈;
        m模拟栈.push(g根节点);
        while (!m模拟栈.empty()) {
            TreeNode *d当前节点 = m模拟栈.top();
            j结果.push_back(d当前节点->val);
            m模拟栈.pop();
            if (d当前节点->left) m模拟栈.push(d当前节点->left);
            if (d当前节点->right) m模拟栈.push(d当前节点->right);
        }
        reverse(j结果.begin(),  j结果.end());
        return j结果;
    }

















    // 采用根右左的方式遍历树并保存到暂存栈1中，然后暂存栈1元素出栈再压入到暂存栈2中。此时暂存栈2中的顺序即为左右根
    // 暂存栈2再出栈并保存到返回数组，这样遍历得到的数组就是后序的左右根。看的哪个题解搞忘了。
    vector<int> 双栈法(TreeNode *root) {
        if (root == nullptr) return {};
        vector<int> j结果;
        stack<TreeNode *> z暂存栈1, z暂存栈2;
        z暂存栈1.push(root);
        while (!z暂存栈1.empty()){
            TreeNode *d当前结点 = z暂存栈1.top();
            z暂存栈2.push(d当前结点);
            z暂存栈1.pop();
            if (d当前结点->left) z暂存栈1.push(d当前结点->left);
            if (d当前结点->right) z暂存栈1.push(d当前结点->right);
        }
        while (!z暂存栈2.empty()){
            TreeNode *d当前结点 = z暂存栈2.top();
            j结果.push_back(d当前结点->val);
            z暂存栈2.pop();
        }
        return j结果;
    }

    //将先序遍历的根左右调整为根右左，然后将得到的结果数组翻转，得到的就是左右根数组
    vector<int> 翻转法(TreeNode *root) {
        vector<int> b遍历结果;
        stack<TreeNode *> m模拟递归栈;
        if (root == nullptr)
            return b遍历结果;
        else m模拟递归栈.push(root);

        while (!m模拟递归栈.empty()) {
            TreeNode *d当前节点 = m模拟递归栈.top(); //取栈顶元素
            m模拟递归栈.pop(); //移除栈顶元素
            b遍历结果.push_back(d当前节点->val);
            if (d当前节点->left) m模拟递归栈.push(d当前节点->left); //注意这里，左子结点后访问就先入栈
            if (d当前节点->right) m模拟递归栈.push(d当前节点->right); //右子结点先访问就后入栈
        }
        reverse(b遍历结果.begin(), b遍历结果.end());
        return b遍历结果;
    }

    vector<int> d调用递归法(TreeNode *root) {
        vector<int> j结果;
        h后序遍历(root, j结果);
        return j结果;
    }

    void h后序遍历(TreeNode *g根结点, vector<int> &f返回结果) {
        if (g根结点 == nullptr)return;
        h后序遍历(g根结点->left, f返回结果);
        h后序遍历(g根结点->right, f返回结果);
        f返回结果.push_back(g根结点->val);
    }
};