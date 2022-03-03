//
// Created by XK on 2022/3/2.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution215 {
public:
    //2022年3月2日，简单的看了官方题解。
    int h划分数组(vector<int> &nums, int z左边界, int y右边界, int k) {
        int j基准数位置 = rand() % (y右边界 - z左边界 + 1) + z左边界;
        swap(nums[j基准数位置], nums[y右边界]);
        int z指针1 = z左边界 - 1, j基准数 = nums[y右边界];
        for (int z指针2 = z左边界; z指针2 <= y右边界 - 1; ++z指针2) {
            //这里采用降序排列
            if (nums[z指针2] >= j基准数) {
                ++z指针1;
                swap(nums[z指针1], nums[z指针2]); //每次交换后“指针1”对应的数字都是小于等于基准数的数字
            }
        }
        swap(nums[z指针1 + 1], nums[y右边界]);
        return z指针1 + 1;
    }

    int d递归函数(vector<int> &nums, int z左边界, int y右边界, int k) {
        //为什么这里不用左边界小于右边界，似乎因为只进行快速排序时，左边界小于右边界时递归结束条件，而这里有其他结束条件。
        int j基准数位置 = h划分数组(nums, z左边界, y右边界, k);
        if (k == j基准数位置 + 1)
            return nums[j基准数位置];
        else if (k > j基准数位置 + 1)
            return d递归函数(nums,j基准数位置 + 1, y右边界, k);
        else
            return d递归函数(nums, z左边界, j基准数位置 - 1, k);
    }

    int findKthLargest(vector<int> &nums, int k) {
        return d递归函数(nums, 0, nums.size() - 1, k);
    }
};

int main() {
    cout << rand() % 0 << endl;
    return 0;
}