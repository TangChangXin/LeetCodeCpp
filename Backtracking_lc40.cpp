//
// Created by XKA on 2021/8/24. 中等 组合总和 II
//

#include <vector>
#include <algorithm>
using namespace std;

class Solution40 {
public:
    //第一次做 大致思路没问题，但是在去重细节上还需要再多考虑
    vector<vector<int>> z组合结果;
    vector<int> l路径;

    //2022年2月1日，去重没写好，我写的方法超时了。
    void h回溯函数2(vector<int> &z整数数组, int m目标数, int l临时和, int q起始位置) {
        if (l临时和 == m目标数) {
            z组合结果.push_back(l路径);
            return;
        }
        if (l临时和 > m目标数) return;
        for (int i = q起始位置; i < z整数数组.size() && l临时和 + z整数数组[i] <= m目标数; ++i) {
            //从起始位置开始在同一层循环内去重可以避免出现相同的组合。
            if (i > q起始位置 && z整数数组[i - 1] == z整数数组[i]) continue;
            l路径.push_back(z整数数组[i]);
            l临时和 += z整数数组[i];
            //进入下层递归时起始位置加1，可以防止在同一个位置的元素重复使用。
            h回溯函数2(z整数数组, m目标数, l临时和, i + 1);
            l路径.pop_back();
            l临时和 -= z整数数组[i];
        }
    }

    void h回溯函数(vector<int> &y源数组, int m目标和, int q起始位置, int l临时和){
        //源数组必须是升序排列的
        if (l临时和 == m目标和) {
            z组合结果.push_back(l路径);
            return;
        }

        // for(int i = q起始位置; i < c长度; ++i) 这样写会有重复的组合出现
        int c长度 = y源数组.size();
        for (int i = q起始位置; i < c长度 && l临时和+y源数组[i] <= m目标和; ++i) {
            //跳过重复元素。例子：[1,1,1,2,2,5,5,6,7,10],目标和是8。
            //           下标  [0,1,2,3,4,5,6,7,8,9]
            //当起始位置从0开始，且已经取得了路径为[1,2,5]的组合，经过回溯后路径为[1,2]
            //                           下标[0,3,5]                下标[0,3]
            //这时如果不跳过重复元素,直接开始下一次for循环,那么会得到路径[1,2,5]的组合，这和之前的组合重复了
            //                                             下标[0,3,6]

            if (i > q起始位置 && y源数组[i-1] == y源数组[i])
                continue; //如果使用这种方式去重，那么在进入for循环的时候就有下标范围判断，在循环体中不需要额外判断，这样更好。
            //下面写法报错，因为即使在这里“i大于或等于c长度”导致退出了while循环，但是下面的语句中依然会出现下标越界的错误，下面的语句又需要额外下标范围判断。
            //while (i < c长度 && i > q起始位置 && y源数组[i-1] == y源数组[i]) ++i;
            l临时和 += y源数组[i];
            l路径.push_back(y源数组[i]);
            h回溯函数(y源数组, m目标和, i+1, l临时和);
            l临时和 -= y源数组[i];
            l路径.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); //对数组进行排序，防止出现重复组合
        h回溯函数(candidates, target, 0, 0);
        return z组合结果;
    }
};