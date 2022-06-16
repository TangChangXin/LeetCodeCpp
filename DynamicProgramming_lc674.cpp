//
// Created by XK on 2022/6/16.
//
#include <vector>

using namespace std;

//674. 最长连续递增序列
class Solution674 {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        //虽然可以得出正确的结果，但是超时了。其实我原来的思路就有点儿像贪心了
        //DP[i]表示以下标i结尾的最长连续递增子序列。
        vector<int> DP(nums.size(), 1);
        int z最长长度 = 1;
        for (int i = 1; i < nums.size(); ++i) {
            //相邻元素符合条件才加1
            if (nums[i] > nums[i - 1])
                DP[i] = DP[i - 1] + 1;
            z最长长度 = max(z最长长度, DP[i]);
        }

        return z最长长度;
    }

    int 弹性(vector<int> &nums) {
        //“z左边界”表示连续递增子数组的起点，i表示连续递增子数组的终点。两者之差加1就是当前连续递增子数组的长度
        int z左边界 = 0, z最长长度 = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]){
                z最长长度 = max(z最长长度, i - z左边界 + 1);
            } else
                //当前访问的元素小于等于前一个元素，那么连续递增子数组的起点就重置为当前访问元素的下标
                z左边界 = i;
        }
        return z最长长度;
    }
};