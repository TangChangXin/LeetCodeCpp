//
// Created by XK on 2022/3/12.
//
#include <vector>

using namespace std;

//70. 爬楼梯
class Solution70 {
public:
    //2022年6月12日
    int climbStairs2(int n) {
        vector<int> DP(n + 1);
        DP[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 2; ++j) {
                if (i >= j)
                    DP[i] += DP[i - j];
            }
        }
        return DP[n];
    }

    int climbStairs(int n) {
        if (n <= 2)
            return n;
        //其实和斐波那契数列类似
        int d当前层方法, q前一层方法 = 2, q前两层方法 = 1; //初始化第一层1种方法，第二层2种方法
        for (int i = 3; i <= n; ++i) {
            d当前层方法 = q前一层方法 + q前两层方法;
            q前两层方法 = q前一层方法;
            q前一层方法 = d当前层方法;
        }
        return d当前层方法;
    }
};