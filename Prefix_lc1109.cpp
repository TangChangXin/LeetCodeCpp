//
// Created by XK on 2022/5/18.
//
#include <vector>
using namespace std;

class Solution {
public:
    //其实开始思路没问题，但还是看了官方题解才完善
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        //实际bookings中每个元素就表示对i到j区间内的航班座位数进行增加。那么我们可以初始化一个全0的差分数组用来保存航班座位数。
        vector<int> h航班座位(n, 0); //数组先全部初始化为0。方便与差分数组相加
        for (auto &j记录:bookings) {
            //航班编号从1开始
            h航班座位[j记录[0]-1] += j记录[2];
            //注意这里边界
            if (j记录[1] < n)
                h航班座位[j记录[1]] -= j记录[2];
        }
        //上述循环结束后得到就是差分数组
        for (int i = 1; i < n; ++i) {
            h航班座位[i] += h航班座位[i - 1];
        }
        return h航班座位;
    }
};