//
// Created by XKA on 2021/10/21. 简单
//

#include <stack>
#include "Tree_lc94.cpp"

using namespace std;

class Solution101 {
public:
    //2022年2月12日
    bool d对称二叉树(TreeNode *z左子节点, TreeNode *y右子节点) {
        if (z左子节点 == nullptr && y右子节点 != nullptr) return false;
        else if (z左子节点 != nullptr && y右子节点 == nullptr) return false;
        else if (z左子节点 == nullptr && y右子节点 == nullptr) return true;
        else if (z左子节点->val != y右子节点->val) return false;

        bool w外侧结果 = d对称二叉树(z左子节点->left, y右子节点->right);
        bool n内侧结果 = d对称二叉树(z左子节点->right, y右子节点->left);
        return (w外侧结果 && n内侧结果); //只有外侧和内侧结果同时为真时，左子节点和右子节点才是对称的。
    }

    //第一次做 递归法
    bool s是否镜像对称(TreeNode *z左结点, TreeNode *y右结点) {
        if (z左结点 == nullptr && y右结点 != nullptr) return false;
        else if (z左结点 != nullptr && y右结点 == nullptr) return false;
        else if (z左结点 == nullptr && y右结点 == nullptr) return true;
        else if (z左结点->val != y右结点->val) return false; //经过上面的判断两个节点都非空，再取值并判断是否相等。在上面判断中取值会出现空指针错误

        //到这里说明两节点相同，下面画个图就很容易理解了
        bool w外侧比较结果 = s是否镜像对称(z左结点->left, y右结点->right);
        bool n内侧比较结果 = s是否镜像对称(z左结点->right, y右结点->left);

        return (w外侧比较结果 && n内侧比较结果); //内侧和外侧结果同时为真时才是镜像对称的。
    }

    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) return true;
        stack<TreeNode *> m模拟递归栈;
        m模拟递归栈.push(root->right);
        m模拟递归栈.push(root->left);
        while (!m模拟递归栈.empty()) {
            TreeNode *z左节点 = m模拟递归栈.top(); //第一次进入循环时，得到是根节点的左子结点
            m模拟递归栈.pop();
            TreeNode *y右节点 = m模拟递归栈.top(); //第一次进入循环时，得到是根节点的右子结点
            m模拟递归栈.pop();
            if (z左节点 == nullptr && y右节点 == nullptr) continue;
            //进过了上面的判断，左节点和右节点中有一个非空，或者两个都非空
            if (!z左节点 || !y右节点 || (z左节点->val != y右节点->val)) return false;

            m模拟递归栈.push(z左节点->left); //外侧节点入栈
            m模拟递归栈.push(y右节点->right); //外侧节点入栈
            m模拟递归栈.push(z左节点->right); //内侧节点入栈
            m模拟递归栈.push(y右节点->left); //内侧节点入栈
        }
        return true;
    }
};