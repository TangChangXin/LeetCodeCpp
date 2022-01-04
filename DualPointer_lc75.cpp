//
// Created by XKA on 2021/10/4. 第一次基本没什么思路
//
#include <vector>
using namespace std;

class Solution75 {
public:
    //使用一个指针，两次遍历来完成排序
    void 单指针两次遍历(vector<int> &nums) {
        int z指针 = 0, s数组长度 = nums.size();
        for (int &n : nums) {
            //当前访问的元素值为0，那么就交换到数组的前面
            if (n == 0) {
                swap(n, nums[z指针]);
                ++z指针;
            }
        }

        //上面的循环结束后，数组的前面全是0，下面的遍历实现将1排在0的后面，2的前面。
        for (int i = z指针; i < s数组长度; ++i) {
            if (nums[i] == 1) {
                swap(nums[i], nums[z指针]);
                ++z指针;
            }
        }
    }

    //两个指针分别从前后向中间遍历
    void 双指针一次遍历(vector<int> &nums) {
        int z指针0 = 0, z指针2 = nums.size() - 1;
        //注意结束条件
        for (int i = 0; i <= z指针2; ++i) {
            //假设数组全是2，那么“z指针2”最终会减小到-1，导致下标越界，所以加“i <= z指针2”限制
            while (i <= z指针2 && nums[i] == 2) {
                swap(nums[i], nums[z指针2]);
                --z指针2;
            }
            if (nums[i] == 0) {
                swap(nums[i], nums[z指针0]);
                ++z指针0;
            }
        }
    }

    void sortColors(vector<int>& nums) {

    }
};

int main() {
    int a[4] = {1, 2, 3, 4};
    for (int &n : a) {
        n += 2;
    }
    printf("%d\n", a[0]);


    return 0;
}