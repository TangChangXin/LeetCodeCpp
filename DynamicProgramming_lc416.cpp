//
// Created by XK on 2022/3/15.
//

#include <vector>
#include <iostream>

using namespace std;

// 416. 分割等和子集 0-1背包问题
class Solution416 {
public:
    //2022年6月4日
    bool canPartition3(vector<int> &nums) {
        if (nums.size() < 2) return false;
        int s数组和 = 0, m目标和;
        for (int i: nums) {
            s数组和 += i;
        }
        if (s数组和 % 2 == 1) return false; //数组总和为奇数那么必然不能分成两个和相等的子集。
        else m目标和 = s数组和 / 2;
        //DP[i][j]表示从0到i中选择数字，其和恰好为j。
        vector<vector<bool>> DP(nums.size() + 1, vector<bool>(m目标和 + 1));

    }


    //2022年6月3日 没完全想出来
    bool canPartition2(vector<int> &nums) {
        if (nums.size() < 2) return false;
        int s数组和 = 0, m目标和;
        for (int i: nums) {
            s数组和 += i;
        }
        if (s数组和 % 2 == 1) return false; //数组总和为奇数那么必然不能分成两个和相等的子集。
        else m目标和 = s数组和 / 2;
        //从DP[i][j]表示任选数组索引从0到i的元素和为j。这种方法不用更改原数组的顺序。
        vector<vector<int>> DP(nums.size(), vector<int>(m目标和 + 1, 0)); //初始化全为0
        for (int i = nums[0]; i < m目标和 + 1; ++i) {
            DP[0][i] = nums[0];
        }

        for (int i = 1; i < nums.size(); ++i) {
            //外层遍历数组元素，内层遍历元素和对应的值
            for (int j = 1; j <= m目标和; ++j) {
                int b不选择 = DP[i - 1][j];
                int x选择;
                if (j < nums[i])
                    x选择 = DP[i - 1][j];
                else
                    x选择 = DP[i - 1][j - nums[i]] + nums[i];
                DP[i][j] = max(b不选择, x选择);
            }
        }
        if (DP[nums.size() - 1][m目标和] == m目标和)
            return true;
        else
            return false;
    }


    bool canPartition(vector<int> &nums) {
        if (nums.size() < 2) return false; //小于2无法划分
        int z总和 = 0, m目标和;
        for (int n: nums) {
            z总和 += n;
        }
        if (z总和 % 2 == 1)
            return false;
        else
            m目标和 = z总和 / 2;
        vector<vector<int>> z总和表(nums.size(), vector<int>(m目标和 + 1, 0));
        // 只对数组中的第一个元素放入不同背包时初始化即可。注意表示“子集和”的索引“i”应该以第一个元素的值作为开始，而不是从0开始
        // 因为有的“子集和”可能比第一个元素对应的值要小，那么其值应该是0。
        for (int i = nums[0]; i <= m目标和; ++i) {
            z总和表[0][i] = nums[0];
        }

        //遍历数组中的元素
        for (int i = 1; i < nums.size(); ++i) {
            //遍历背包容量，最小的值大于1，所以从1开始遍历即可
            for (int j = 1; j <= m目标和; ++j) {
                if (j < nums[i])
                    z总和表[i][j] = z总和表[i - 1][j];
                else
                    z总和表[i][j] = max(z总和表[i - 1][j], z总和表[i - 1][j - nums[i]] + nums[i]);
            }
        }
        /*
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < m目标和 + 1; ++j) {
                cout << z总和表[i][j];
                cout << '\t';
            }
            cout << '\n';
        }
         */

        if (z总和表[nums.size() - 1][m目标和] == m目标和)
            return true;
        else return false;
    }
};

int main() {
    //vector<int> qwe(2, 1);
    vector<int> qwe = {3, 3, 3, 4, 5};
    Solution416 asd;
    cout << asd.canPartition(qwe);
    return 0;
}