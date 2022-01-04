//
// Created by XKA on 2021/9/16. 简单
//

#include <string>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution20 {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) return false; //奇数个括号直接返回false
        unordered_map<char, char> k括号对 = {
                {')', '('},
                {']', '['},
                {'}', '{'}
        };
        stack<char> f辅助栈;
        for (char c : s) {
            if (k括号对.count(c)) {
                //当前访问的是右括号
                if (f辅助栈.top() != k括号对[c] || f辅助栈.empty()) {
                    return false;
                }
                f辅助栈.pop(); //上面的if语句未执行，说明当前访问的括号是右括号且和辅助栈中的栈顶括号是配对的，移除栈顶括号进行下一次判读
            } else {
                f辅助栈.push(c); //左括号加入栈里
            }
        }
        return true; //默认是全部配对的
    }
};