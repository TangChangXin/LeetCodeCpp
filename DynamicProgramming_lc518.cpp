//
// Created by XK on 2022/5/19.
//
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution518 {
public:
    //回溯法似乎会超时？
    int change(int amount, vector<int> &coins) {
        //DP[i]表示凑成金额i时硬币组合数。凑不出返回0。
        vector<int> DP(amount + 1);
        DP[0] = 1; //任何硬币都不选就可凑成0，这也是一种方案
        for (int i:coins) {
            int x选中硬币 = i;
            //容量从选中的硬币值开始遍历，不然j小于选中硬币值数组下标会出错
            for (int j = x选中硬币; j <= amount; ++j) {
                //这里看似是在遍历金额容量，实际可以理解为在重复选取同一个元素，不断累加直至接近目标金额。如果硬币数组从小到大排列就不会出现重复结果。
                DP[j] += DP[j - x选中硬币];
            }
        }
        return DP[amount];
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