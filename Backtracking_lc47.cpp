//
// Created by XKA on 2021/10/8.
//

#include <vector>
#include <algorithm>
using namespace std;

class Solution47 {
public:
    //第一次做。
    vector<vector<int>> j结果;
    vector<int> l路径;
    //后来看了随想录改进去重
    void h回溯函数(vector<int> &nums, int s数组长度, vector<bool> &y已访问位置) {
        if (l路径.size() == s数组长度) {
            j结果.push_back(l路径);
            return;
        }

        for (int i = 0; i < s数组长度; ++i) {
            //重点注意“y已访问位置”里的true或者false不一定表示访问或者未访问，而是要看具体的循环分析。
            //上一次for循环结束，进入这一次for循环，此时“y已访问位置[i - 1] == false”，但是其实nums[i - 1]已经访问了。
            //因此递归时不断回溯，若y已访问位置[i - 1] == false且“nums[i] == nums[i - 1]”说明同一树层中若访问到相同数字则跳过。
            if (i > 0 && nums[i] == nums[i - 1] && y已访问位置[i - 1] == false) continue;

            //全排列每次循环位置都是从0开始，因此对于纵向的递归选择过程，若“y已访问位置[i] == true”，说明该值已访问过，则跳过。
            if (y已访问位置[i] == false) {
                l路径.push_back(nums[i]);
                y已访问位置[i] = true;
                h回溯函数(nums, s数组长度, y已访问位置);
                l路径.pop_back();
                y已访问位置[i] = false; //递归返回后置false，进入下一次for循环
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        int s数组长度 = nums.size();
        vector<bool> y已访问位置(s数组长度, false);
        sort(nums.begin(), nums.end()); //排序后方便去重
        h回溯函数(nums, s数组长度,y已访问位置);
        return j结果;
    }
};

/*
//第一次自己写的 这种方式去重效率低
void 低h回溯函数(vector<int> &nums, int s数组长度, vector<int> &y已访问) {
    if (l路径.size() == s数组长度) {
        if (find(j结果.begin(), j结果.end(), l路径) == j结果.end()) {
            j结果.push_back(l路径);
            return;
        } else return;
    }
    for (int i = 0; i < s数组长度; ++i) {
        //
        if (find(y已访问.begin(), y已访问.end(), i) != y已访问.end()) continue; //避免重复访问
        l路径.push_back(nums[i]);
        y已访问.push_back(i);
        低h回溯函数(nums, s数组长度, y已访问);
        l路径.pop_back();
        y已访问.pop_back();
    }
}
 */