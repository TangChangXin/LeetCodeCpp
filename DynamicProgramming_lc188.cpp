//
// Created by XK on 2022/6/14.
//
#include <vector>

using namespace std;

class Solution188 {
public:
    //基本是自己参照123想的
    int maxProfit(int k, vector<int> &prices) {
        if (prices.size() < 2) return 0;
        //DP[i][k][j]。
        //k = 0表示没有交易，k = 1表示发生了1次买入股票行为，k = 2表示发生了2次买入股票行为，以此类推。
        //j = 0表示不持有股票，j = 1表示持有股票
        vector<vector<vector<int>>> DP(prices.size(), vector<vector<int>>(k + 1, vector<int>(2)));
        //注意初始本金为0，也即利润为0。规定股票卖出后才算完成一次交易。
        for (int i = 1; i <= k; ++i) {
            DP[0][i][1] = -prices[0]; //在第0天买入了i次股票，也意味着卖出了i-1股票，因为股票可以在同一天内买入和卖出，此时利润为股价负值。
        }
        for (int i = 1; i < prices.size(); ++i) {
            for (int j = 1; j <= k; ++j) {
                DP[i][j][1] = max(DP[i - 1][j][1], DP[i - 1][j - 1][0] - prices[i]);
                DP[i][j][0] = max(DP[i - 1][j][0], DP[i - 1][j][1] + prices[i]);
            }
        }
        return DP[prices.size() - 1][k][0];
    }

    //空间优化
    int maxProfit2(int k, vector<int> &prices) {
        if (prices.size() < 2) return 0;
        //DP[i][j]。
        //i = 0表示没有交易，i = 1表示发生了1次买入股票行为，i = 2表示发生了2次买入股票行为，以此类推。j = 0表示不持有股票，j = 1表示持有股票。
        //DP[i][j]表示到目前为止，已发生了i次股票买入行为
        vector<vector<int>> DP(k + 1, vector<int>(2));
        //注意初始本金为0，也即利润为0。规定股票卖出后才算完成一次交易。
        for (int i = 1; i <= k; ++i) {
            DP[i][1] = -prices[0]; //在第0天买入了i次股票，也意味着卖出了i-1股票，因为股票可以在同一天内买入和卖出，此时利润为股价负值。
        }
        for (int i = 1; i < prices.size(); ++i) {
            for (int j = 1; j <= k; ++j) {
                //注意更新顺序，右边max表达式内的DP[j][0]或者DP[j][1]都是前一天的状态；左边的DP[j][0]或者DP[j][1]是今天的状态。
                DP[j][0] = max(DP[j][0], DP[j][1] + prices[i]);
                //如果先更新DP[j][1]的话就会覆盖昨天的DP[j][1]，然而DP[j][0]需要的是昨天的DP[j][1]。
                DP[j][1] = max(DP[j][1], DP[j - 1][0] - prices[i]);
            }
        }
        return DP[k][0];
    }
};