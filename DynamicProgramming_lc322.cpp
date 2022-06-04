//
// Created by XKA on 2021/6/24.
//

//中等 零钱兑换
#include <vector>
using namespace std;
class Solution322 {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> DP表(amount+1, amount+1);
        DP表[0] = 0;
        int j结果;
        for (int i = 0; i < DP表.size(); ++i) {
            for (int j金额:coins) {
                int c次目标 = i-j金额;
                if (c次目标 < 0) continue;
                if (DP表[c次目标] + 1 < DP表[i]) DP表[i] = DP表[c次目标] + 1;
            }
        }

        if (DP表[amount] > amount) return -1;

        return DP表[amount];
    }
};