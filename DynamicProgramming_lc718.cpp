//
// Created by XK on 2022/6/17.
//
#include <vector>

using namespace std;

class Solution718 {
public:
    int 我的错误思路(vector<int> &nums1, vector<int> &nums2) {
        vector<vector<int>> DP(nums1.size(), vector<int>(nums2.size()));
        for (int i = 0; i < nums2.size(); ++i) {
            if (nums2[i] == nums1[0])
                DP[0][i] = 1;
        }
        for (int i = 0; i < nums1.size(); ++i) {
            if (nums1[i] == nums2[0])
                DP[i][0] = 1;
        }
        int z最长长度 = 0;
        for (int i = 1; i < nums1.size(); ++i) {
            for (int j = 1; j < nums2.size(); ++j) {
                //注意我的这种思路实际上对于两个数组中的第一个元素并没有访问到，是从第二个元素才开始访问的。所以会出错，例子：[1,2,3,2,8]，[5,6,1,4,7]
                if (nums1[i] == nums2[j]) {
                    DP[i][j] = DP[i - 1][j - 1] + 1;
                    z最长长度 = max(z最长长度, DP[i][j]);
                }
            }
        }
        return z最长长度;
    }

    int findLength(vector<int> &nums1, vector<int> &nums2) {
        //DP[i][j]表示nums1中以下标i-1为结尾与nums2中以下标j-1为结尾的最长重复子数组的长度。定义成i-1和j-1的形式是为了递推公式的一致性。
        //如果定义成i和j的形式就会犯上面思路的错误，需要额外对第一个元素进行处理才符合要求。
        //DP[i][0]和DP[0][j]是无意义的，但是初始为0就可以。这样在访问第一个元素时，nums1[0]和nums2[0]相等的话则，DP[1][1]=DP[0][0]+1，这样刚好符合递推公式的逐步累加计算。
        vector<vector<int>> DP(nums1.size() + 1, vector<int>(nums2.size() + 1));

        int z最长长度 = 0;
        for (int i = 1; i <= nums1.size(); ++i) {
            for (int j = 1; j <= nums2.size(); ++j) {
                //下标i-1和j-1才是当前正在访问的元素。
                if (nums1[i-1] == nums2[j-1]) {
                    DP[i][j] = DP[i - 1][j - 1] + 1;
                    z最长长度 = max(z最长长度, DP[i][j]);
                }
            }
        }
        return z最长长度;
    }
};