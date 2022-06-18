//
// Created by XK on 2022/6/18.
//
#include <vector>

using namespace std;

class Solution1035 {
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
        //这题其实本质就是求最长公共子序列的长度。在数组A中找一个子序列a，在数组B中找相同的一个子序列b，且a中的元素与b中元素相对位置不变。
        vector<vector<int>> DP(nums1.size() + 1, vector<int>(nums2.size() + 1));
        int z最大连线数 = 0;
        for (int i = 1; i <= nums1.size(); ++i) {
            for (int j = 1; j <= nums2.size(); ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    DP[i][j] = DP[i - 1][j - 1] + 1;
                    z最大连线数 = max(z最大连线数, DP[i][j]);
                } else
                    DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
            }
        }
        return DP[nums1.size()][nums2.size()];
    }
};