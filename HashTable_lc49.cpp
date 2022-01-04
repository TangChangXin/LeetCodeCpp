//
// Created by XKA on 2021/8/28. 中等 字母异位词分组
//

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution49 {
public:
    //第一次做，这个方法时间复杂度高 O(nklogk)
    //链接：https://leetcode-cn.com/problems/group-anagrams/solution/kan-wo-yi-ju-hua-ac-zi-mu-yi-wei-ci-fen-yrnis/
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> y异位词组合; //利用排序后的字符串作为键，将符合条件的字符串加入值中。
        for (auto str:strs){
            string j键 = str;
            sort(j键.begin(), j键.end()); //对访问的字符串排序
            y异位词组合[j键].push_back(str); //
        }

        vector<vector<string>> z组合结果;
        for (auto it = y异位词组合.begin();it != y异位词组合.end();++it){
            z组合结果.push_back(it->second);
        }
//        for (auto & it : y异位词组合){
//            z组合结果.push_back(it.second);
//        }

        return z组合结果;
    }

    //时间复杂度更低的方法
};