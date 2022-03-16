//
// Created by XK on 2022/3/15.
//

#include <vector>
#include <iostream>
using namespace std;

// 分割等和子集
class Solution416 {
public:
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
                    z总和表[i][j] = max(z总和表[i - 1][j], z总和表[i-1][j - nums[i]] + nums[i]);
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
    vector<int> qwe = {3,3,3,4,5};
    Solution416 asd;
    cout << asd.canPartition(qwe);
    return 0;
}