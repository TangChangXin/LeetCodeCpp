//
// Created by XK on 2022/6/13.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int 类似贪心(vector<int> &prices) {
        int d当前最小值 = prices[0], l利润 = 0;
        for (int i = 1; i < prices.size(); ++i) {
            //当前最小值保存遍历到“prices[i]”为止时的最小值；利润则保存到目前为止，最小元素右方的最大元素与最小元素的差值。
            d当前最小值 = min(d当前最小值, prices[i]);
            l利润 = max(l利润, prices[i] - d当前最小值);
        }
        return l利润;
    }

    //动态规划基本没思路，看的随想录
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 1) return 0;
        //DP[i][0]表示在第i天时不持有股票的最大利润，DP[i][1]表示在第i天时持有股票的最大利润。
        vector<vector<int>> DP(prices.size(), vector<int>(2));
        DP[0][0] = 0, DP[0][1] = -prices[0]; //最开始不持有股票利润为0，可以理解为本金。持有股票的话利润就是最开始股票价格的负值，理解为此时买入股票
        for (int i = 1; i < prices.size(); ++i) {
            DP[i][0] = max(DP[i - 1][0], DP[i - 1][1] + prices[i]);
            //注意股票只能交易一次。如果在第“i-1”天没持有股票的话说明之前的日子也没有持有股票，所以第“i”天买入股票后利润就是股票价格的负值，因为本金时0。
            DP[i][1] = max(DP[i - 1][1], -prices[i]);
        }
        return DP[prices.size() - 1][0];
    }
};