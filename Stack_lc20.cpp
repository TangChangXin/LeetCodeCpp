//
// Created by XKA on 2021/9/16. 简单
//

#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution20 {
public:
    //2022年3月5日
    bool isValid(string s) {
        //默认括号是匹配的
        unordered_map<char, char> k括号对 = {
                {')', '('},
                {']', '['},
                {'}', '{'}
        };
        stack<char> f符号栈;
        //循环没想好
        for (char k括号: s) {
            //左括号入栈
            if (!k括号对.count(k括号))
                f符号栈.push(k括号);
            //如果是右括号则判断是否匹配
            else {
                //若第一个就是右括号，那么
                if (f符号栈.empty())
                    return false;
                char d当前括号 = f符号栈.top();
                f符号栈.pop();
                if (d当前括号 != k括号对[k括号])
                    return false;
            }
        }
        //全匹配的话那么栈就是空的，不匹配的话栈中只有左括号。但是上述方法不能直接返回false，比如"["，或者"{[]}["
        return f符号栈.empty();
    }


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