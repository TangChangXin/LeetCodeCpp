//
// Created by XK on 2022/3/7.
//
#include <vector>

using namespace std;

class Solution03 {
public:
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
