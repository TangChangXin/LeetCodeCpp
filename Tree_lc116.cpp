//
// Created by XK on 2021/5/31. 中等 70.5%
//

#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution116 {
public:
    //第二次做，之前做了但是没提交
    Node* connect(Node* root) {
        queue<Node *> s树层;
        if (root != nullptr) s树层.push(root);

        while (!s树层.empty()) {
            int d大小 = s树层.size();
            for (int i = 0; i < d大小; ++i) {
                Node *d当前节点 = s树层.front();
                s树层.pop();
                if (i < d大小 - 1) d当前节点->next = s树层.front();

                if (d当前节点->left) s树层.push(d当前节点->left);
                if (d当前节点->right) s树层.push(d当前节点->right);
            }
        }
        return root;
    }

    // labuladong的算法小抄 递归方法
    Node *算法小抄(Node *root) {
        if (root == nullptr || root->left == nullptr) return nullptr;
        l连接两结点(root->left, root->right); //看下方的函数
        return root;
    }

    //定义一个函数,传入两个结点并且认为这两个结点有同一个父结点，连接传入的两个结点
    void l连接两结点(Node *j结点1, Node *j结点2){
        if (j结点1 == nullptr || j结点2 == nullptr) return;
        j结点1->next = j结点2;// 连接两个结点

        //递归调用，连接相同父结点的两个子结点
        l连接两结点(j结点1->left, j结点1->right);
        l连接两结点(j结点2->left, j结点2->right);
        //递归调用，连接不同父结点的两个子结点，这两个结点各自的父结点的父结点是同一个
        l连接两结点(j结点1->right, j结点2->left);
    }
};