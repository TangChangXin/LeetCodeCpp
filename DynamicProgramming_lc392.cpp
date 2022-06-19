//
// Created by XK on 2022/6/19.
//
#include <string>
#include <vector>
using namespace std;
//392.判断子序列
class Solution392 {
public:
    //动态规划
    bool isSubsequence(string s, string t) {
        //这题其实类似1143题，最长公共子序列。把s当成s和t的最长公共子序列。
        //DP[i][j]表示s中以下标i-1结尾和t中以下标j-1结尾的公共子序列的长度。
        vector<vector<int>> DP(s.size() + 1, vector<int>(t.size() + 1));
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= t.size(); ++j) {
                if (s[i - 1] == t[j - 1])
                    DP[i][j] = DP[i - 1][j - 1] + 1; //相同的话直接加1
                else
                    //不同的话可以理解为在s指针不变的情况下，t的指针指向前一个相同的元素时的值。
                    DP[i][j] = DP[i][j - 1];
            }
        }
        if (DP[s.size()][t.size()] == s.size()) return true;
        return false;
    }

    //双指针
    bool isSubsequence2(string s, string t) {
        int c长度s = s.size(), z指针s = 0, c长度t = t.size(), z指针t = 0;
        while (z指针s < c长度s && z指针t < c长度t) {
            //定义两个指针分别指向字符串s和t，如果当前访问的两个元素相同，则指针同时加1
            if (s[z指针s] == t[z指针t]) {
                ++z指针s;
                ++z指针t;
            } else
                //指针不同说明s中的字符还没有在t中出现，那么只移动t的指针。
                ++z指针t;
        }
        //遍历结束后s不等于s长度说明s不存在于t中。
        return z指针s == c长度s;
    }
};