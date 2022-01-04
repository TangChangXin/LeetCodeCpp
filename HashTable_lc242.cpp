//
// Created by XKA on 2021/8/27. 简单 有效字母异位词
//
#include <string>
#include <unordered_map>
using namespace std;

class Solution242 {
public:
    //第一次做，注意键值对的思想，有时候不一定非要用unordered_map
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int z字母频次表[26] = {0}; //0对应a，1对应b，依次类推
        for (auto i:s){
            ++z字母频次表[i - 'a']; //根据i和'a'的差值来判断当前是哪个字符,频次加1
        }
        for (auto i:t){
            --z字母频次表[i - 'a']; //频次减一
            if (z字母频次表[i - 'a'] < 0) return false; //如果有哪个字符的频次小于0，说明该字符的频次不一样。
        }
        return true;
    }
};