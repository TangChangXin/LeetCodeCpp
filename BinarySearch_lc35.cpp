//
// Created by XKA on 2021/8/29. 简单 搜索插入位置
//

#include <vector>
using namespace std;

class Solution35 {
public:
    //第一次做。有些细节没注意
    int searchInsert(vector<int>& nums, int target) {
        if (nums[0] > target) return 0;
        if (nums[nums.size()-1] < target) return nums.size();

        int z左指针 = 0, y右指针 = nums.size()-1, z中间位置 = (z左指针+y右指针)/2;
        //注意结束条件
        while (z左指针 <= y右指针){
            if (nums[z中间位置] == target) return z中间位置;
            else if (nums[z中间位置] < target) {
                z左指针 = z中间位置+1;
                z中间位置 = (z左指针+y右指针)/2;
            } else{
                y右指针 = z中间位置-1;
                z中间位置 = (z左指针+y右指针)/2;
            }
        }
        //如果z左指针 是 nums.size()，说明应该插入到数组最后加1的位置。若y右指针 是 -1，则应该插入到0的位置。
        if (z左指针 == nums.size()) return nums.size();
        else if (y右指针 == -1) return 0;
        else return z左指针; //画图
    }
};