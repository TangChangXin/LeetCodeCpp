//
// Created by XK on 2022/1/29.
//

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution15 {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end()); //从小到大排序
        int s数组长度 = nums.size();
        vector<vector<int>> j结果;
        //指针i对应第一个加数
        for (int i = 0; i < s数组长度 - 2; ++i) {
            if (nums[i] > 0) break;
            //直接跳过循环体，执行for循环中的++i操作，如果在if这里写一句“++i”，那么i会多加上1。
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            int z左指针 = i + 1, y右指针 = s数组长度 - 1;
            while (z左指针 < y右指针) {
                int h和 = nums[i] + nums[z左指针] + nums[y右指针];
                if (h和 == 0) {
                    j结果.push_back({nums[i], nums[z左指针], nums[y右指针]});
                    while (z左指针 < y右指针 && nums[z左指针] == nums[z左指针 + 1]) ++z左指针;
                    while (z左指针 < y右指针 && nums[y右指针] == nums[y右指针 - 1]) --y右指针;
                    ++z左指针;
                    --y右指针;
                } else if (h和 < 0) ++z左指针;
                else --y右指针;
            }
        }
        return j结果;
    }
};

int main() {
    vector<int> a = {3, 2, 1};
    sort(a.begin(), a.end());
    cout << a[0];
    return 0;
}