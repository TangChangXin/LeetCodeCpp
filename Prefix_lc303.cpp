//
// Created by XK on 2022/5/18.
//
#include <vector>

using namespace std;

class NumArray {
public:
    vector<int> q前缀和数组;

    NumArray(vector<int> &nums) {
        int c长度 = nums.size();
        q前缀和数组.resize(c长度 + 1); //加1是认为第一个前缀和为0，方便后续迭代计算
        for (int i = 0; i < c长度; ++i) {
            q前缀和数组[i + 1] = q前缀和数组[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        //q前缀和数组[i]实际只从nums[0]加到了nums[i- 1]。
        //所以 q前缀和数组[left] 加到了 nums[left-1] ， q前缀和数组[right] 加到了 nums[right-1]。
        //直接算“q前缀和数组[right] - q前缀和数组[left]”求出来的是从nums[left]+...+nums[right-1]的结果，少算了nums[right]
        return q前缀和数组[right + 1] - q前缀和数组[left];
    }
};