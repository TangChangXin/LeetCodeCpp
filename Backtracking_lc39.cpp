//
// Created by XKA on 2021/8/24. 中等 组合总和
//

#include <vector>

using namespace std;

class Solution39 {
public:
    //第一次做
    vector<vector<int>> z组合结果;
    vector<int> l路径;
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
        h回溯函数(candidates, target, 0, 0);
        return z组合结果;
    }
};