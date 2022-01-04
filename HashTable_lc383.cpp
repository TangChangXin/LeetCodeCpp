//
// Created by XKA on 2021/8/28. 简单 赎金信
//
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution383 {
public:
    //第一次做
    // magazine中对应字母出现的次数要大于等于ransomNote中对应字母出现的次数
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() > magazine.length()) return false; //杂志字符串比赎金信字符串短，那必不可能构成。
        //int c长度1 = ransomNote.length(), c长度2 = magazine.length();
        int z字母频次表[26] = {0}; //0对应a，1对应b，以此类推。默认频次全是0。
        for (auto i:ransomNote){
            ++z字母频次表[i - 'a'];
        }
        for (auto i:magazine){
            --z字母频次表[i - 'a'];
        }
        int p频次最大值 = INT_MIN;
        for (auto i:z字母频次表){
            if (i > p频次最大值)
                p频次最大值 = i;
        }
        if (p频次最大值 >= 1)
            return false;
        else return true;
    }

    //best-jin-xing-shi-k 的题解 链接：https://leetcode-cn.com/problems/ransom-note/solution/qiao-yong-stringrong-qi-de-cha-zhao-han-kao7r/
    bool canConstruct2(string ransomNote, string magazine) {
        for(int i = 0; i < ransomNote.size(); i++){
            int a = magazine.find(ransomNote[i]);
            if(a != -1){
                magazine[a] = '0'; //画图理解
            }else{
                return false;
            }
        }
        return true;
    }
};