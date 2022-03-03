//
// Created by XK on 2022/2/28.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution912 {
public:
    //2022年3月2日
    int h划分数组2(vector<int> &nums, int z左边界, int y右边界) {
        int j基准数位置 = rand() % (y右边界 - z左边界 + 1) + z左边界;
        swap(nums[j基准数位置], nums[y右边界]);
        int j基准数 = nums[y右边界];
        int z指针1 = z左边界 - 1;
        for (int z指针2 = z左边界; z指针2 <= y右边界 - 1; ++z指针2) {
            if (nums[z指针2] <= j基准数) {
                ++z指针1;
                swap(nums[z指针1], nums[z指针2]);
            }
        }
        swap(nums[z指针1 + 1], nums[y右边界]);
        return z指针1 + 1; //经过一趟排序后，基准数对应索引的位置
    }

    void d递归快速排序2(vector<int> &nums, int z左边界, int y右边界) {
        if (z左边界 < y右边界) {
            int j基准数位置 = h划分数组2(nums, z左边界, y右边界);
            d递归快速排序2(nums, z左边界, j基准数位置 - 1);
            d递归快速排序2(nums, j基准数位置 + 1, y右边界);
        }
    }

    //2022年3月1日
    //返回经过一趟排序后基准数对应的索引
    int h划分数组1(vector<int> &nums, int z左边界, int y右边界) {
        int w位置 = rand() % (y右边界 - z左边界 + 1) + z左边界; //随机选择基准数的索引
        swap(nums[w位置], nums[y右边界]);
        int j基准数 = nums[y右边界]; //交换之后最后一个数就是基准数
        int z指针1 = z左边界 - 1;
        for (int z指针2 = z左边界; z指针2 <= y右边界 - 1; ++z指针2) {
            if (nums[z指针2] <= j基准数) {
                ++z指针1;
                swap(nums[z指针1], nums[z指针2]);
            }
        }
        swap(nums[z指针1 + 1], nums[y右边界]);
        return z指针1 + 1;
    }

    void d递归排序1(vector<int> &nums,  int l, int r) {
        if (l < r) {
            int w位置 = h划分数组1(nums, l, r);
            d递归排序1(nums, l, w位置 - 1);
            d递归排序1(nums, w位置 + 1, r);
        }
    }

    //官方题解
    int gpartition(vector<int> &nums, int l, int r) {
        //选择最后一个数作为基准数
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; ++j) {
            if (nums[j] <= pivot) {
                //TODO 为什么要先加1，因为如果"i+1"对应的值大于基准数，那么j会直接进入下一次循环，等遇到了小于基准数的数字，将“i”加1再交换，
                //即可保证左边全比基准数小
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        //上述循环结束后，从0到i全是比基准数小的数；从i+1到r-1全是比基准数大的数。交换i+1和r，划分为左右两个子数组
        swap(nums[i + 1], nums[r]); //
        return i + 1; //返回一趟排序后的基准数的索引
    }

    //随机选择主元位置
    int grandomized_partition(vector<int> &nums, int l, int r) {
        int i = rand() % (r - l + 1) + l; // 随机选一个作为我们的主元
        swap(nums[r], nums[i]); //交换基准数和最后一个数
        return gpartition(nums, l, r); //返回一趟排序后的基准数的索引
    }

    //递归排序
    void grandomized_quicksort(vector<int> &nums, int l, int r) {
        if (l < r) {
            int pos = grandomized_partition(nums, l, r);
            grandomized_quicksort(nums, l, pos - 1);
            grandomized_quicksort(nums, pos + 1, r);
        }
    }

    //快速排序，看了题解
    vector<int> sortArray(vector<int> &nums) {
        grandomized_quicksort(nums, 0, (int) nums.size() - 1);
        return nums;
    }
};

int main() {
    vector<int> qwe = {5,2,3,1};
    Solution912 asd;
    asd.d递归快速排序2(qwe, 0, 3);
    for (int n:qwe) {
        cout << n << endl;
    }
    return 0;
}