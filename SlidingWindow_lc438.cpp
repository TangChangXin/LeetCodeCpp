//
// Created by XKA on 2021/7/13.
//

//中等 找到字符串中所有字母异位词
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution438 {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> j结果;
        if (s.empty() || p.size() > s.size()) return j结果;
        unordered_map<char, int> p统计, c窗口;
        for (char c : p) ++p统计[c];//统计字符串p中每个字符出现的次数

        int z左边界 = 0, y右边界 = 0, b标志 = 0;

        while (y右边界 < s.size()){
            char y移入窗口字符 = s[y右边界];
            if (p统计.count(y移入窗口字符)){
                ++c窗口[y移入窗口字符];
                if (c窗口[y移入窗口字符] == p统计[y移入窗口字符]) ++b标志;
            }
            ++y右边界;
            while (y右边界 - z左边界 >= p.size()){
                if (b标志 == (int)p统计.size()) j结果.push_back(z左边界);
                char y移出窗口字符 = s[z左边界];
                if (p统计.count(y移出窗口字符)){
                    if (c窗口[y移出窗口字符] == p统计[y移出窗口字符]) --b标志;
                    --c窗口[y移出窗口字符];
                }
                ++z左边界;
            }
        }
        return j结果;
    }
};