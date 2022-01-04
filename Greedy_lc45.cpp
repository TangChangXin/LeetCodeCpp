//
// Created by XKA on 2021/11/9.
//

#include <vector>
using namespace std;

class Solution45 {
public:
    //第一次做基本没思路，看了随想录
    int jump(vector<int>& nums) {
        //注意初始化“d当前最大边界”为0，然后在访问第一个元素时更新边界并且
        int s数组长度 = nums.size(), d当前最大边界 = 0, x下一次最大边界 = 0, t跳跃次数 = 0;
        //注意这里只访问到倒数第二个元素
        for (int i = 0; i < s数组长度 - 1; ++i) {
            //在每一次的跳跃范围中选择一个在下一次跳跃时能到达的最远边界作为新的右边界
            x下一次最大边界 = max(x下一次最大边界, i + nums[i]);
            if (i == d当前最大边界) {
                ++t跳跃次数; //只要到达边界就加1
                d当前最大边界 = x下一次最大边界; //扩展边界
            }
        }

        return t跳跃次数;
    }
};