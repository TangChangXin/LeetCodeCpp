//
// Created by XK on 2022/3/15.
//

#include <vector>
#include <iostream>

using namespace std;

// 最后一块石头的重量 II
class Solution1049 {
public:
    //2022年6月5日
    int lastStoneWeightII2(vector<int> &stones) {
        int z重量和 = 0;
        for (int i: stones) {
            z重量和 += i;
        }
        //这题有点儿类似分割等和子集。将数组划分为两部分，两部分的和尽量相等。子集和较大的部分减去子集和较小的部分之后剩余结果就是最后一块石头的重量。
        int m目标和 = z重量和 / 2; //以总和一半为界，求出较小的子集和。
        //问题转化为从数组中任意选择数字，求和结果在不超过目标和的条件下最大是多少。
        //DP[i][j]表示选择索引在0到i内的元素，放入容量为j的背包中的最大求和结果。
        vector<vector<int>> DP(stones.size(), vector<int>(m目标和 + 1));
        for (int i = stones[0]; i < m目标和 + 1; ++i) {
            DP[0][i] = stones[0]; //第一行中只有背包容量大于等于第一个元素时才初始化为第一个元素的值。
        }
        for (int i = 1; i < stones.size(); ++i) {
            for (int j = 0; j < m目标和 + 1; ++j) {
                int b不选择 = DP[i - 1][j];
                int x选择;
                if (j >= stones[i])
                    x选择 = DP[i - 1][j - stones[i]] + stones[i]; //选了第i个元素且背包容量足够
                else
                    x选择 = DP[i - 1][j]; //选择了第i个元素，但是背包容量不够
                DP[i][j] = max(b不选择, x选择);
            }
        }
        return z重量和 - DP[stones.size() - 1][m目标和] - DP[stones.size() - 1][m目标和];
    }


    int lastStoneWeightII(vector<int> &stones) {
        int z总和 = 0;
        for (int n: stones) {
            z总和 += n;
        }
        int m目标和 = z总和 / 2; // 向下取整，所以“总和 - 目标和”大于目标和
        vector<vector<int>> z子集和(stones.size(), vector<int>(m目标和 + 1, 0));
        for (int i = stones[0]; i <= m目标和; ++i) {
            z子集和[0][i] = stones[0]; // 只初始化第一个石头即可
        }
        for (int i = 1; i < stones.size(); ++i) {
            for (int j = 0; j <= m目标和; ++j) {
                int b不放入 = z子集和[i - 1][j]; //不选择该物品
                int f放入;
                if (j < stones[i])
                    f放入 = z子集和[i - 1][j]; //放入该物品但是背包容量不足
                else
                    f放入 = z子集和[i - 1][j - stones[i]] + stones[i]; //放入该物品且背包容量充足
                z子集和[i][j] = max(b不放入, f放入);
                /*
                if (j < stones[i])
                    z子集和[i][j] = z子集和[i - 1][j];
                else
                    z子集和[i][j] = max(z子集和[i - 1][j], z子集和[i - 1][j - stones[i]] + stones[i]);
                */
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
    vector<int> qwe = {1, 2};
    Solution1049 asd;
    cout << asd.lastStoneWeightII(qwe);
    return 0;
}