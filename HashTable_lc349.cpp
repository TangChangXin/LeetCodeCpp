//
// Created by XKA on 2021/8/27.
//

#include <vector>
#include <unordered_set>
using namespace std;

class Solution349 {
public:
    //第一次做，开始想用unordered_map，但是那样做似乎有点儿复杂
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //unordered_set特点是无序，数值不可重复。s数字表是nums1去重的结果。
        unordered_set<int> s数字表(nums1.begin(), nums1.end()), j结果;
        for (auto i:nums2){
            if (s数字表.find(i) != s数字表.end())
                j结果.insert(i); //结果是unordered_set类型，保证了它不会重复插入
        }
        return vector<int>(j结果.begin(), j结果.end());
    }
};