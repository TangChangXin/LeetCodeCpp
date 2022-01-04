//
// Created by XKA on 2021/11/10.
//
#include <vector>
#include <algorithm>
using namespace std;

class Solution1005 {
public:
    //todo 注意这里的static，在下方调用的时候为什么可以不加括号
    static bool j绝对值比较(int a, int b) {
        return abs(a) > abs(b);
    }

    //第一次做直接看的随想录
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end(), j绝对值比较); //对原数组按照绝对值的大小降序排列
        int s数组长度 = nums.size();
        for (int i = 0; i < s数组长度; ++i) {
            if (nums[i] < 0 && k > 0) {
                nums[i] *= -1;
                --k;
            }
        }
        //如果剩余k是奇数才需要乘以-1
        if (k % 2 == 1)
            nums[s数组长度 - 1] *= -1;
        int s数组和 = 0;
        for (int i : nums)
            s数组和 += i;
        return s数组和;
    }
};