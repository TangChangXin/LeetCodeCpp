//
// Created by XK on 2022/6/10.
//
#include <vector>
#include <iostream>
using namespace std;

//377. 组合总和 Ⅳ
class Solution377 {
public:
    int combinationSum4(vector<int> &nums, int target) {
        //这题实际求的是排列有多少种结果
        //DP[j]在0到i的范围内任选数字和为j的排列数
        vector<int> DP(target + 1);
        DP[0] = 1;
        //外层遍历背包容量即目标金额
        for (int i = 0; i <= target; ++i) {
            //内层遍历物品即硬币
            for (int j: nums) {
                if (i >= j && DP[i - j] < INT_MAX - DP[i])
                    DP[i] += DP[i - j];
            }
        }
        return DP[target];
    }
};