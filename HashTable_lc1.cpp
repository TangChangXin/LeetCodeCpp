//
// Created by XKA on 2021/8/9. 简单第三次做 进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？
// c++的哈希表操作似乎比较复杂。决定不用c++做了

#include <vector>
#include <unordered_map>
using namespace std;
class Solution1 {
public:
    //2022年3月4日
    vector<int> twoSum2(vector<int>& nums, int target) {
        vector<int> j结果;
        unordered_map<int, int> w位置映射表;
        for (int i = 0; i < nums.size(); ++i) {
            if (w位置映射表.count(target - nums[i])) {
                j结果.push_back(i);
                j结果.push_back(w位置映射表[target - nums[i]]);
                break;
            } else {
                w位置映射表[nums[i]] = i;
            }
        }
        return j结果;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> j结果;
        unordered_map<int, int> h哈希表;
        int c长度 = nums.size();
        for (int i = 0; i < c长度; ++i) {
            if (h哈希表.find(target - nums[i]) != h哈希表.end()) {
                j结果.push_back(i); //说明找到了
                j结果.push_back(h哈希表[target - nums[i]]);
                break;
            }
            h哈希表[nums[i]] = i; //没找到对应的值，那么就把当前访问的键值对加入哈希表中
        }
        return j结果;
    }

    //第三次做
    vector<int> l两数之和(vector<int>& nums, int target) {
        vector<int> j结果;
        unordered_map<int, int> p匹配表;
        int c长度 = nums.size();
        for (int i = 0; i < c长度; ++i) {
            if (p匹配表.find(target - nums[i]) != p匹配表.end()) {
                j结果.push_back(i);
                j结果.push_back(p匹配表[target - nums[i]]);
                break;
            }
            p匹配表[nums[i]] = i;
        }
        return j结果;
    }
};