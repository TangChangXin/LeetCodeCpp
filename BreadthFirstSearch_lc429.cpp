//
// Created by XKA on 2021/10/20. 中等 70%
//
#include <vector>
#include <queue>

using namespace std;

class NNode {
public:
    int val;
    vector<NNode *> children;

    NNode() {}

    NNode(int _val) {
        val = _val;
    }

    NNode(int _val, vector<NNode *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution429 {
public:
    //注意NNode，是为了避免类冲突实际应该是Node
    vector<vector<int>> levelOrder(NNode *root) {
        queue<NNode *> que;
        if (root != nullptr) que.push(root);
        vector<vector<int>> result;

        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; ++i) {
                NNode *Nnode = que.front();
                que.pop();
                vec.push_back(Nnode->val);

                for (int j = 0; j < Nnode->children.size(); ++j) {
                    if (Nnode->children[j]) que.push(Nnode->children[j]);
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};

int main() {
    Solution429 aaa;

    return 0;
}