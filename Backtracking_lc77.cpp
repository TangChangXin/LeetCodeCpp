//
// Created by XKA on 2021/8/22. 中等 组合
//

#include <vector>
using namespace std;
class Solution77 {
public:
    vector<vector<int>> j结果;
    vector<int> l路径;
    //2022年1月29日

    //没有剪枝的回溯法  第一次做
    void h回溯函数(int n, int k, int q起始数字){
        if (l路径.size() == k){
            j结果.push_back(l路径); //当前的路径中已经包含了满足条件的k个数，将路径加入结果中。
            return;//进入下一次递归
        }

        for (int i = q起始数字; i <= n; ++i) {
            l路径.push_back(i); //将当前访问的数字加入到路径数组中。
            h回溯函数(n, k, i+1);
            l路径.pop_back(); //撤销做出的选择
        }
    }

    //剪枝的回溯法  第一次做
    void j剪枝回溯(int n, int k, int q起始数字){
        if (l路径.size() == k){
            j结果.push_back(l路径); //当前的路径中已经包含了满足条件的k个数，将路径加入结果中。
            return;//进入下一次递归
        }

        //从起始数字开始，如果剩余元素个数不满足我们需要的元素个数，不必再继续搜索
        for (int i = q起始数字; i <= n-(k-l路径.size())+1; ++i) {
            l路径.push_back(i); //将当前访问的数字加入到路径数组中。
            h回溯函数(n, k, i+1);
            l路径.pop_back(); //撤销做出的选择
        }
    }

    vector<vector<int>> combine(int n, int k) {
        j结果.clear(); // 可以不写
        l路径.clear();   // 可以不写
        h回溯函数(n, k, 1);
        return j结果;
    }
};