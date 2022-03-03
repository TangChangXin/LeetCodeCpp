//
// Created by XKA on 2021/11/9.
//

#include <vector>
using namespace std;

class Solution53 {
public:
    //2022年3月3日,有些小瑕疵
    int z最大子数组和(vector<int>& nums) {
        int j结果 = INT_MIN, s数组和 = 0;
        for (int num : nums) {
            s数组和 += num;
            j结果 = max(j结果, s数组和);
            if (s数组和 <= 0)
                s数组和 = 0;
        }
        return j结果;
        /*
        int j结果 = INT_MIN, s数组和 = 0;
        for (int num : nums) {
            s数组和 += num;
            if (s数组和 > j结果)
                j结果 = s数组和;
            if (s数组和 <= 0)
                s数组和 = 0;
        }
        return j结果;
         */
    }

    //第一次做，看了随想录
    int maxSubArray(vector<int>& nums) {
        int z最大子序和 = INT_MIN, l临时和 = 0, s数组长度 = nums.size();
        for (int i = 0; i < s数组长度; ++i) {
            l临时和 += nums[i];
            if (l临时和 > z最大子序和)
                z最大子序和 = l临时和;
            if (l临时和 <= 0)
                l临时和 = 0;
        }
        return z最大子序和;
    }
};