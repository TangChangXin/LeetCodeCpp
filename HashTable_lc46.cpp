//
// Created by XK on 2022/2/5.
//

#include <vector>

using namespace std;

class Solution46 {
public:
    vector<vector<int>> q全排列结果;
    vector<int> p排列;

    //之前用Java写过
    void h回溯函数(vector<int> &w无重复数组, vector<bool> &y已访问) {
        if (p排列.size() == w无重复数组.size()) {
            q全排列结果.push_back(p排列);
            return;
        }
        for (int i = 0; i < w无重复数组.size(); ++i) {
            if (y已访问[w无重复数组[i] + 10] == true) continue;
            p排列.push_back(w无重复数组[i]);
            y已访问[w无重复数组[i] + 10] = true;
            h回溯函数(w无重复数组, y已访问);
            p排列.pop_back();
            y已访问[w无重复数组[i] + 10] = false;
        }
    }
    
    vector<vector<int>> permute(vector<int> &nums) {
        vector<bool> y已访问位置(nums.size(), false);
        h回溯函数(nums, y已访问位置);
        return q全排列结果;
    }
};

int main() {

    return 0;
}