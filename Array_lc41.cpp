//
// Created by XK on 2022/3/6.
//
#include <vector>

using namespace std;

class Solution41 {
public:
    //2022年3月24日，基本没想出来
    int firstMissingPositive2(vector<int>& nums) {
        /*
         * 对于一个长度为N的数组，没出现的最小未出现正整数只在[1,N+1]中。因为如果[1,N]内的数字都出现了，那么最小未出现正整数是N+1。
         * 如果数组内全是大于N的数，那么最小未出现正整数是1。如果数组内既有负数又有大于N的数，那么最小未出现正整数在[1,N]中,可以理解为在[1,N]中
         * 本应该出现的数被其他数代替了。综上最小未出现正整数只能在[1,N+1]中
         */
        for (int i = 0; i < nums.size(); ++i) {
            //如果是负数则跳过不管，
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return nums.size() + 1;
    }

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