//
// Created by XK on 2022/1/29.
//

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution15 {
public:
    // 2022年3月23日
    vector<vector<int>> threeSum2(vector<int>& nums) {
        sort(nums.begin(),  nums.end()); //从小到大排序
        vector<vector<int>> j结果;
        int s数组长度 = nums.size();
        for (int i = 0; i < s数组长度 - 2; ++i) {
            if (nums[i] > 0)
                break; //如果第一个元素大于0了，那后面不可能满足三数和为0，直接退出
            //i控制第一个元素的移动。跳过重复元素，遇到重复元素时只用第一个元素计算
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            int z左指针 = i + 1, y右指针 = s数组长度 - 1;
            while (z左指针 < y右指针) {
                //满足条件则加入结果
                int s三数和 = nums[z左指针] + nums[y右指针] + nums[i];
                if (s三数和 == 0) {
                    j结果.push_back({nums[i], nums[z左指针], nums[y右指针]});
                    //下方去重结束后，指针都是指向最后一个重复的元素，加1，以及减1之后就指向了下一个不重复的元素
                    while (z左指针 < y右指针 && nums[z左指针] == nums[z左指针 + 1])
                        ++z左指针;
                    while (z左指针 < y右指针 && nums[y右指针] == nums[y右指针 - 1])
                        --y右指针;
                    ++z左指针;
                    --y右指针;
                }
                else if (s三数和 < 0) {
                    while (z左指针 < y右指针 && nums[z左指针] == nums[z左指针 + 1])
                        ++z左指针;
                    // 循环结束后指向最后一个重复元素，需要再加1
                    ++z左指针;
                }
                else {
                    while (z左指针 < y右指针 && nums[y右指针] == nums[y右指针 - 1])
                        --y右指针;
                    // 循环结束后指向最后一个重复元素，需要再减1
                    --y右指针;
                }
            }
        }
        return j结果;
    }

    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end()); //从小到大排序
        int s数组长度 = nums.size();
        vector<vector<int>> j结果;
        //指针i对应第一个加数
        for (int i = 0; i < s数组长度 - 2; ++i) {
            if (nums[i] > 0) break;
            //直接跳过循环体，执行for循环中的++i操作，如果在if这里写一句“++i”，那么i会多加上1。
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            int z左指针 = i + 1, y右指针 = s数组长度 - 1;
            while (z左指针 < y右指针) {
                int h和 = nums[i] + nums[z左指针] + nums[y右指针];
                if (h和 == 0) {
                    j结果.push_back(vector<int>{nums[i], nums[z左指针], nums[y右指针]});
                    while (z左指针 < y右指针 && nums[z左指针] == nums[z左指针 + 1]) ++z左指针;
                    while (z左指针 < y右指针 && nums[y右指针] == nums[y右指针 - 1]) --y右指针;
                    ++z左指针;
                    --y右指针;
                } else if (h和 < 0) ++z左指针;
                else --y右指针;
            }
        }
        return j结果;
    }
};