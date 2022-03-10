//
// Created by XK on 2022/3/10.
//
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> q全排列结果;
    vector<int> p排列;

    void h回溯函数(vector<int> &nums, vector<bool> &y已使用) {
        //todo 针对这题去重有更好的方式
        if (p排列.size() == nums.size()) {
            q全排列结果.push_back(p排列);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (y已使用[i])
                continue;
            p排列.push_back(nums[i]);
            y已使用[i] = true;
            h回溯函数(nums, y已使用);
            p排列.pop_back();
            y已使用[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> y已使用(nums.size(), false);
        h回溯函数(nums, y已使用);
        return q全排列结果;
    }
};