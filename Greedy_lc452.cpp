//
// Created by XKA on 2021/11/25.
//

#include <vector>
#include <algorithm>
using namespace std;

class Solution452 {
public:
    //第一次做基本没思路
    static bool b比较大小(vector<int> &s数组1, vector<int> &s数组2) {
        return s数组1[0] < s数组2[0];
    }

    int findMinArrowShots(vector<vector<int>> &points) {
        sort(points.begin(), points.end(), b比较大小); //按照气球起点从小到大排序
        int q气球数量 = points.size(), g弓箭数量 = 1;
        for (int i = 0; i < q气球数量 - 1; ++i) {
            if (points[i][1] < points[i + 1][0]) //当前气球和右方的气球边界不重叠
                ++g弓箭数量;
            else
                points[i + 1][1] = min(points[i][1], points[i + 1][1]);
        }
        return g弓箭数量;
    }
};