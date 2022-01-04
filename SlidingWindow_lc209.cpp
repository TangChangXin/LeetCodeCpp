//
// Created by XKA on 2021/9/1.中等 长度最小的子数组
//

#include <vector>

using namespace std;

class Solution209 {
public:
    //第一次做
    int minSubArrayLen(int target, vector<int> &nums) {
        int c窗口和 = 0, z左边界 = 0, z子数组长度 = INT_MAX, y原数组长度 = nums.size();
        for (int y右边界 = 0; y右边界 < y原数组长度; ++y右边界) {
            c窗口和 += nums[y右边界];
            while (c窗口和 >= target) {
                if (y右边界 - z左边界 + 1 <= z子数组长度)
                    z子数组长度 = y右边界 - z左边界 + 1; //记录长度
                c窗口和 -= nums[z左边界]; //将左边界的元素移出窗口
                ++z左边界; //移动左边界，缩小窗口
            }
        }
        if (z子数组长度 < INT_MAX) return z子数组长度;
        else return 0;
    }
};