//
// Created by XK on 2022/6/16.
//
#include <vector>
#include <algorithm>
using namespace std;

class Solution300 {
public:
    int lengthOfLIS(vector<int> &nums) {
        //DP[i]表示以nums[i]结尾的最长子序列长度。单独的每个元素可以看成是长度为1的上升子序列，初始化为1。
        vector<int> DP(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                //保证是上升子序列
                if (nums[j] < nums[i]) {
                    //在求DP[i]之前显然已经求出了DP[0],DP[1],...,DP[i-1]。那么选择其中最长的再加上nums[i]就是所求的DP[i]
                    DP[i] = max(DP[i], DP[j] + 1);
                }
            }
        }
        //注意这里不能直接返回DP表的最后一个元素，注意对状态的定义。DP表最后一个元素仅仅表示以数组元素nums[nums.size()-1]结尾的最长子序列长度，不能说明是全局最长的。
        // 例如数组[4, 5, 6, 1, 2]对应DP表[1, 2, 3, 1, 2]
        return *max_element(DP.begin(), DP.end());
    }
};