//
// Created by XKA on 2021/8/24. 中等 电话号码的字母组合
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution17 {
public:
    vector<string> j结果;
    string l路径;
    //2022年1月30日，哈希表的键定义错了，开始定义成了int。没考虑空数字串的情况
    unordered_map<char, string> z字母映射表 = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
    };

    void h回溯函数2(string s数字串, int q起始位置) {
        if (l路径.size() == s数字串.size()) {
            j结果.push_back(l路径);
            return;
        }

        //本来在这个外面又套了一层循环，但实际不需要，在递归时就隐含了对数字的循环遍历。
        //for循环是对同一个集合而言，对同一集合的元素遍历。不同的数字可以说是不同的集合了，对应着不同的字母集合。
        for (char z字母: z字母映射表[s数字串[q起始位置]]) {
            l路径.push_back(z字母);
            h回溯函数2(s数字串,q起始位置 + 1);
            l路径.pop_back();
        }
    }

    //第一次做时用到的数字和字母对应表
    string y映射表[10] = {
            " ",//0
            "!",//1
            "abc",//2
            "def",//3
            "ghi",//4
            "jkl",//5
            "mno",//6
            "pqrs",//7
            "tuv",//8
            "wxyz",//9
    };

    //哈希表速度快？
    unordered_map<char, string> s数字字母映射表{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
    };

    void h回溯函数(string &s数字串, int q起始位置) {
        //终止条件。起始位置表示访问到第几个数字，从0开始。
        if (q起始位置 == s数字串.size()) {
            j结果.push_back(l路径);
            return;
        }

        /* 这个用字符数组映射的方法
        int s数字 = s数字串[q起始位置] - '0';//
        string z字母 = y映射表[s数字];
        for (auto c:z字母){
            l路径.push_back(c); //做出选择，将数字对应的字母加入路径中
            h回溯函数(s数字串, q起始位置+1); //递归遍历下一个数字
            l路径.pop_back(); //撤销选择，删除字母
        }
         */

        char s数字 = s数字串[q起始位置];
        string z字母 = s数字字母映射表.at(s数字);
        for (auto c: z字母) {
            l路径.push_back(c); //做出选择，将数字对应的字母加入路径中
            h回溯函数(s数字串, q起始位置 + 1); //递归遍历下一个数字
            l路径.pop_back(); //撤销选择，删除字母
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return j结果; //第一次做的时候没考虑到数字字符串为空的情况
        h回溯函数(digits, 0);
        return j结果;
    }
};