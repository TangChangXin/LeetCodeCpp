//
// Created by XK on 2022/5/20.
//
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution5 {
public:
    string longestPalindrome(string s) {
        //现在考虑DP表
        if (s.size() < 2) return s; //空字符串或者只有一个字符直接返回即可
        int z字符串长度 = s.size(), q起点 = 0, z子串长度 = 1;
        vector<vector<int>> DP(z字符串长度, vector<int>(z字符串长度));
        //以子串的右边界为准开始递推遍历
        for (int y右边界 = 1; y右边界 < z字符串长度; ++y右边界) {
            //子串的右边界固定，左边界不断向右移动，这样即可选择到不同的子串。
            for (int z左边界 = 0; z左边界 < y右边界; ++z左边界) {
                //判断当前子串是否回文
                if (s[z左边界] == s[y右边界]) {
                    //若左右边界相等且长度小于等于3那么就是回文
                    if (y右边界 - z左边界 <= 2)
                        DP[z左边界][y右边界] = 1;
                    else
                        //长度大于3就需要根据去掉首尾之后的子串来判断了
                        DP[z左边界][y右边界] = DP[z左边界 + 1][y右边界 - 1];
                    if (y右边界 - z左边界 + 1 > z子串长度) {
                        z子串长度 = y右边界 - z左边界 + 1;//
                        q起点 = z左边界;
                    }
                }
            }
        }
        //substr(起点, 长度)
        return s.substr(q起点, z子串长度);
    }

    string b不超时的暴力法(string s) {
        // if (s.size())
    }
};

int main() {
    string wqe = "cbbd";
    Solution5 asd;

    cout << asd.longestPalindrome(wqe);
}