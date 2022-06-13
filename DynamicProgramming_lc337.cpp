//
// Created by XK on 2022/6/13.
//
#include <vector>
#include "Tree_lc94.cpp"

using namespace std;

class Solution {
public:
    vector<int> t偷窃树(TreeNode *root) {
        //使用长度为2的数组保存当前节点不偷与偷时得到的最大金额。
        if (root == nullptr) return vector<int>{0, 0}; //空节点直接返回0
        vector<int> z左子节点金额 = t偷窃树(root->left);
        vector<int> y右子节点金额 = t偷窃树(root->right);
        //对于当前节点可以选择不偷或者偷。注意当前节点不偷时其子节点也并非一定要偷，而是应该取子节点不偷或者偷的最大值。
        int b不偷 = max(z左子节点金额[0], z左子节点金额[1]) + max(y右子节点金额[0], y右子节点金额[1]);
        int t偷 = root->val + z左子节点金额[0] + y右子节点金额[0]; //当前节点偷了那么子节点只能选择不偷
        return {b不偷, t偷};
    }

    int rob(TreeNode *root) {
        vector<int> t偷窃结果 = t偷窃树(root);
        return max(t偷窃结果[0], t偷窃结果[1]);
    }
};