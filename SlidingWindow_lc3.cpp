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
    //2022年3月2日，路西法的方法，有小细节不好理解。
    int lengthOfLongestSubstring2(string s) {
        int w无重复字符的最长子串长度 = 0;
        int q起始位置 = 0, z字符串长度 = s.size();
        unordered_map<char, int> z字符位置; //这个哈希表中保存的是每个正在被访问的字符对应的索引
        for (int i = 0; i < z字符串长度; ++i) {
            //如果哈希表中已经存在字符了，那么就将重复字符的下一个字符作为新的子串起点
            char z正被访问字符 = s[i];
            if (z字符位置.count(z正被访问字符))
                q起始位置 = max(q起始位置, z字符位置[z正被访问字符] + 1);
                //todo 如果字符串是“abccba”，轴对称式重复，试一下就理解了。起始位置被设置为重复字符的前一个字符位置，范围扩大了。
                // q起始位置 = z字符位置[z正被访问字符] + 1;

            //如果不存在，那么当前字符对应的位置是子串的结束位置，加入哈希表中
            z字符位置[z正被访问字符] = i;
            w无重复字符的最长子串长度 = max(w无重复字符的最长子串长度, i - q起始位置 + 1);
        }
        return w无重复字符的最长子串长度;
    }

    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        unordered_map<char, int> c窗口; //值保存的是出现过的次数

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