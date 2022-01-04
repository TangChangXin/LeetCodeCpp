//
// Created by XKA on 2021/11/9.
//

#include <vector>
using namespace std;

class Solution376 {
public:
    //第一次做直接看的随想录，基本没啥思路
    int wiggleMaxLength(vector<int>& nums) {
        int s数组长度 = nums.size();
        if (s数组长度 < 2) return s数组长度;
        int c长度, q前差值 = nums[1] - nums[0];
        if (q前差值 != 0)
            c长度 = 2;
        else
            c长度 = 1;
        for (int i = 2; i < s数组长度; ++i) {
            int h后差值 = nums[i] - nums[i - 1];
            if ((h后差值 > 0 && q前差值 <= 0) || (h后差值 <0 && q前差值 >= 0)) {
                ++c长度;
                q前差值 = h后差值;
            }
        }
        return c长度;
    }
};

