//
// Created by XKA on 2021/11/10.
//
#include <vector>

using namespace std;

class Solution134 {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int j加油站数量 = gas.size(), d当前剩余油量 = 0, z总剩余油量 = 0, c出发时加油站位置 = -1;
        for (int i = 0; i < j加油站数量; ++i) {
            d当前剩余油量 += gas[i] - cost[i];
            z总剩余油量 += gas[i] - cost[i];
            //如果“d当前剩余油量”为负数，那么说明无法从第i站到第i+1站，出发起点可能在第i+1站。
            //遍历到最后一站时如果“d当前剩余油量”大于0，才需要从第一个加油站开始出发
            if (d当前剩余油量 < 0) {
                d当前剩余油量 = 0; //将“d当前剩余油量”置0并开始
                c出发时加油站位置 = i + 1;
            }
        }

        if (z总剩余油量 < 0) return -1; //剩余油量小于0那么必然不能走完一圈
        return c出发时加油站位置;
    }
};