//
// Created by XKA on 2021/9/10. 简单 Offer 58 - II. 左旋转字符串 85.7%
//

#include <string>
#include <iostream>
using namespace std;

class Solution58 {
public:
    //第一次做，有点儿类似541题
    void f反转字符串(string &s, int q起始位置, int j结束位置) {
        for (int i = q起始位置, j = j结束位置; i < j; ++i, --j) {
            swap(s[i], s[j]);
        }
    }
    string reverseLeftWords(string s, int n) {
        int z字符串长度 = s.size(), s实际旋转数 = n % z字符串长度;
        /* 我自己想的，先反转整体，再反转局部，这样边界的计算比较麻烦
        f反转字符串(s, 0, z字符串长度 - 1);
        f反转字符串(s, 0, z字符串长度 - s实际旋转数 - 1);
        f反转字符串(s, z字符串长度 - s实际旋转数, z字符串长度 - 1);
         */
        f反转字符串(s, 0, s实际旋转数 - 1);
        f反转字符串(s, s实际旋转数, z字符串长度 - 1);
        f反转字符串(s, 0, z字符串长度 - 1);

        return s;
    }
};

int main() {
    string s = "asdfghjk";

    Solution58 aaa;
    cout << aaa.reverseLeftWords(s, 2);
    return 0;
}