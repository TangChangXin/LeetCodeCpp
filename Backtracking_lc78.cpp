//
// Created by XKA on 2021/10/5.
//


#include <vector>
#include <iostream>
#include <typeinfo>
using namespace std;

class Solution78 {
public:
    //todo 迭代法

    vector<vector<int>> j结果;
    vector<int> l路径;

    //2022年2月3日，没完全想出来。其实在每次递归的时候把路径加入到结果中就是获取到子集。
    void h回溯函数2(vector<int> &z整数数组, int q起始位置) {
        j结果.push_back(l路径);
        for (int i = q起始位置; i < z整数数组.size(); ++i) {
            l路径.push_back(z整数数组[i]);
            h回溯函数2(z整数数组, i + 1);
            l路径.pop_back();
        }
    }

    //第一次做
    void h回溯函数(vector<int> &nums, int z子集大小, int q起始位置, int s数组长度) {
        if (l路径.size() == z子集大小) {
            j结果.push_back(l路径);
            return;
        }
        for (int i = q起始位置; i <= s数组长度 - z子集大小 + l路径.size(); ++i) {
            l路径.push_back(nums[i]);
            h回溯函数(nums, z子集大小, i + 1, s数组长度);
            l路径.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int s数组长度 = nums.size();

        //循环变量i表示当前准备返回的子集大小
        for (int i = 0; i <= s数组长度; ++i) {
            //从数组中选择“i”个元素构成子集
            h回溯函数(nums, i, 0, s数组长度);
        }
        return j结果;
    }
};

int main() {
    int a = 1, b = 0;
    cout << (1 << 3);
    return 0;
}