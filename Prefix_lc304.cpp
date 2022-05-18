//
// Created by XK on 2022/5/18.
//
#include <vector>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> q前缀和数组;

    NumMatrix(vector<vector<int>> &matrix) {
        int h行数 = matrix.size(), l列数 = matrix[0].size();
        q前缀和数组.resize(h行数+1, vector<int>(l列数+1, 0)); //前缀和比数组多出一行一列，方便第一行和第一列使用递推公式
        for (int i = 1; i <= h行数; ++i) {
            for (int j = 1; j <= l列数; ++j) {
                //q前缀和数组[i][j]实际是从matrix[0][0]+...+matrix[i-1][j-1]。注意i，j都是从1开始遍历。i=0或者j=0时表示
                q前缀和数组[i][j] = q前缀和数组[i][j - 1] + q前缀和数组[i - 1][j] - q前缀和数组[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return q前缀和数组[row2 + 1][col2 + 1] - q前缀和数组[row1][col2 + 1] - q前缀和数组[row2 + 1][col1]+ q前缀和数组[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */