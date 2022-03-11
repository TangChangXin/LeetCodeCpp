//
// Created by XKA on 2021/6/24.
//

//简单 斐波那契数列
/*
 * F(0) = 0，F(1) = 1
 * F(n) = F(n - 1) + F(n - 2)，其中 n > 1
 */

#include <vector>

using namespace std;

class Solution509 {
public:
    //2022年3月11日
    int d动态规划(int n) {
        if (n <= 1)
            return n;
        int j结果 = 0, j加数1 = 0, j加数2 = 1;
        for (int i = 2; i <= n; ++i) {
            j结果 = j加数1 + j加数2;
            j加数1 = j加数2;
            j加数2 = j结果;
        }
        return j结果;
    }

    int fib(int n) {
        if (n < 2) return n;
        vector<int> DP表(n + 1, 0);
        DP表[0] = 0;
        DP表[1] = 1;
        for (int i = 2; i <= n; ++i) {
            DP表[i] = DP表[i-1]+DP表[i-2];
        }
        return DP表[n];
    }
};