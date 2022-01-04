//
// Created by XKA on 2021/7/13.
//

//中等 字符串的排列
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class Solution567 {
public:
    bool checkInclusion(string s1, string s2) {
        //无序哈希表
        /*原来自己的写法
        unordered_map<char, int> s1统计, c窗口;
        for (char c : s1) ++s1统计[c];//统计s1中每个字符出现的次数

        int z左边界 = 0, y右边界 = 0;
        int s1长度 = s1.size();
        int c存在性 = 0;
        unordered_map<char, int> b标志;

        //开始扩展窗口。“s2.size()”是一个无符号的数，所以前面加一个(int)转换类型
        while (y右边界 < s2.size()){
            char y移入窗口字符 = s2[y右边界];
            //如果“移入窗口的字符”存在于s1中
            if (s1统计.count(y移入窗口字符)){
                ++c窗口[y移入窗口字符];
                if (c窗口[y移入窗口字符] <= s1统计[y移入窗口字符]) ++b标志[y移入窗口字符];
            }
            ++y右边界;
            //何时开始缩短左边界？可以这样判断吗
            while (b标志 == s1统计){
                int c窗口长度 = y右边界-z左边界;
                if (c窗口长度 == s1长度) return true;//当前窗口满足条件就直接返回了
                char y移出窗口字符 = s2[z左边界];
                if (s1统计.count(y移出窗口字符)){
                    if (c窗口[y移出窗口字符]>=0 && c窗口[y移出窗口字符] <= s1统计[y移出窗口字符]) --b标志[y移出窗口字符];
                    --c窗口[y移出窗口字符];
                }
                ++z左边界;
            }
        }*/
//        string s1, string s2
        unordered_map<char, int> s1统计, c窗口;
        for (char c : s1) ++s1统计[c];//统计s1中每个字符出现的次数
        int z左边界 = 0, y右边界 = 0, b标志 = 0;

        while (y右边界 < s2.size()){
            char y移入窗口字符 = s2[y右边界];

            if (s1统计.count(y移入窗口字符)){
                ++c窗口[y移入窗口字符];
                //标志表示s1的字符在窗口中的存在性和数量。标志每增加1表示当前窗口中存在一种s1中的字符且在窗口中的数量和在s1中的数量相同。
                if (c窗口[y移入窗口字符] == s1统计[y移入窗口字符]) ++b标志;
            }
            ++y右边界;

            //开始收缩左边界。满足题目条件的时候窗口长度和s1的长度必然相同，所以当“y右边界 - z左边界”大于或等于“s1长度”时，只要右边界向右移动一个位置，左边界就要同步向左移动一个位置。
            //所以不需要先一直移动右边界直到当前窗口出现满足条件的字符串再移动左边界，这样效率低。
            while (y右边界 - z左边界 >= s1.size()){
                if (b标志 == (int)s1统计.size()) return true;
                char y移出窗口的字符 = s2[z左边界];
                if (s1统计.count(y移出窗口的字符)){
                    //假设待移出的字符存在于s1中且数量相等，那么当它被移出的时候数量就不相等了，所以标志要减1
                    if (c窗口[y移出窗口的字符] == s1统计[y移出窗口的字符]) --b标志;
                    --c窗口[y移出窗口的字符];
                }
                ++z左边界;
            }
        }

        return false;//默认是找不到的，找的到在循环中就直接返回了
    }
};

bool checkInclusion(string s1, string s2) {
    //无序哈希表
    unordered_map<char, int> s1统计, c窗口;
    for (char c : s1) ++s1统计[c];//统计s1中每个字符出现的次数

    int z左边界 = 0, y右边界 = 0;
    int s1长度 = s1.size();
    unordered_map<char, int> b标志;

    //开始扩展窗口。“s2.size()”是一个无符号的数，所以前面加一个(int)转换类型
    while (y右边界 < s2.size()){
        char y移入窗口字符 = s2[y右边界];
        //如果“移入窗口的字符”存在于s1中
        if (s1统计.count(y移入窗口字符)){
            ++c窗口[y移入窗口字符];
            if (c窗口[y移入窗口字符] <= s1统计[y移入窗口字符]) ++b标志[y移入窗口字符];
        }
        ++y右边界;
        //何时开始缩短左边界？可以这样判断吗
        while (b标志 == s1统计){
            int c窗口长度 = y右边界-z左边界;
            if (c窗口长度 == s1长度) return true;//当前窗口满足条件就直接返回了
            char y移出窗口字符 = s2[z左边界];
            if (s1统计.count(y移出窗口字符)){
                if (c窗口[y移出窗口字符]>=0 && c窗口[y移出窗口字符] <= s1统计[y移出窗口字符]) --b标志[y移出窗口字符];
                --c窗口[y移出窗口字符];
            }
            ++z左边界;
        }
    }

    return false;//默认是找不到的，找的到在循环中就直接返回了
}

int main(){
    string s1 = "adc", s2 = "dcda";
//    unordered_map<char, int> a1, a2;
////    string s1 = "abcdabc";
//    a1['a'] = 2;
//    a1['b'] = 1;
//    a2['b'] = 1;
//    a2['a'] = 2;
//    cout << (a1 == a2) << endl;
    return 0;
}