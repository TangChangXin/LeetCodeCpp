//
// Created by XKA on 2021/10/29. 简单 71.9
//
#include <vector>

using namespace std;

class Solution136 {
public:
    int singleNumber(vector<int> &nums) {
        int j结果 = 0;
        for (int i : nums)
            j结果 ^= i;
        return j结果;
    }
};