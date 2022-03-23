//
// Created by XKA on 2021/11/9.
//

#include <vector>

using namespace std;

class Solution53 {
public:
    //2022年3月23日，动态规划
    int maxSubArray2(vector<int>& nums) {
        //TODO 注意这是子序和，不是从头到某个节点的最大和。可以从序列中截取一段的，再想想递推公式
        vector<int> z子序和表(nums.size(), 0);
        z子序和表[0] = nums[0];
        int z最大子序和 = nums[0]; //防止数组只有一个元素
        for (int i = 1; i < nums.size(); ++i) {
            //如果nums[i]比之前的子序和大，那nums[i]直接就可以当成一个子序和了；与前面的断开，从这里作为起点再次计算
            z子序和表[i] = max(z子序和表[i - 1] + nums[i], nums[i]);
            z最大子序和 = max(z最大子序和, z子序和表[i]);
        }
        return z最大子序和;
    }

    int y优化(vector<int> nums) {
        int z最大子序和 = nums[0], d当前和 = 0;
        for (int & num : nums) {
            d当前和 = max(d当前和 + num, num);
            z最大子序和 = max(z最大子序和, d当前和);
        }
        return z最大子序和;
    }

    //动态规划优化
    int y优化动态规划(vector<int> &nums) {
        int j结果 = nums[0], s数组和 = 0;
        for (int s数字: nums) {
            s数组和 = max(s数组和 + s数字, s数字);
            j结果 = max(j结果, s数组和);
        }
        return j结果;
    }

    //动态规划的方法
    int d动态规划(vector<int> &nums) {
        vector<int> d动态规划表(nums.size());
        d动态规划表[0] = nums[0];
        int z最大值 = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            d动态规划表[i] = max(d动态规划表[i - 1] + nums[i], nums[i]);
            z最大值 = max(z最大值, d动态规划表[i]);
            //if (d动态规划表[i] > z最大值)
            //z最大值 = d动态规划表[i];
        }
        return z最大值;
    }

    //2022年3月3日,有些小瑕疵
    int z最大子数组和(vector<int> &nums) {
        int j结果 = INT_MIN, s数组和 = 0;
        for (int num: nums) {
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
    int maxSubArray(vector<int> &nums) {
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