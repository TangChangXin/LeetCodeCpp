//
// Created by XKA on 2021/9/16. 简单
//

#include <string>
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
        for (char c : s) {
            if (k括号对.count(c)) {
                 //加上“f辅助栈.empty()”的判断是为了应对第一个字符就是右括号，这样直接就返回false。但此时栈是空的，第一个不能判断。
                if (f辅助栈.top() != k括号对[c] || f辅助栈.empty())
                    return false;
                f辅助栈.pop();
            } else {
                f辅助栈.push(c);
            }
        }
        return true;
    }
};