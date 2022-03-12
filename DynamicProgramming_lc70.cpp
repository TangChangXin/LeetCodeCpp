//
// Created by XK on 2022/3/12.
//

class Solution70 {
public:
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