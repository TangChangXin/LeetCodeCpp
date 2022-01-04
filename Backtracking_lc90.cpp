//
// Created by XKA on 2021/10/6.
//

#include <vector>
#include <algorithm>
using namespace std;

class Solution90 {
public:
    vector<vector<int>> j结果;
    vector<int> z子集;

    //看了随想录
    void h回溯函数(vector<int> &nums, int s数组长度, int q起始位置) {
        j结果.push_back(z子集); //注意子集问题需要取树的所有节点，组合和分割问题则只是需要取叶子节点的结果

        //每次遍历时，起始位置的改变实际就是子集长度的改变，不需要像以前那样额外确定子集的大小，再在固定的子集大小内循环
        for (int i = q起始位置; i < s数组长度; ++i) {
            //去重方式有多种，这里采用好40题类似的方法
            //这里和40题类似
            if (i > q起始位置 && nums[i] == nums[i - 1]) continue;

            //纵向递归时数字是可以重复的
            z子集.push_back(nums[i]);
            h回溯函数(nums, s数组长度, i + 1);
            z子集.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int s数组长度 = nums.size();
        sort(nums.begin(), nums.end()); //使数组升序排列，便于去除重复子集。
        h回溯函数(nums, s数组长度, 0);
        return j结果;
    }
};

/*
//2021/10/6 第一次做
void h回溯函数(vector<int> &nums, int s数组长度, int z子集大小, int q起始位置) {
    if (l路径.size() == z子集大小) {
        //这样去重效率低
        if (find(j结果.begin(), j结果.end(), l路径) == j结果.end()) {
            j结果.push_back(l路径); //“结果”中没有重复的子集时才将当前遍历的子集加入结果中
            return;
        } else return;
    }
    //传入的实参“nums”必须是升序排列
    for (int i = q起始位置; i <= s数组长度 - z子集大小 + l路径.size(); ++i) {
        l路径.push_back(nums[i]);
        h回溯函数(nums, s数组长度, z子集大小, i + 1);
        l路径.pop_back();
    }
}
 */