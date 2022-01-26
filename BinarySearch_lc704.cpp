//
// Created by XK on 2022/1/26.
//

#include <vector>

using namespace std;

class Solution704 {
public:
    int search(vector<int> &nums, int target) {
        int z左边界 = 0, y右边界 = nums.size() - 1;
        while (z左边界 <= y右边界) {
            int z中点 = (z左边界 + y右边界) / 2;
            if (target == nums[z中点]) return z中点;
            else if (target > nums[z中点]) z左边界 = z中点 + 1;
            else y右边界 = z中点 - 1;
        }
        return -1;
    }
};