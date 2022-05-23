//
// Created by XK on 2022/5/19.
//
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution518 {
public:
/*
 * 设DP[i]表示硬币面额为i时可以凑成i的硬币组合数。其中硬币数组是给定的且假设从小到大排序的。
 * 这里究竟是DP[i-1]还是应该DP[i-coins[j]]，那么DP数组的定义是否需要改
 * DP[i] = DP[i-coins[j]] +
 */

    //回溯法不行吗
    int change(int amount, vector<int> &coins) {
        int c长度 = coins.size();
        sort(coins.begin(), coins.end()); //将硬币数组排序防止遍历目标金额时出现目标金额比硬币面值小的情况。
        vector<int> DP(c长度 + 1);
        DP[0] = 1; //初始化目标金额为0时的硬币组合数1。
    }
};



void test_CompletePack() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;
    vector<int> dp(bagWeight + 1, 0);
    for(int i = 0; i < weight.size(); i++) { // 遍历物品
        for(int j = weight[i]; j <= bagWeight; j++) { // 遍历背包容量
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            cout << dp[j] << '\t';
        }
        cout << '\n';
    }
//    cout << dp[bagWeight] << endl;
}
int main() {
    test_CompletePack();
}