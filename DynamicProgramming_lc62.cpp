//
// Created by XK on 2022/3/12.
//
#include <vector>
#include <iostream>
class Solution62 {
public:
    //2022年3月14日
    int z组合数方法(int m, int n) {
        long long j结果 = 1;
        for (int i = n, j = 1; j < m; ++i, ++j) {
            j结果 = j结果 * i / j;
        }
        return j结果;
    }

    int d动态规划优化空间(int m, int n) {
        std::vector<int> l路径表(n, 1);
        //可以理解为每次只计算一行的结果，计算完直接覆盖原来的数组，这样相当于把上一次的计算结果保留了。
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                l路径表[j] += l路径表[j - 1];
            }
        }
        return l路径表[n - 1];
    }

    int uniquePaths(int m, int n) {
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

int qwer() {
    std::vector<int> a(5, 1);
    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j < 5; ++j) {
            a[j] += a[j - 1];
        }
    }
    return a[4];
}

int main() {
    std::cout << qwer();
    return 0;
}