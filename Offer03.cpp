//
// Created by XK on 2022/3/7.
//
#include <vector>

using namespace std;

class Solution03 {
public:
    //2022年3月24日
    int findRepeatNumber2(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            // 如果“i等于nums[i]”那么不需要操作
            while (i != nums[i]) {
                //如果相等，说明重复的数字就是nums[i]
                if (nums[i] == nums[nums[i]])
                    return nums[i];
                //不相等就交换两个数字，通过不断的交换令nums[i]出现在位置i处
                swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }

    //2022年3月8日
    int findRepeatNumber(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != i) {
                //相等说明的当前访问的数字就是重复的
                if (nums[i] == nums[nums[i]])
                    return nums[i];
                swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }
};
