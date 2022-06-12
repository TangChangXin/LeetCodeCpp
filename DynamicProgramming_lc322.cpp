//
// Created by XKA on 2021/6/24.
//

//中等 零钱兑换 完全背包问题 322. 零钱兑换
#include <vector>
#include <iostream>
using namespace std;
class Solution322 {
public:
    //2022年6月12日，没完全做出来看了随想录
    int coinChange2(vector<int>& coins, int amount) {
        // DP[j]表示凑成金额j所需最小硬币数。初始值为“amount + 1”，显然全用面值1的硬币凑目标金额时最多需要amount个，若使用其他面值则会更少，
        // “amount + 1”就比其他情况都大了，不用初始为正无穷
        vector<int> DP(amount + 1, amount + 1);
        DP[0] = 0; //注意求的是最小硬币数，凑成金额0需要0个硬币。一般来讲求最值时基本情况初始化为0是没问题的，因为在循环过程中一般会加上某个值，例如下面的加1
        //求最小值
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                if (j >= coins[i])
                    DP[j] = min(DP[j], DP[j - coins[i]] + 1);
            }
        }
        return DP[amount];
    }

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