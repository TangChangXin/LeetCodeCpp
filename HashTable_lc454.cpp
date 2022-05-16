//
// Created by XK on 2022/5/16.
//
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        unordered_map<int, int> s数组和映射;
        int y元组数目 = 0;
        for (int i : nums1) {
            for (int j : nums2) {
                //如果键存在的话，则会增加1，如果键不存在的话则会创建一个值，值默认为0再增加1。
                ++s数组和映射[i + j];
                /*我的原来写法
                if (s数组和映射.count(i + j))
                    //如果存在以“nums1[i] + nums2[j]”的结果为键，那么对应的值加1，表示满足条件的元组出现一次。
                    s数组和映射[i + j]++;
                else
                    //当前键不存在，那么把这个键加入哈希表中，值设为1.
                    s数组和映射[i + j] = 1;
                */
            }
        }

        for (int i : nums3) {
            for (int j : nums4) {
                if (s数组和映射.count(-i - j))
                    y元组数目 += s数组和映射[-i - j];
            }
        }
        return y元组数目;
    }
};