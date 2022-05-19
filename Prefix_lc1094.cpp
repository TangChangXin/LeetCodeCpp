//
// Created by XK on 2022/5/18.
//
#include <vector>

using namespace std;

class Solution1094 {
public:
    //https://leetcode.cn/problems/car-pooling/solution/1094-cji-hu-shuang-bai-de-chai-fen-shu-z-kpwd/
    bool carPooling(vector<vector<int>> &trips, int capacity) {
        vector<int> c乘客表(1001, 0); //根据题意最多有1001站，初始为0人。
        for (auto &p拼车表:trips) {
            //p拼车表[1]表示开始站，p拼车表[2]表示结束站。
            c乘客表[p拼车表[1]] += p拼车表[0];
            //注意这里不用“p拼车表[2]+1”是因为人是需要下车的。一般对区间[i, j]的差分操作应该是在j+1的位置减去某个值，但是乘客在j处会下车，
            // 可以理解为乘客只在[i, j-1]区间增加了，对应这里就是“p拼车表[2]”
            c乘客表[p拼车表[2]] -= p拼车表[0];
        }

        if (c乘客表[0] > capacity) // 如果最开始的上车人数大于容量直接返回false。
            return false;
        for (int i = 1; i < 1001; ++i) {
            c乘客表[i] += c乘客表[i - 1];
            if (c乘客表[i] > capacity)
                return false;
        }
        return true;
    }
};