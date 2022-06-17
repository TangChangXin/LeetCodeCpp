//
// Created by XK on 2022/6/17.
//
#include <string>
#include <vector>
using namespace std;

//1143. 最长公共子序列
class Solution1143 {
public:
    //基本没思路看了随想录
    int longestCommonSubsequence(string text1, string text2) {
        //DP[i][j]表示text1中以下标i-1为结尾与text2中以下标j-1为结尾的最长公共子序列的长度。
        vector<vector<int>> DP(text1.size() + 1, vector<int>(text2.size() + 1));
        for (int i = 1; i <= text1.size(); ++i) {
            for (int j = 1; j <= text2.size(); ++j) {
                if (text1[i - 1] == text2[j - 1]){
                    DP[i][j] = DP[i - 1][j - 1] + 1;
                } else
                    //https://leetcode.cn/problems/longest-common-subsequence/solution/zui-chang-gong-gong-zi-xu-lie-by-leetcod-y7u0/
                    DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
            }
        }
        return DP[text1.size()][text2.size()];
    }
};