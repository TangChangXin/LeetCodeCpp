//
// Created by XK on 2022/1/23.
//
#include <vector>
using namespace std;
class Solution {
public:
    //没完全做出来
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int z指针1 = m - 1, z指针2 = n - 1, z指针3 = m + n - 1;
        while (z指针1 >= 0 && z指针2 >= 0) {
            if (nums1[z指针1] > nums2[z指针2]) {
                nums1[z指针3--] = nums1[z指针1];
                --z指针1;
            } else {
                nums1[z指针3--] = nums2[z指针2];
                --z指针2;
            }
        }

        if (z指针1 == -1)
            while (z指针2 >= 0)
                nums1[z指针3--] = nums2[z指针2--];
        if (z指针2 == -1)
            while (z指针1 >= 0)
                nums1[z指针3--] = nums1[z指针1--];
    }
};
