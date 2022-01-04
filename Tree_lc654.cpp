//
// Created by XKA on 2021/6/15.
//
//中等 最大二叉树
#include <iostream>
#include <vector>
#include <stack>
#include "Tree_lc94.cpp"

/*
 * 给定一个不含重复元素的整数数组 nums 。一个以此数组直接递归构建的 最大二叉树 定义如下：
 * 二叉树的根是数组 nums 中的最大元素。
 * 左子树是通过数组中 最大值左边部分 递归构造出的最大二叉树。
 * 右子树是通过数组中 最大值右边部分 递归构造出的最大二叉树。
 * 返回有给定数组 nums 构建的 最大二叉树 。
 *  [3,2,1,6,0,5]
 */
class Solution654 {
public:
    TreeNode *调用额外递归函数(vector<int> &nums) {
        int c长度 = nums.size();
        return g构造结点(nums, 0, c长度);
    }

    //仔细思考每个结点是如何构造出来的，然后再不断递归构造每一个结点 时间复杂度O(n^2)
    TreeNode *g构造结点(vector<int> &s输入数组, int q起点, int z终点){
        if (q起点 >= z终点) return nullptr;

        //“w位置”表示最大值在数组中的位置,为什么初始化为0的时候会出错，初始化为"q起点"的时候运行正常
        int z最大值 = 0, w位置 = q起点;//“w位置”初始化为"q起点"，如果下述的判断最大值的语句一次也不执行时，初始化为其他值可能会出错

        //注意循环结束的边界条件与传入的参数之间的关系
        for (int i = q起点; i < z终点; ++i) {
            if (z最大值 < s输入数组[i]) {
                z最大值 = s输入数组[i];
                w位置 = i;
            }
        }

        TreeNode *g根结点 = new TreeNode(z最大值);
        g根结点->left = g构造结点(s输入数组, q起点, w位置);
        g根结点->right = g构造结点(s输入数组, w位置 + 1, z终点);
        return g根结点;
    }
};