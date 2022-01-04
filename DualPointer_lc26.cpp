//
// Created by XKA on 2021/9/1. 简单 删除有序数组中的重复项
//

#include <vector>
using namespace std;

class Solution26 {
public:
    //第一次做
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int x新长度 = 1, x新指针 = 0, y原长度 = nums.size();
        nums[x新指针] = nums[0];  //todo 这里是否相当于链表形式的前置节点  这里可以优化
        for (int d当前指针 = 1; d当前指针 < y原长度; ++d当前指针) {
            int l临时 = nums[x新指针]; //这里可以优化
            if (l临时 != nums[d当前指针]) {
                nums[++x新指针] = nums[d当前指针];
                ++x新长度;
            }
        }

        return x新长度;
    }
};