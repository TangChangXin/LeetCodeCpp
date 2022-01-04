//
// Created by XKA on 2021/10/9.
//

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution60 {
public:
    //第一次做
    string s数字集合 = "123456789";
    vector<string> p排列结果;
    string l路径;
    void h回溯函数(int n, int k, int &d第几次) {
        if (l路径.size() == n) {
            p排列结果.push_back(l路径);
            ++d第几次;
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (find(l路径.begin(), l路径.end(), s数字集合[i]) != l路径.end()) continue;
            l路径.push_back(s数字集合[i]);
            h回溯函数(n, k, d第几次);
            if (k == d第几次) {
                for (auto j : l路径)
                    cout << j;
                cout << "\n";
                break;
            }
            l路径.pop_back();
        }
    }

    string getPermutation(int n, int k) {
        int d第几次 = 0;
        h回溯函数(n, k, d第几次);
        return p排列结果[k - 1];
    }
};

//void digui(int n, int k, int &ab) {
//    for (int i = 1; i < ; ++i) {
//
//    }
//}

int main() {
    Solution60 Atest;
    Atest.getPermutation(4, 9);
    return 0;
}
