//
// Created by XK on 2022/6/18.
//
#include <vector>
#include <algorithm>
using namespace std;
//53. 最大子数组和
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //DP[i]表示以下标i为结尾的连续子数组的最大和
        vector<int> DP(nums.size());
        DP[0] = nums[0];
        int z最大值 = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            //对DP[i]而言，它可以由DP[i-1]+nums[i]构成，但是如果nums[i]本身就大于前者那么nums[i]自己就可以作为一个新的子数组起点往后继续计算。
            DP[i] = max(DP[i - 1] + nums[i], nums[i]);
            z最大值 = max(z最大值, DP[i]);
        }
        return z最大值;
    }
};