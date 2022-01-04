//
// Created by XKA on 2021/7/10.
//

//中等 在排序数组中查找元素的第一个和最后一个位置
//相当于确定二分查找的左侧边界或者右侧边界
#include <vector>

using namespace std;

class Solution34 {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> 结果;
        int 第一个位置 = 左侧边界(nums, target);
        int 最后的位置 = 右侧边界(nums, target);
        结果.push_back(第一个位置);
        结果.push_back(最后的位置);
        return 结果;
    }

    int 左侧边界(vector<int> &nums, int target) {
        if (nums.empty()) return -1;
        int z左 = 0, y右 = (int)nums.size() - 1;
        //注意循环结束条件的判断。结束时 左=右+1
        while (z左 <= y右) {
            int z中间 = z左 + (y右 - z左) / 2;//避免 左+右 过大造成溢出
            if (nums[z中间] < target) z左 = z中间 + 1;
            else y右 = z中间 - 1;//中间值大于或等于目标值时，都将 y右 = z中间-1 作为新的右边界，画图理解。
        }

        //庸才顾子汐的方法，默认没找到额外判断找到了
        if (z左 != nums.size() && nums[z左] == target) {
            return z左; //如果数组中能够找到目标的话，那么必然是nums[z左] == target且 0<=z左<=nums.size()-1
        }

//        if (nums[z左] == target) {
//            //如果目标小于数组值，则最终直接比较“nums[z左] == target”即可，不用越界判断
//            //这样写报错了，因为目标大于数组值时，z左 = z中间 + 1，这样左边界不断向右移动，最终“左”会越界，“左”等于“nums.size()”。举例运行理解
//            return z左;
//        }
        return -1;
    }

    int 右侧边界(vector<int> &nums, int target) {
        if (nums.empty()) return -1;
        int z左 = 0, y右 = (int)nums.size() - 1;
        while (z左 <= y右){
            int z中间 = z左 + (y右 - z左) / 2;//避免 左+右 过大造成溢出
            if (nums[z中间] > target) y右 = z中间-1;
            else z左 = z中间+1;//中间值小于或等于目标值时，都将 z左 = z中间+1 作为新的左边界，画图理解。
        }

        //庸才顾子汐的方法，默认没找到额外判断找打了
        if (y右 != -1 && nums[y右] == target) {
            return y右;
        }

//        if (nums[y右] == target) {
//            //如果目标大于数组值，则最终直接比较“nums[y右] == target”即可，不用越界判断
//            //这样写报错了，因为目标小于数组值时，y右 = z中间-1，这样右边界不断向左移动，最终“右”会越界，“右”等于“-1”。举例运行理解
//            return y右;
//        }
        return -1;
    }
};