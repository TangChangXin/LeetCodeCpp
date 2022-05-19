//
// Created by XK on 2022/5/19.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution96 {
public:
    void numTrees(int n) {
        // 初始化全0的表，e二叉搜索树表[i]表示由i个节点组成且节点值从1到i的互不相同的二叉搜索树个数。
        // 先根据i分别为1,2,3时的结果进行简单的数学推导。
        // 进行数学推导
        // 1. 设G[n]为长度为n的序列构成的不相同的二叉搜索树个数。
        // 2. F(i,n)表示以i为根节点时，节点数量为n时的不相同的二叉搜索树的个数。
        // F(i,n) = G(i-1)*G(n-i)，其中G(i-1)表示左子节点的二叉搜索树个数，G(n-i)表示右子节点的二叉搜索树个数。
        //
        vector<int> e二叉搜索树表(n+1, 0);
        e二叉搜索树表[0] = 1; //注意初始化DP[0] = 1
        for (int i = 1; i < n+1; ++i) {
            for (int j = 1; j <= i; ++j) {
                e二叉搜索树表[i] += e二叉搜索树表[j-1]*e二叉搜索树表[i - j];
            }
            cout << e二叉搜索树表[i] << '\t';
        }
//        return e二叉搜索树表[n];
    }
};

int main() {
    class Solution96 cesh;
    cesh.numTrees(3);
}