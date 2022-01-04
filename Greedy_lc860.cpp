//
// Created by XKA on 2021/11/15.简单
//
#include <vector>
#include <iostream>
using namespace std;

class Solution860 {
public:
    //第一次做看了随想录，
    bool lemonadeChange(vector<int>& bills) {
        int w五元的数量 = 0,s十元的数量 = 0;
        for (int j金额 : bills) {
            //收到五元不用找零钱
            if (j金额 == 5)
                ++w五元的数量;
            //收到十元只需找零五元
            if (j金额 == 10) {
                if (w五元的数量 <= 0)
                    return false;
                --w五元的数量;
                ++s十元的数量;

            }
            //收到二十优先用十元和五元找零，如果十元不够才用五元
            if (j金额 == 20) {
                //有十元则优先找零十元
                if (w五元的数量 > 0 && s十元的数量 > 0) {
                    --s十元的数量;
                    --w五元的数量;
                } else if (w五元的数量 >= 3)
                    //没有十元则全找五元
                    w五元的数量 -= 3;
                else
                    return false;
            }
        }
        return true;
    }
};