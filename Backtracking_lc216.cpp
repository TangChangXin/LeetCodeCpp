//
// Created by XKA on 2021/8/23. 中等 组合总和 III
//

#include <vector>

using namespace std;

class Solution216 {
public:
    vector<vector<int>> j结果;
    vector<int> l路径;

    //2022年1月30日，剪枝没写好
    void h回溯函数2(int k, int n, int q起始位置, int l临时和) {
        if (l临时和 > n) return;
        if (l路径.size() == k && l临时和 == n) {
            j结果.push_back(l路径);
            return;
        }

        for (int i = q起始位置; i <= 10 - k + l路径.size(); ++i) {
            l路径.push_back(i);
            l临时和 += i;
            h回溯函数2(k, n, i + 1, l临时和);
            l路径.pop_back();
            l临时和 -= i;
        }
    }


    void h回溯函数(int k, int n, int q起始数字) {
        //终止条件，
        if (l路径.size() == k && l路径[0] + l路径[1] + l路径[2] == n) {
            j结果.push_back(l路径);
            return;
        }

        for (int i = q起始数字; i <= 9; ++i) {
            l路径.push_back(i); //做出选择
            h回溯函数(k, n, i + 1);
            l路径.pop_back(); //撤销选择
        }
    }

    void j剪枝回溯(int k, int m目标和, int q起始数字, int l临时和) {
        if (l路径.size() == k && l临时和 == m目标和) {
            j结果.push_back(l路径);
            return;
        }

        if (l临时和 > m目标和) return; //“l临时和”保存当前路径中数字的和，如果已经比“目标和”大了，那么也不需要继续搜索了。相当于剪枝

        //理解为在1到9的范围内选出k个数，那么从起始数字开始，如果剩余元素个数不满足我们需要的元素个数，不必再继续搜索
        for (int i = q起始数字; i <= 9 - (k - l路径.size()) + 1; ++i) {
            l临时和 += i; //对当前路径中已存在的数字求和
            l路径.push_back(i); //做出选择
            j剪枝回溯(k, m目标和, i + 1, l临时和);
            l临时和 -= i; //减去刚刚加入了路径中的数
            l路径.pop_back(); //撤销选择
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        //h回溯函数(k, n, 1); //没有剪枝优化的版本
        j剪枝回溯(k, n, 1, 0); //剪枝优化的版本
        return j结果;
    }
};

int main() {
    return 0;
}