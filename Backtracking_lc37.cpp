//
// Created by XKA on 2021/10/10.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution37 {
public:
    //第一次做，看了题解 传入的棋盘中有些数字是已经确定好的
    bool h回溯函数(vector<vector<char>> &board) {
        //每次进入函数都是从第0行开始，逐行向下遍历，i表示行
        for (int i = 0; i < 9; ++i) {
            //每次都是从第0列开始，逐列向后遍历，j表示列
            for (int j = 0; j < 9; ++j) {
                // 假设最后一个格子填好了且满足条件，现在已经进入到下一次递归函数了，那么这里会不断continue直到遍历结束，循环内的“return false”不执行，
                // 这样等所有for遍历结束就会返回true，然后再返回到上一层递归函数，判断后直接返回true就好了。
                if (board[i][j] != '.') continue; //如果当前这个格子的字符不是’.‘，那说明这个格子已经有数字了则直接进行下一次循环

                //遍历数字’1‘至’9‘，
                for (char k = '1'; k <= '9'; ++k) {
                    //如果可以放置
                    if (s是否可以放置(board, k, i, j)) {
                        board[i][j] = k; //在当前的格子做出选择
                        if (h回溯函数(board)) return true; //进入下一次的递归，如果找到了一组满足条件的解就立即返回
                        board[i][j] = '.';
                    }
                }

                return false; //在最后一个格子填写数字时，如果不能在上面的for循环中返回true的话，那说明这九个数字都不适合，返回false
            }
        }

        return true;
    }

    bool s是否可以放置(vector<vector<char>> &board, char d待放置数字,int d当前行, int d当前列) {
        //判断当前所在行是否有冲突
        for (int i = 0; i < 9; ++i) {
            if (board[d当前行][i] == d待放置数字) return false;
        }
        //判断当前所在列是否有冲突
        for (int i = 0; i < 9; ++i) {
            if (board[i][d当前列] == d待放置数字) return false;
        }
        //判断当前所在3*3宫内是否有冲突。先除以3是为了确定在哪个3*3宫内，乘以3是为了确定真正的起始位置
        int h行起始位置 = (d当前行 / 3) * 3, l列起始位置 = (d当前列 / 3) * 3, h行结束位置 = h行起始位置 + 3, l列结束位置 = l列起始位置 + 3;
        for (int i = h行起始位置; i < h行结束位置; ++i) {
            for (int j = l列起始位置; j < l列结束位置; ++j) {
                if (board[i][j] == d待放置数字) return false;
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        h回溯函数(board);
    }
};