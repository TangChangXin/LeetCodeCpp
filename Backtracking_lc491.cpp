//
// Created by XKA on 2021/10/16. 中等 54.6%
//

#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution491 {
public:
    //第一次做，注意不能对数组排序后再求递增子序列
    vector<vector<int>> j结果;
    vector<int> d递增子序列;

    //2022年2月4日，没想出来
    void h回溯函数2(vector<int> &z整数数组, int q起始位置) {
        if (d递增子序列.size() > 1) {
            j结果.push_back(d递增子序列);
        }

        int y已访问[201] = {0}; //初始的全没访问过。
        for (int i = q起始位置; i < z整数数组.size(); ++i) {
            if (!d递增子序列.empty() && z整数数组[i] < d递增子序列.back() || y已访问[z整数数组[i] + 100] == 1) continue;
            d递增子序列.push_back(z整数数组[i]);
            y已访问[z整数数组[i] + 100] = 1; //记录相同元素在同一层的访问状态，循环时跳过。
            h回溯函数2(z整数数组, i + 1);
            d递增子序列.pop_back();
        }
    }

    void h回溯函数(vector<int> &nums, int s数组长度, int q起始位置, int z子序列长度) {
        if (d递增子序列.size() == z子序列长度) {
            j结果.push_back(d递增子序列);
            return;
        }

        // -100 <= nums[i] <= 100，将数字映射为“nums[i]+100”，在每一层循环内都初始化为全0，若访问过则置1。
        int y已访问[201] = {0}; //小数据用数组更好
        for (int i = q起始位置; i <= s数组长度 - z子序列长度 + d递增子序列.size(); ++i) {
            //最开始循环时“d递增子序列”是空的，下面这样判断就可以将数组第一个值加入“d递增子序列”。后序“d递增子序列”中有值了，!d递增子序列.empty()也就一直为真
            if ((!d递增子序列.empty() && nums[i] < d递增子序列.back()) || y已访问[nums[i] + 100] != 0) continue;

            d递增子序列.push_back(nums[i]);
            y已访问[nums[i] + 100] = 1;
            h回溯函数(nums, s数组长度, i + 1, z子序列长度);
            d递增子序列.pop_back();
        }

        /*
        unordered_set<int> y已访问; //将同一层内已访问的值加入这里，避免重复访问
        for (int i = q起始位置; i <= s数组长度 - z子序列长度 + d递增子序列.size(); ++i) {
            //最开始循环时“d递增子序列”是空的，下面这样判断就可以将数组第一个值加入“d递增子序列”。后序“d递增子序列”中有值了，!d递增子序列.empty()也就一直为真
            if ((!d递增子序列.empty() && nums[i] < d递增子序列.back()) || y已访问.find(nums[i]) != y已访问.end()) continue;

            d递增子序列.push_back(nums[i]);
            y已访问.insert(nums[i]);
            h回溯函数(nums, s数组长度, i + 1, z子序列长度);
            d递增子序列.pop_back();
        }
         */
    }

    vector<vector<int>> findSubsequences(vector<int> &nums) {
        int s数组长度 = nums.size(); //z子序列尾部的值
        for (int i = 2; i <= s数组长度; ++i) {
            h回溯函数(nums, s数组长度, 0, i);
        }
        return j结果;
    }

    //思路没什么问题，但是似乎超时了。感觉是递归结束后才去重导致无效搜索太多了
    void 超时了h回溯函数(vector<int> &nums, int s数组长度, int q起始位置, int z子序列长度, int z子序列尾部的值) {
        if (d递增子序列.size() == z子序列长度) {
            if (find(j结果.begin(), j结果.end(), d递增子序列) == j结果.end())
                j结果.push_back(d递增子序列); //j结果中无重复“d递增子序列”才加入
            return;
        }

        for (int i = q起始位置; i <= s数组长度 - z子序列长度 + d递增子序列.size(); ++i) {
            //当前访问的值大于或等于目前“z子序列尾部的值”时才把当前访问的值加入子序列，保证子序列是自增的
            if (nums[i] >= z子序列尾部的值) {
                d递增子序列.push_back(nums[i]);
                //以前我这里写的是下面两句，这样有错。因为在下一轮for循环里“z子序列尾部的值”不再是接收的实参的值，而是保留的上一轮循环的值。
                //z子序列尾部的值 = nums[i];
                //h回溯函数(nums, s数组长度, i + 1, z子序列长度, z子序列尾部的值);

                超时了h回溯函数(nums, s数组长度, i + 1, z子序列长度, nums[i]);
                d递增子序列.pop_back();
            } else continue;
        }
    }

};