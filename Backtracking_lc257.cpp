//
// Created by XKA on 2021/10/26. 简单 68.4
//
#include <vector>
#include <string>
#include "Tree_lc94.cpp"

using namespace std;

class Solution257 {
public:
    vector<string> j结果;

    void h回溯函数(TreeNode *root, vector<char> &j节点链) {
        j节点链.push_back(root->val);
        //如果将节点加入节点链的语句写在这句判断的后面，那么会导致最后一个节点无法加入节点链。
        if (root->left == nullptr && root->right == nullptr)
        {
            string l路径;
            //这个只添加了到了倒数第二个节点
            for (int i = 0; i < j节点链.size() - 1; ++i) {
                l路径 += to_string(j节点链[i]);
                l路径 += "->";
            }
            l路径 += to_string(j节点链.back());
            j结果.push_back(l路径);
            return;
        }

        if (root->left != nullptr) {
            h回溯函数(root->left, j节点链);
            j节点链.pop_back();
        }
        if (root->right!= nullptr) {
            h回溯函数(root->right, j节点链);
            j节点链.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode *root) {
        if (root == nullptr) return j结果;
        vector<char> j节点链;
        h回溯函数(root, j节点链);
        return j结果;
    }
};

int main() {
    TreeNode t5 = TreeNode(5, nullptr, nullptr), t2 = TreeNode(2, nullptr, &t5);
    TreeNode t3 = TreeNode(3, nullptr, nullptr), t1 = TreeNode(1, &t2, &t3);
    Solution257 ce;
    ce.binaryTreePaths(&t1);
    cout << ce.j结果[0];
    return 0;
}