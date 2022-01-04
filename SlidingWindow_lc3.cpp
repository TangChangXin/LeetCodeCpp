//
// Created by XKA on 2021/7/16.
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//输入: s = "abcabcbb"
//输出: 3
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

//输入: s = "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是"wke"，所以其长度为 3。
//请注意，你的答案必须是 子串 的长度，"pwke"是一个子序列，不是子串。

//输入: s = ""
//输出: 0

//中等 无重复字符的最长子串
class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        unordered_map<char, int> c窗口;

        int z左边界 = 0, y右边界 = 0, c长度 = 0;
        while (y右边界 < s.size()){
            char y移入窗口的字符 = s[y右边界];
            ++y右边界;
            ++c窗口[y移入窗口的字符];//先将字符加入窗口

            //
            while (c窗口[y移入窗口的字符] > 1){
                char y移出窗口字符 = s[z左边界];
                --c窗口[y移出窗口字符];
                ++z左边界;
            }
            /*
             * 仔细想了想这样的写法是错的，如果两个相邻字符是重复的就能看出来哪里错了。
            if (c窗口.count(y移入窗口的字符)){
                while (c窗口[y移入窗口的字符] > 0){
                    --c窗口[y移入窗口的字符];
                    ++z左边界;
                }
            }
             */
            if (y右边界 - z左边界 > c长度) c长度 = y右边界 - z左边界;
        }
        return c长度;
    }
};

int main(){
    unordered_map<char, int> m1;
    string s1 = "asdfga";
    for (char c : s1) ++m1[c];
    char c1 = 'a';
    cout << m1[c1] << endl;
    cout << m1.count('a') << endl;
    cout << m1.count('q') << endl;
}