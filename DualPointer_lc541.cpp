//
// Created by XKA on 2021/9/9. 简单 反转字符串 II 60.8%
//

#include <string>
using namespace std;

class Solution541 {
public:
    //第一次做
    string f反转(string &s, int q起始位置, int j结束位置) {
        for (int i = q起始位置, j = j结束位置; i < j; ++i, --j) {
            swap(s[i], s[j]);
        }
        return s;
    }

    string reverseStr(string s, int k) {
        int z字符串长度 = s.size();
        for (int i = 0; i < z字符串长度; i += (2 * k)) {
            if (i + k <= z字符串长度) {
                f反转(s, i, i + k - 1);
                continue; //
            }

            //剩余字符不足k个
            f反转(s, i, z字符串长度 - 1);
        }
        return s;
    }
};