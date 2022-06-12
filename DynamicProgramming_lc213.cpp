//
// Created by XK on 2022/6/12.
//
#include <vector>

using namespace std;

class Solution213 {
public:
    //开始没啥思路，直接看的随想录。
    int t偷窃金额(vector<int> &nums, int q起点, int z终点) {
        if (q起点 == z终点) return nums[q起点];
        vector<int> DP(nums.size());
        //起点对应的值是DP表的基本情况
        DP[q起点] = nums[q起点], DP[q起点 + 1] = max(nums[q起点], nums[q起点 + 1]);
        //从起点+2开始遍历，这样减2之后才能取到基本情况的值
        for (int i = q起点 + 2; i <= z终点; ++i) {
            DP[i] = max(DP[i - 2] + nums[i], DP[i - 1]);
        }
        return DP[z终点];
    }

    int rob(vector<int> &nums) {
        if (nums.size() == 1)
            return nums[0];
        //这里划分为两种偷窃方法：1.偷第一间房屋和倒数第二间房屋。 2.偷第二间房屋和最后一间房屋。
        int j金额1 = t偷窃金额(nums, 0, nums.size() - 2);
        int j金额2 = t偷窃金额(nums, 1, nums.size() - 1);
        return max(j金额1, j金额2);
    }
};