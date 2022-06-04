//
// Created by XK on 2022/6/3.
//
#include <vector>
#include <iostream>

using namespace std;

// 中等 494. 目标和
class Solution494 {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int s数组总和 = 0;
        for (int i: nums) {
            s数组总和 += i;
        }

        if (abs(target) > s数组总和 || (target + s数组总和) % 2 == 1) return 0;
        int j加法和 = (target + s数组总和) / 2;
        //DP[i][j]表示从前i个数字中选择，凑出和为j的方法数目。所以数组大小DP[nums.size() + 1][j加法和 + 1]
        vector<vector<int>> DP(nums.size() + 1, vector<int>(j加法和 + 1));
        DP[0][0] = 1; //在前0个数字中凑出和为0的方法数为1。

        for (int i = 1; i <= nums.size(); ++i) {
            //外层for循环从1开始，DP[i]表示前i个，对应nums[i-1]才当前正选择的元素，即第i个。
            int x选中数字 = nums[i-1];
            for (int j = 0; j <= j加法和; ++j) {
                if (j >= x选中数字)
                    DP[i][j] = DP[i - 1][j] + DP[i - 1][j - x选中数字];
                else
                    DP[i][j] = DP[i - 1][j];
            }
        }
        return DP[nums.size()][j加法和];
    }
};