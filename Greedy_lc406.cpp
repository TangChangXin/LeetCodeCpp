//
// Created by XKA on 2021/11/19.
//

#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Solution406 {
public:
    //第一次做，思路不清晰
    static bool b比大小(vector<int> &s数组1, vector<int> &s数组2) {
        if (s数组1[0] == s数组2[0])
            //如果身高相等
            return s数组1[1] < s数组2[1];
        //不相等则直接返回高的
        return s数组1[0] > s数组2[0];
    }

    //使用动态数组实现，插入的效率低
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), b比大小);
        vector<vector<int>> d队列;
        int z总人数 = people.size();
        for (int i = 0; i < z总人数; ++i) {
            int c插入位置 = people[i][1];
            d队列.insert(d队列.begin() + c插入位置, people[i]);
        }
        return d队列;
    }

    vector<vector<int>> c重建队列(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), b比大小);
        list<vector<int>> d队列;
        int z总人数 = people.size();
        for (int i = 0; i < z总人数; ++i) {
            int c插入位置 = people[i][1];
            list<vector<int>>::iterator d迭代器 = d队列.begin();
            while (c插入位置--) {
                //寻找对应的插入位置
                ++d迭代器;
            }
            d队列.insert(d迭代器, people[i]);
        }
        return vector<vector<int>>(d队列.begin(), d队列.end());
    }
};