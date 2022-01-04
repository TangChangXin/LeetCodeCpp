//
// Created by XK on 2021/6/1.
//

//中等 二叉树展开为链表
#include <iostream>
#include "Tree_lc94.cpp"

using namespace std;

class Solution114 {
public:
    //网友题解法，很巧妙
    //①从根结点开始，对于每个结点而言
    void w网友题解(TreeNode *root){
        //深度优先搜索方法
        while (root != nullptr){
            if (root->left == nullptr)root = root->right;
            else{
                TreeNode *l临时右结点 = root->right;//用一个临时结点保存右子树
                root->right = root->left;//将左子树移动到右子树位置
                root->left = nullptr;
                TreeNode *l临时结点 = root->right;
                //用一个临时结点遍历到新右子树的最右子结点，再将原来的右子树接到这个最右子结点后面
                while (l临时结点->right != nullptr)
                    l临时结点 = l临时结点->right;
                l临时结点->right = l临时右结点;
            }
            root = root->right;
        }
    }

    //看了算法小抄
    void h后序遍历递归(TreeNode *root) {
        if (root == nullptr)return;
        h后序遍历递归(root->left);
        h后序遍历递归(root->right);
        //这种形式有点儿类似于后序遍历操作
        //认为当前根结点的左右子结点分别已经展开为链表，那么再处理当前根结点即可
        TreeNode *l临时左结点 = root->left;
        TreeNode *l临时右结点 = root->right;
        root->left = nullptr;
        root->right = l临时左结点;
        TreeNode *d当前结点 = root;
        while (d当前结点->right != nullptr){
            d当前结点 = d当前结点->right;
        }
        d当前结点->right = l临时右结点;
    }

    //递归法前序遍历并保存每个树结点到一个容器中，然后再从容器中一个一个取出结点连接成链表。性能差，花费的空间多
    void q前序遍历保存到栈(TreeNode *g根结点, vector<TreeNode *> &s树数组){
        if (g根结点 == nullptr) return;
        s树数组.push_back(g根结点);
        q前序遍历保存到栈(g根结点->left, s树数组);
        q前序遍历保存到栈(g根结点->right, s树数组);
    }

    void 递归函数加额外栈(TreeNode *root) {
        vector<TreeNode *> z暂存树结点;
        q前序遍历保存到栈(root, z暂存树结点);
        TreeNode *d当前结点 = root;
        int j结点总数 = z暂存树结点.size();
        for (int i = 1; i < j结点总数; ++i) {
            d当前结点->left = nullptr;
            d当前结点->right = z暂存树结点[i];
            d当前结点 = d当前结点->right;
        }
    }
};