//
// Created by XK on 2022/3/6.
//

#include <vector>
#include <algorithm>

using namespace std;

class Solution442 {
public:
    //2022年3月6日，看了剑指offer的解释
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> c重复的整数;
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != i + 1) {
                //和第“nums[i]”个比较,相等则说明重复了；不相等就交换两者的值然后继续循环判断
                if (nums[i] == nums[nums[i] - 1]) {
                    //防止重复添加
                    if (find(c重复的整数.begin(),  c重复的整数.end(), nums[i]) == c重复的整数.end())
                        c重复的整数.push_back(nums[i]);
                    break;
                }
                else
                    swap(nums[i], nums[nums[i] - 1]);
            }
        }
        return c重复的整数;
    }
};