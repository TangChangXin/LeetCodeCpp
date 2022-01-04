//
// Created by XKA on 2021/11/8.
//

#include <vector>
#include <algorithm>
using namespace std;

class Solution455 {
public:
    //第一次做，直接看的随想录
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //g表示孩子，s表示饼干
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int h孩子位置 = 0, h孩子总数 = g.size(), b饼干总数 = s.size();

        for (int i = 0; i < b饼干总数; ++i) {
            if (h孩子位置 < h孩子总数 && g[h孩子位置] <= s[i]) {
                ++h孩子位置; //实际循环结束了，孩子位置就表示有多少孩子满足
            }
        }
        return h孩子位置;
    }
};