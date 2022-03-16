//
// Created by XK on 2022/3/15.
//

#include <vector>
#include <iostream>

using namespace std;

// 最后一块石头的重量 II
class Solution1049 {
public:
    int lastStoneWeightII(vector<int> &stones) {
        int z总和 = 0;
        for (int n:stones) {
            z总和 += n;
        }
        int m目标和 = z总和 / 2; // 向下取整，所以“总和 - 目标和”大于目标和
        vector<vector<int>> z子集和(stones.size(), vector<int>(m目标和 + 1, 0));
        for (int i = stones[0]; i <= m目标和; ++i) {
            z子集和[0][i] = stones[0]; // 只初始化第一个石头即可
        }
        for (int i = 1; i < stones.size(); ++i) {
            for (int j = 0; j <= m目标和; ++j) {
                if (j < stones[i])
                    z子集和[i][j] = z子集和[i - 1][j];
                else
                    z子集和[i][j] = max(z子集和[i - 1][j], z子集和[i - 1][j - stones[i]] + stones[i]);
            }
        }
/*
        for (int i = 0; i < stones.size(); ++i) {
            for (int j = 0; j < m目标和 + 1; ++j) {
                cout << z子集和[i][j];
                cout << '\t';
            }
            cout << '\n';
        }
*/
        return z总和 - z子集和[stones.size() - 1][m目标和] - z子集和[stones.size() - 1][m目标和];
    }
};

int main() {
    //vector<int> qwe(2, 1);
    vector<int> qwe = {1,2};
    Solution1049 asd;
    cout << asd.lastStoneWeightII(qwe);
    return 0;
}