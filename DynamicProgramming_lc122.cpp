//
// Created by XK on 2022/6/13.
//
#include <vector>

using namespace std;

class Solution122 {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 1) return 0;
        //DP[i][0]表示在第i天时不持有股票的最大利润，DP[i][1]表示在第i天时持有股票的最大利润。
        vector<vector<int>> DP(prices.size(), vector<int>(2));
        DP[0][0] = 0, DP[0][1] = -prices[0]; //最开始不持有股票利润为0，可以理解为本金。持有股票的话利润就是最开始股票价格的负值，理解为此时买入股票
        for (int i = 1; i < prices.size(); ++i) {
            DP[i][0] = max(DP[i - 1][0], DP[i - 1][1] + prices[i]);
            //注意股票可以交易多次但是只能在每次交易结束之后再进行下一次交易。
            // DP[i][1]表示第“i”天持有股票的最大利润，那么它可以由两种情况构成：
            // 1. 在第“i-1”天持有股票时的最大利润，且在第“i”天不进行交易。
            // 2. 在第“i-1”天不持有股票时的最大利润减去在第“i”天买入股票后的利润。因为在这之前可能进行了多次交易，所以当前利润不一定是初始的本金0。注意和121题的区别
            DP[i][1] = max(DP[i - 1][1], DP[i - 1][0] - prices[i]);
        }
        return DP[prices.size() - 1][0];
    }
};