//
// Created by XKA on 2021/10/23. 中等 78.2
//


#include <iostream>
#include "Tree_lc94.cpp"

using namespace std;

class Solution222 {
public:
    //2022年2月15日
    int 位运算二分法(TreeNode* root) {
    }































    //第一次做 代码随想录的方法。 画图时每个点不只访问了一次，为什么他还说是logn呢？
    int countNodes(TreeNode *root) {
        if (root == nullptr) return 0;
        TreeNode *z左节点 = root->left;
        TreeNode *y右节点 = root->right;
        int z左节点深度 = 0, y右节点深度 = 0;

        //这方法在每次递归时会重复遍历子树，似乎效率不高
        while (z左节点!= nullptr) {
            z左节点 = z左节点->left;
            ++z左节点深度; //不断向左遍历求最大的深度
        }

        while (y右节点!= nullptr) {
            y右节点 = y右节点->right;
            ++y右节点深度; //不断向右遍历求深度。左、右深度相等则是满二叉树，不等就用二分法求节点数
        }
        if (z左节点深度 == y右节点深度)
            return (2 << z左节点深度) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }


    //官方二分法，利用位运算实现的
    int 统计节点数目(TreeNode *root) {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr) return 1;
        int s深度 = 0;
        TreeNode *j节点 = root;
        //注意是左子节点不为空时才执行，开始的时候一直出错
        while (j节点->left != nullptr) {
            ++s深度; //不断向左遍历求出最大深度，
            j节点 = j节点->left;
        }
        int z最小值 = 1 << s深度, z最大值 = (1 << (s深度 + 1)) - 1;
        while (z最小值 <= z最大值) {
            int z中间值 = (z最大值 - z最小值) / 2 + z最小值;
            if (c存在(root, s深度, z中间值)) {
                z最小值 = z中间值 + 1;
            } else
                z最大值 = z中间值 - 1;
        }
        return z最大值;
    }

    bool c存在(TreeNode *root, int s深度, int s数目) {
        //最后一层的节点数目用二进制表示时，最高位都是1，从次高位开始才不同，因此从次高位开始根据0或1判断取左节点或者右节点。
        //左边节点数小，右边节点数大，高位的二进制位是0说明它的十进制数小，所以往右移动。
        int p判断位 = 1 << (s深度 - 1); //左移“s深度 - 1”位是为了保证从次高位开始判断0或1
        TreeNode *j节点 = root;
        while (j节点 != nullptr && p判断位 > 0) {
            if ((p判断位 & s数目) == 0) {
                j节点 = j节点->left;
            } else
                j节点 = j节点->right;
            p判断位 >>= 1;
        }
        return j节点 != nullptr; //节点不为空则返回真。
    }
};

int main() {
    TreeNode t4 = TreeNode(4, nullptr, nullptr), t5 = TreeNode(5, nullptr, nullptr), t6 = TreeNode(6, nullptr, nullptr);
    TreeNode t2 = TreeNode(2, &t4, &t5), t3 = TreeNode(3, &t6, nullptr);
    //TreeNode t1 = TreeNode(1, &t2, &t3);
    TreeNode t1 = TreeNode(1, nullptr, nullptr);
    Solution222 ce;
    int a = ce.统计节点数目(&t1);
    cout << a;
    return 0;
}