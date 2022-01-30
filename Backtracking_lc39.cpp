//
// Created by XKA on 2021/8/24. 中等 组合总和
//

#include <vector>
#include <algorithm>
using namespace std;

class Solution39 {
public:
    //第一次做
    vector<vector<int>> z组合结果;
    vector<int> l路径;

    //2020年1月30日，注意去重
    void h回溯函数2(vector<int> &z整数数组, int m目标数, int l临时和, int q起始位置) {
        if (l临时和 == m目标数) {
            z组合结果.push_back(l路径);
            return;
        }
        if (l临时和 > m目标数) return;
        //在for循环中添加小于目标数的判断可以在不满足条件时不进入递归，而是直接进行下一次for循环，加快执行时间
        for (int i = q起始位置; i < z整数数组.size() && l临时和 + z整数数组[i] <= m目标数; ++i) {
            l临时和 += z整数数组[i];
            l路径.push_back(z整数数组[i]);
            h回溯函数2(z整数数组, m目标数, l临时和, i);
            l临时和 -= z整数数组[i];
            l路径.pop_back();
        }
    }

    void h回溯函数(vector<int> &y源数组, int m目标数, int l临时和, int q起始位置) {
        if (l临时和 == m目标数){
            z组合结果.push_back(l路径);
            return;
        }

        if (l临时和 > m目标数) return;

        int c长度 = y源数组.size();
        //开始没注意到剪枝优化，
        for (int i = q起始位置; i < c长度 && l临时和 + y源数组[i] <= m目标数; ++i) {
            l路径.push_back(y源数组[i]);
            l临时和 += y源数组[i];
            h回溯函数(y源数组, m目标数, l临时和, i);
            l路径.pop_back();
            l临时和 -= y源数组[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        h回溯函数(candidates, target, 0, 0);
        return z组合结果;
    }
};