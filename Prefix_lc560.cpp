//
// Created by XK on 2022/5/16.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    //2022年5月16日第一次做,看了labuladong的题解
    int subarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> q前缀和表; //定义一个哈希表保存每个前缀和结果出现的次数
        //数组下标0之前没有元素，认为前缀和为0，个数为1。不然会出错。
        //例如，nums = [3,...], k = 3，和nums = [1, 1, 1,...], k = 3。
        // https://leetcode.cn/problems/subarray-sum-equals-k/solution/bao-li-jie-fa-qian-zhui-he-qian-zhui-he-you-hua-ja/
        q前缀和表[0] = 1;

        int z子数组个数 = 0, q前缀和_i = 0; //"前缀和_i"表示从0到i的数字之和
        for (int i = 0; i < nums.size(); ++i) {
            q前缀和_i += nums[i];
            int q前缀和_j = q前缀和_i - k; // 原本是(q前缀和_i - q前缀和_j 等于k)。改了之后可以少写一次循环
            if (q前缀和表.count(q前缀和_j))
                //前缀和表中存在对应的键，说明有子数组和为k
                z子数组个数 += q前缀和表[q前缀和_j];
            //出现的前缀和次数加1
            q前缀和表[q前缀和_i]++;
        }
        return z子数组个数;
    }
};