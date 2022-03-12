//
// Created by XK on 2022/3/12.
//
#include <vector>

class Solution62 {
public:
    int uniquePaths(int m, int n) {
        //还有使用一维数组的版本
        std::vector<std::vector<int>> l路径表(m, std::vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            l路径表[i][0] = 1;
        }
        for (int i = 0; i < n; ++i) {
            l路径表[0][i] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                l路径表[i][j] = l路径表[i - 1][j] + l路径表[i][j - 1];
            }
        }
        return l路径表[m - 1][n - 1];
    }
};