//
// Created by XK on 2022/3/12.
//

#include <vector>

using namespace std;

class Solution63 {
public:
    //看了随想录
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int k宽度 = obstacleGrid.size(), c长度 = obstacleGrid[0].size();
        vector<vector<int>> l路径表(k宽度, vector<int>(c长度, 0));
        for (int i = 0; i < k宽度 && obstacleGrid[i][0] == 0; ++i) {
            l路径表[i][0] = 1;
        }
        for (int i = 0; i < c长度 && obstacleGrid[0][i] == 0; ++i) {
            l路径表[0][i] = 1;
        }
        for (int i = 1; i < k宽度; ++i) {
            for (int j = 1; j < c长度; ++j) {
                if (obstacleGrid[i][j] == 1) continue;
                l路径表[i][j] = l路径表[i - 1][j] + l路径表[i][j - 1];
            }
        }
        return l路径表[k宽度 - 1][c长度 - 1];
    }
};