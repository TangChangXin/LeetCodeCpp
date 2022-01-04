//
// Created by XKA on 2021/6/18.
//

//中等 从中序与后序遍历序列构造二叉树
#include <vector>
#include <stack>
#include "Tree_lc94.cpp"

class Solution106 {
public:
    TreeNode *调用递归函数法(vector<int> &inorder, vector<int> &postorder) {
        return d递归构造树(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }

    //注意子树的起点和终点边界判断
    TreeNode *d递归构造树(vector<int> &z中序数组,int z中序起点,int z中序终点, vector<int> &h后序数组, int h后序起点, int h后序终点){
        if (h后序终点 < h后序起点) return nullptr;

        int g根节点值 = h后序数组[h后序终点];//后序遍历数组的最后一个元素是根节点值
        int g根节点位置 = z中序起点;
        while (g根节点值 != z中序数组[g根节点位置])
            g根节点位置++;

        TreeNode *g根节点 = new TreeNode(g根节点值);
        g根节点->left = d递归构造树(z中序数组, z中序起点, g根节点位置-1, h后序数组, h后序起点, g根节点位置-1-z中序起点+h后序起点);
        g根节点->right = d递归构造树(z中序数组, g根节点位置+1, z中序终点, h后序数组, g根节点位置-z中序起点+h后序起点, h后序终点-1);
        return g根节点;
    }
/*
 * postorder = [15, 10, 9, 5, 4, 8, 7, 20, 3] 后序数组 左右根
 *   inorder = [15, 9, 10, 3, 20, 5, 7, 8, 4] 中序数组 左根右
 *
 * 后序反序 = [3, 20, 7, 8, 4, 5, 9, 10, 15]  根右左
 * 中序反序 = [4, 8, 7, 5, 20, 3, 10, 9, 15]  右根左
 * 将中序反序得到右根左，将后序反序得到根右左，于是我们可以用类似105的方法来还原二叉树
 */
    TreeNode *迭代法(vector<int>& h后序数组, vector<int>& z中序数组){
        if(h后序数组.size() == 0) return nullptr;
        TreeNode *g根节点 = new TreeNode(h后序数组[h后序数组.size()-1]);//后序数组最后一个是根节点

        stack<TreeNode *> z暂存栈;
        z暂存栈.push(g根节点);

        int z最右节点位置 = z中序数组.size()-1;

        for (int i = h后序数组.size()-2; i >= 0; --i) {
            TreeNode *d当前节点 = z暂存栈.top();
            if (d当前节点->val != z中序数组[z最右节点位置]){
                //若是不相等说明在后序数组中当前节点的前一节点必是右子节点
                d当前节点->right = new TreeNode(h后序数组[i]);
                z暂存栈.push(d当前节点->right);//入栈后成为当前栈顶
            } else{
                while (!z暂存栈.empty() && z暂存栈.top()->val == z中序数组[z最右节点位置]){
                    d当前节点 = z暂存栈.top();
                    z暂存栈.pop();
                    --z最右节点位置;
                }
                d当前节点->left = new TreeNode(h后序数组[i]);
                z暂存栈.push(d当前节点->left);
            }
        }
        return g根节点;
    }
};