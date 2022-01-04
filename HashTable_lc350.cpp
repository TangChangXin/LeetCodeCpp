//
// Created by XKA on 2021/8/28. 简单 两个数组的交集 II
//

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution350 {
public:
    //第一次做，没啥思路，看了题解
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            //默认第一个形参指向的数组比较短，遍历更省时。若是第二个形参指向的数组短，就重新调用传参。
            return intersect(nums2, nums1);
        }

        unordered_map<int, int> s数字频次表;
        for (auto num:nums1){
            ++s数字频次表[num];
        }

        vector<int> j结果;
        //循环体的写法和官方题解不同
        for (auto num:nums2){
            //存在相同的数字
            if (s数字频次表.find(num) != s数字频次表.end()){
                if (s数字频次表[num] > 0)
                    j结果.push_back(num);
                --s数字频次表[num];
            }
        }
        return j结果;
    }

    vector<int> 已排好序(vector<int>& nums1, vector<int>& nums2){
        vector<int> j结果;
        sort(nums1.begin(), nums1.end()); //排序
        sort(nums2.begin(), nums2.end()); //排序
        int z指针1 = 0, z指针2 = 0, c长度1 = nums1.size(), c长度2 = nums2.size();
        while (z指针1 < c长度1 && z指针2 < c长度2) {
            if (nums1[z指针1] == nums2[z指针2]){
                j结果.push_back(nums1[z指针1]);
                ++z指针1;
                ++z指针2;
            }
            else if (nums1[z指针1] < nums2[z指针2])
                ++z指针1;
            else ++z指针2;
        }
        return j结果;
    }
};