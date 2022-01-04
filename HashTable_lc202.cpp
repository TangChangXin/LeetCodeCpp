//
// Created by XKA on 2021/8/29. 简单 快乐数
//

#include <unordered_set>
using namespace std;

class Solution202 {
public:
    //第一次做基本没啥思路，如何处理循环没有想好
    int q求和(int n){
        int h和 = 0;
        while (n){
            h和 += (n%10) * (n%10); //对数字的每一位求平方再相加
            n /= 10; //去掉最一位数
        }
        return h和;
    }

    //哈希表法
    bool isHappy(int n) {
        unordered_set<int> h哈希集;
        while (1){
            n = q求和(n);
            if (n == 1) return true;
            if (h哈希集.find(n) != h哈希集.end()){
                return false;
            } else{
                h哈希集.insert(n);
            }
        }
    }

    //todo 快慢指针法
};