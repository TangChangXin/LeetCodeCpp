//
// Created by XK on 2022/1/25.
//

#include <string>
#include <iostream>
using namespace std;

class Solution415 {
public:
    //细节没完全想出来
    string addStrings(string num1, string num2) {
        int z指针1 = (int)num1.size() - 1, z指针2 = (int)num2.size() - 1, j进位 = 0;
        string j结果;
        while (z指针1 >= 0 || z指针2 >= 0 || j进位 != 0) {
            int j加数1, j加数2, h和;
            if (z指针1 == -1) j加数1 = 0;
            else {
                j加数1 = num1[z指针1] - '0';
                --z指针1;
            }
            if (z指针2 == -1) j加数2 = 0;
            else {
                j加数2 = num2[z指针2] - '0';
                --z指针2;
            }
            h和 = (j加数1 + j加数2 + j进位) % 10;
            j进位 = (j加数1 + j加数2 + j进位) / 10;
            j结果.push_back(h和 + '0');//我写的 j结果.push_back((char)h和);
        }
        reverse(j结果.begin(), j结果.end());
        return j结果;
    }
};

int main() {
    Solution415 qwer;
    string asdf = qwer.addStrings("123", "11");
    cout << asdf << endl;
    return 0;
}