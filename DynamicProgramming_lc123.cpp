//
// Created by XK on 2022/6/14.
//
#include <vector>

using namespace std;

class Solution123 {
public:
    //基本没思路，看的题解
    //https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/solution/dong-tai-gui-hua-by-liweiwei1419-7/
    //https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/solution/dong-tai-gui-hua-by-liweiwei1419-7/739269
    int maxProfit(vector<int> &prices) {
        //DP[i][j][k]。
        //j = 0表示没有交易，j = 1表示发生了1次买入股票行为，j = 2表示发生了2次买入股票行为。
        //k = 0表示不持有股票，k = 1表示持有股票
        vector<vector<vector<int>>> DP(prices.size(), vector<vector<int>>(3, vector<int>(2)));
        //注意初始本金为0，也即利润为0。规定股票卖出后才算完成一次交易。
        DP[0][1][1] = -prices[0]; //在第0天买入并持有股票，利润为股票价格负值。
        DP[0][1][0] = 0; //第0天买入但是没有持有股票，可以理解为买入之后又在同一天内卖出了，利润为0相当于还是本金的0。
        DP[0][2][1] = -prices[0]; //第0天买入又卖出之后完成了一次交易，继续在第0天内买入持有股票，利润为股票价格负值。
        DP[0][2][0] = 0; //在第0天连续两次买入卖出，完成了两次交易，利润为0相当于还是本金。
        for (int i = 1; i < prices.size(); ++i) {
            DP[i][1][1] = max(DP[i - 1][1][1], -prices[i]);
            DP[i][1][0] = max(DP[i - 1][1][0], DP[i - 1][1][1] + prices[i]);
            DP[i][2][1] = max(DP[i - 1][2][1], DP[i - 1][1][0] - prices[i]);
            DP[i][2][0] = max(DP[i - 1][2][0], DP[i - 1][2][1] + prices[i]);
        }
        //我这里认为股票是可以在同一天内买入又立即卖出的，所以两次交易的利润是大于等于一次交易的利润的。即使一次交易利润达到最大了，我也可以继续买入再卖出，利润加0。
        return DP[prices.size() - 1][2][0];
    }
};