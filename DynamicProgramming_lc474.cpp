//
// Created by XK on 2022/6/6.
//
#include <vector>
#include <string>

using namespace std;

class Solution474 {
public:
    //直接看的题解
    int findMaxForm(vector<string> &strs, int m, int n) {
        //DP[i][j][k]表示选择元素索引在0到i内的任意字符串，放入0的容量为j和1的容量为k的背包中，得到的最大子集长度。
        vector<vector<vector<int>>> DP(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1)));
        //初始化将第一个字符串放入背包时最大子集长度。
        int s数量0 = 0, s数量1 = 0;
        for (char c: strs[0]) {
            //统计第一个字符串中。
            if (c == '0') ++s数量0;
            else ++s数量1;
        }
        for (int i = 0; i <= m; ++i) {
            //遍历背包容量。
            if (i < s数量0)
                continue; //背包0的容量小于字符串中0的数量，直接进入下一次循环。
            for (int j = 0; j < n + 1; ++j) {
                if (j >= s数量1)
                    DP[0][i][j] = 1; //背包0的容量和背包1的容量同时大于等于字符串中0和1的数量才初始化为1。
            }
        }
        for (int i = 1; i < strs.size(); ++i) {
            //遍历字符串数组
            s数量0 = 0, s数量1 = 0; //每次都重置为0
            for (char c: strs[i]) {
                //统计第一个字符串中。
                if (c == '0') ++s数量0;
                else ++s数量1;
            }

            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    int b不选择 = DP[i - 1][j][k], x选择;
                    if (j >= s数量0 && k >= s数量1)
                        x选择 = DP[i - 1][j - s数量0][k - s数量1] + 1; //剩余容量同时大于等于时才能放进去
                    else
                        x选择 = DP[i - 1][j][k];
                    DP[i][j][k] = max(b不选择, x选择);
                }
            }
        }
        return DP[strs.size() - 1][m][n];
    }
};