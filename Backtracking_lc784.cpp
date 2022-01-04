//
// Created by XKA on 2021/10/6.
//

#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution784 {
public:
    //第一次做。todo 题解中还有很多巧妙的解法
    vector<string> j结果;
    string l路径 = "";

    void h回溯函数(string s, int q起始位置, int z字符串长度) {
        if (l路径.size() == z字符串长度) {
            j结果.push_back(l路径);
            return;
        }

        //这题和一般的排列题不同
        for (int i = q起始位置; i <= l路径.size(); ++i) {
            l路径.push_back(s[i]);
            h回溯函数(s, i + 1, z字符串长度);
            l路径.pop_back();
            //判断当前字符是否小写字母，若是则转换为大写字母，再加入路径然后进行新的路径选择
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] -= 32;
                l路径.push_back(s[i]);
                h回溯函数(s, i + 1, z字符串长度);
                l路径.pop_back();
            }
            else if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 32;
                l路径.push_back(s[i]);
                h回溯函数(s, i + 1, z字符串长度);
                l路径.pop_back();
            }
        }
    }

    vector<string> letterCasePermutation(string s) {
        int z字符串长度 = s.size();
        h回溯函数(s, 0, z字符串长度);
        return j结果;
    }
};

