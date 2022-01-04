//
// Created by XKA on 2021/6/30.
//
#include <string>
#include <vector>

using namespace std;

class Solution51 {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> j结果;
        vector<string> y已选择位置(n, string(n, '.'));//首先初始化为全是‘.’，表示没有放置皇后
        h回溯法(y已选择位置, 0, j结果);
        return j结果;
    }

    // 路径：当前皇后放置方案 中小于 当前行 的那些行都已经成功放置了皇后
    // 选择列表：当前行的所有列都是放置皇后的选择
    // 结束条件：当前行 超过 棋盘 的最后一行
    void h回溯法(vector<string> &q棋盘, int row, vector<vector<string>> &f返回结果) {
        //初始传入的行是0行，即从第0行开始遍历
        if (row == q棋盘.size()) {
            f返回结果.push_back(q棋盘);
            return;//进入下一次递归
        }

        int k宽度 = q棋盘[row].size();//求出当前正在访问的行的长度
        for (int d当前列 = 0; d当前列 < k宽度; ++d当前列) {
            if (!k可以放置(q棋盘, row, d当前列)) continue;//后面的不执行了，进入下一次for循环

            q棋盘[row][d当前列] = 'Q';//做出选择
            //这一行放置好之后开始在下一行找位置放置皇后
            h回溯法(q棋盘, row + 1, f返回结果);

            //
            q棋盘[row][d当前列] = '.';//撤销选择
        }
    }

    bool k可以放置(vector<string> &q棋盘, int row, int l列) {
        //在当前的皇后位置摆放方案中，棋盘上小于 row 的所有行已经摆放好了皇后

        int g高度 = q棋盘.size();//求出当前已经摆放好的棋盘中
        //判断列是否有皇后位置冲突
        for (int i = 0; i < g高度; ++i) {
            if (q棋盘[i][l列] == 'Q') return false;
        }

        //判断右上方是否有皇后位置冲突
        for (int i = row - 1, j = l列 + 1; i >= 0 && j < g高度; --i, ++j) {
            if (q棋盘[i][j] == 'Q') return false;
        }

        //判断左上方是否有皇后位置冲突
        for (int i = row - 1, j = l列 - 1; i >= 0 && j >= 0; --i, --j) {
            if (q棋盘[i][j] == 'Q') return false;
        }
        return true;
    }
};