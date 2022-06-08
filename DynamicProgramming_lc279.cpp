//
// Created by XK on 2022/6/8.
//
#include <vector>
#include <climits>

using namespace std;

// 279. 完全平方数
class Solution279 {
public:
    //第一次直接看的题解
    int numSquares(int n) {
        vector<int> DP(n + 1, INT_MAX);
        //DP[i]表示和为i的完全平方数的最小数量。
        DP[0] = 0; //初始化，注意这里初始化为0是为了满足递推公式，实际题目并不考虑0。其余值初始化为无限大，因为要取最小值。
        //外层遍历背包容量
        for (int i = 1; i <= n; ++i) {
            //内层遍历物品
            for (int j = 1; j * j <= i; ++j) {
                DP[i] = min(DP[i], DP[i - j * j] + 1);
            }
        }
        return DP[n];
    }
};