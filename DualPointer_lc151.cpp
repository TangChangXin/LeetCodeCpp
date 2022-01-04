//
// Created by XKA on 2021/9/10. 中等 翻转字符串里的单词
//

#include <string>
#include <iostream>
using namespace std;

class Solution151 {
public:
    //第一次做
    string f反转(string &s, int q起始位置, int j结束位置) {
        for (int i = q起始位置, j = j结束位置; i < j; ++i, --j) {
            swap(s[i], s[j]);
        }
        return s;
    }

    void q去除多余空格(string &s) {
        //即使使用原地覆盖的方式去除了一些空格，但是字符串的长度实际并没有改变，字符串的后面的空格在计算长度时依旧会被算进去，需要resize函数处理一下。
        int k快指针 = 0, m慢指针 = 0, y原长度 = s.size();
        while (k快指针 < y原长度 && s[k快指针] == ' ') ++k快指针; //去除字符串前面的空格
        //去除字符串中间的空格
        for (; k快指针 < y原长度; ++k快指针) {
            //跳过单词之间重复的空格，只保留最后一个
            if (k快指针 + 1 < y原长度 && s[k快指针] == s[k快指针 + 1] && s[k快指针] == ' ')
                continue;
            else {
                s[m慢指针] = s[k快指针];
                ++m慢指针;
            }
        }

        if (s[m慢指针 - 1] == ' ' && m慢指针 - 1 > 0)
            s.resize(m慢指针 - 1); //去除尾部的空格
        else s.resize(m慢指针); //最后一个不是空格
    }

    string reverseWords(string s) {
        q去除多余空格(s);
        int c长度 = s.size();
        f反转(s, 0, c长度 - 1); //得到一个反转后的字符串

        for (int i = 0; i < c长度; ++i) {
            int j结束位置 = i; //结束位置从前向后遍历
            while (j结束位置 < c长度 && s[j结束位置] != ' ') ++j结束位置; //遍历单词中字符
            f反转(s, i, j结束位置 - 1); //反转单词
            i = j结束位置;
        }
        return s;
    }
};

int main() {
    string s = "   the sky is blue   ";
    Solution151 abc;
    cout << abc.reverseWords(s);
    cout << 'a';
    return 0;
}