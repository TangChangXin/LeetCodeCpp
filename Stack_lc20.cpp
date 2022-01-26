//
// Created by XKA on 2021/9/16. 简单
//

#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution20 {
public:
    //2022年1月25日。细节没想清楚
    bool 有效括号(string s) {
        if (s.size() % 2 == 1) return false;
        stack<char> f辅助栈;
        //判断右括号是否匹配左括号，左括号需要入栈。
        unordered_map<char, char> k括号对 = {
                {')', '('},
                {']', '['},
                {'}', '{'}
        };

        for (char c: s) {
            if (k括号对.count(c)) {
                //加上“f辅助栈.empty()”的判断是为了应对第一个字符就是右括号，这样直接就返回false。但此时栈是空的，。
                if (f辅助栈.empty() || f辅助栈.top() != k括号对[c])
                    return false;
                f辅助栈.pop();
            } else {
                f辅助栈.push(c);
            }
        }
        return f辅助栈.empty();//如果括号全匹配的话，那么栈是空的；不匹配的的话那么栈中全是左括号
    }
};