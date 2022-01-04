//
// Created by XKA on 2021/9/8.
//

#include <vector>
using namespace std;

class Solution59 {
public:
    //第一次做
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> j结果(n, vector<int>(n, 0)); //
        int x循环次数 = n / 2, z中间位置 = n / 2, q起始位置x = 0, q起始位置y = 0, s数字 = 1, d当前循环 = 1;
        while (d当前循环 <= x循环次数){
            int i = q起始位置x, j = q起始位置y; //每次循环起始坐标
            for (j = q起始位置y; j < n - d当前循环; ++j) {
                j结果[i][j] = s数字++; //遍历时行坐标不变，列坐标增加
            }
            for (i = q起始位置x; i < n - d当前循环; ++i) {
                j结果[i][j] = s数字++; //遍历时列坐标不变，行坐标增加
            }
            for (; j > q起始位置y; --j) {
                j结果[i][j] = s数字++; //遍历时行坐标不变，列坐标减小
            }
            for (; i > q起始位置x; --i) {
                j结果[i][j] = s数字++; //遍历时列坐标不变，行坐标减小
            }

            ++q起始位置x; //下一轮循环起始位置增加
            ++q起始位置y; //下一轮循环起始位置增加
            ++d当前循环; //循环次数增加
        }
        if (n % 2)
            j结果[z中间位置][z中间位置] = s数字; //画图就懂 单独判断
        return j结果;
    }
};