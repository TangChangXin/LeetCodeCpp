//
// Created by XKA on 2021/6/18.
//

/* 中等 根据前序和后序遍历构造二叉树
 * 返回与给定的前序和后序遍历匹配的任何二叉树。
 * pre 和 post 遍历中的值是不同的正整数。
 * 输入：pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
 * 输出：[1,2,3,4,5,6,7]
 * 提示
 * 1 <= pre.length == post.length <= 30
 * pre[]和post[]都是1, 2, ..., pre.length的排列
 * 每个输入保证至少有一个答案。如果有多个答案，可以返回其中一个。
 */
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include "Tree_lc94.cpp"

class Solution889 {
public:
    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post) {
        return d递归调用函数(pre, 0, pre.size() - 1, post, 0, post.size() - 1);
    }

    TreeNode *d递归调用函数(vector<int> &q前序数组, int q前序起点, int q前序终点, vector<int> &h后序数组, int h后序起点, int h后序终点) {
        if (q前序起点 > q前序终点) return nullptr;//注意结束条件

        TreeNode *g根节点 = new TreeNode(q前序数组[q前序起点]);//"q前序数组[q前序起点]" 是根节点元素的值
        if (q前序起点 == q前序终点) return g根节点;//相等时说明没有子节点了可以直接返回，不然后面的语句会出现数组越界报错，注意和105题区别

        //因为构造的树有多个结果，为了简单起见一律将根节点后的节点当做左子节点来构造
        int z左子节点值 = q前序数组[q前序起点 + 1];
        //下面基本是套路写法
        int z左子节点在后序数组中位置 = h后序起点;
        //求出左子节点在后序数组中的位置,while循环可以避免判断边界条件
        while (z左子节点值 != h后序数组[z左子节点在后序数组中位置])
            z左子节点在后序数组中位置++;

        int q前序左子树起点 = q前序起点 + 1;//每次递归调用的时候，"q前序起点"会隐式的自加
        int q前序左子树终点 = z左子节点在后序数组中位置 - h后序起点 + q前序起点 + 1;
        int h后序左子树起点 = h后序起点;
        int h后序左子树终点 = z左子节点在后序数组中位置;

        int q前序右子树起点 = z左子节点在后序数组中位置 - h后序起点 + q前序起点 + 2;
        int q前序右子树终点 = q前序终点;
        int h后序右子树起点 = z左子节点在后序数组中位置 + 1;
        int h后序右子树终点 = h后序终点 - 1;

        g根节点->left = d递归调用函数(q前序数组, q前序左子树起点, q前序左子树终点, h后序数组, h后序左子树起点, h后序左子树终点);
        g根节点->right = d递归调用函数(q前序数组, q前序右子树起点, q前序右子树终点, h后序数组, h后序右子树起点, h后序右子树终点);

        return g根节点;
    }
};
