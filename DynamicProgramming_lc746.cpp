//
// Created by XK on 2022/3/12.
//
#include <vector>
using namespace std;

class Solution746 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int z最低花费, q前一层花费 = 0, q前两层花费 = 0;
        for (int i = 2; i <= cost.size(); ++i) {
            z最低花费 = min(q前一层花费 + cost[i - 1], q前两层花费 + cost[i - 2]);
            q前两层花费 = q前一层花费;
            q前一层花费 = z最低花费;
        }
        return z最低花费;
    }
};