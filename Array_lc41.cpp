//
// Created by XK on 2022/3/6.
//
#include <vector>

using namespace std;

class Solution41 {
public:
    //2022年3月6日
    int firstMissingPositive(vector<int> &nums) {
        int s数组长度 = nums.size();
        for (int i = 0; i < s数组长度; ++i) {
            //只有在[1， s数组长度]范围内的数字才用交换。负数和大于数组长度的数在哪里不用管，只要保证范围内的数在对应的位置即可
            while (nums[i] > 0 && nums[i] <= s数组长度 && nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        //再遍历一次
        for (int i = 0; i < s数组长度; ++i) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        //如果没在上面返回，说明数组中所有数字都是小于等于数组长度的。
        return s数组长度 + 1;
    }
};