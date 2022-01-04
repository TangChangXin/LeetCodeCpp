//
// Created by XKA on 2021/11/9.
//

#include <vector>
using namespace std;

class Solution55 {
public:
    //第一次做基本没思路，看的随想录
    bool canJump(vector<int>& nums) {
        int s数组长度 = nums.size(), y右边界 = 0; //右边界表示访问到当前位置时，能够向右跳跃的最大位置。
        for (int i = 0; i <= y右边界; ++i) {
            y右边界 = max(y右边界, i + nums[i]);
            if (y右边界 >= s数组长度 - 1)
                return true;
            //若是右边界小于最后位置的下标，则进入下一次循环。本来我自己想的是令i = i+nums[i]，但是这样会出错。比如
            //                             [3,2,8,0,4],这样实际是可以达到最后位置的，但是我的方法把“8”跳过去了。
        }
        return false;
    }
};