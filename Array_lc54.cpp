//
// Created by XKA on 2021/9/8.
//

#include <vector>

using namespace std;

class Solution54 {
public:
    // 链接：https://leetcode-cn.com/problems/spiral-matrix/solution/cxiang-xi-ti-jie-by-youlookdeliciousc-3/
    vector<int> 别人题解(vector<vector<int>> &matrix) {
        vector<int> ans;
        if (matrix.empty()) return ans; //若数组为空，直接返回答案
        int u = 0; //赋值上下左右边界
        int d = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;
        while (true) {
            for (int i = l; i <= r; ++i) ans.push_back(matrix[u][i]); //向右移动直到最右
            if (++u > d) break; //重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
            for (int i = u; i <= d; ++i) ans.push_back(matrix[i][r]); //向下
            if (--r < l) break; //重新设定有边界
            for (int i = r; i >= l; --i) ans.push_back(matrix[d][i]); //向左
            if (--d < u) break; //重新设定下边界
            for (int i = d; i >= u; --i) ans.push_back(matrix[i][l]); //向上
            if (++l > r) break; //重新设定左边界
        }
        return ans;
    }

    //第一次做，这个方法有点麻烦，遍历的结束条件判断有点儿繁琐，需要多次if判断
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int h行数 = matrix.size(), l列数 = matrix[0].size();
        vector<int> j结果;
        int x循环次数, q起始位置x = 0, q起始位置y = 0, d当前循环 = 1, s数字 = 0;
        h行数 > l列数 ? x循环次数 = h行数 / 2 : x循环次数 = l列数 / 2;
        int i, j;
        while (d当前循环 <= x循环次数) {
            i = q起始位置x, j = q起始位置y; //每次循环起始坐标
            for (j = q起始位置y; j < l列数 - d当前循环; ++j) {
                j结果.push_back(matrix[i][j]); //遍历时行坐标不变，列坐标增加
                ++s数字;
                if (s数字 == h行数 * l列数) break; //退出了for还没退出while
            }
            for (i = q起始位置x; i < h行数 - d当前循环; ++i) {
                j结果.push_back(matrix[i][j]); //遍历时列坐标不变，行坐标增加
                ++s数字;
                if (s数字 == h行数 * l列数) break; //退出了for还没退出while
            }
            for (; j > q起始位置y; --j) {
                j结果.push_back(matrix[i][j]);
                ++s数字;
                if (s数字 == h行数 * l列数) break; //退出了for还没退出while
            }
            for (; i > q起始位置x; --i) {
                j结果.push_back(matrix[i][j]);
                ++s数字;
                if (s数字 == h行数 * l列数) break; //退出了for还没退出while
            }
            if (s数字 == h行数 * l列数) break; //退出while
            ++d当前循环;
            ++q起始位置x;
            ++q起始位置y;
        }
        if ((h行数 == l列数) && (h行数 % 2)) j结果.push_back(matrix[h行数 / 2][l列数 / 2]);
        return j结果;
    }
};