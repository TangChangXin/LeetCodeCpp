//
// Created by XK on 2022/6/12.
//
#include <vector>
#include <iostream>
using namespace std;

//198. 打家劫舍
class Solution198 {
public:
    //大致思路没问题，注意小细节
    int rob(vector<int> &nums) {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        int q前2 = nums[0], q前1 = max(nums[0], nums[1]), d当前金额;

        for (int i = 2; i < nums.size(); ++i) {
            d当前金额 = max(q前2 + nums[i], q前1);
            q前2 = q前1;
            q前1 = d当前金额;
        }
        return d当前金额;
        /*
        if (nums.size() == 1)
            return nums[0];
        //DP[i]偷窃到i号房屋时得到的最高金额
        vector<int> DP(nums.size());
        DP[0] = nums[0], DP[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            DP[i] = max(DP[i - 2] + nums[i], DP[i - 1]);
        }
        return DP[nums.size() - 1];
         */
    }
};