//
// Created by XKA on 2021/11/10.
//
#include <vector>

using namespace std;

class Solution135 {
public:
    //第一次做，大体思路没问题，注意遍历时左右两侧孩子糖果数量的小细节
    int candy(vector<int> &ratings) {
        int h孩子总数 = ratings.size();
        vector<int> m每个孩子得到的糖果 (h孩子总数, 1);
        //从前向后遍历，若右边的分数比左边的分数高，则右边孩子的糖果比左边孩子的糖果多一
        for (int i = 0; i < h孩子总数 - 1; ++i) {
            if (ratings[i] < ratings[i + 1])
                m每个孩子得到的糖果[i + 1] = m每个孩子得到的糖果[i] + 1;
        }
        for (int i = h孩子总数 - 1; i > 0; --i) {
            //注意从后向前遍历比较分数的高低时，若第“i-1”个孩子比左右两侧的孩子分数都高，在从前向后的遍历过程中第“i-1”个孩子的糖果数可能比右侧孩子不只多一个
            //所以如果用我之前想的“i-1”糖果数等于右侧加一的话，那显然是错的。
            if (ratings[i - 1] > ratings[i])
                m每个孩子得到的糖果[i - 1] = max(m每个孩子得到的糖果[i - 1], m每个孩子得到的糖果[i] + 1);
        }
        int t糖果总数 = 0;
        for (auto i : m每个孩子得到的糖果)
            t糖果总数 += i;
        return t糖果总数;
    }
};