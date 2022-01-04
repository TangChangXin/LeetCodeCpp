//
// Created by XKA on 2021/6/21.
//

#include <stack>
#include <string>
#include <unordered_map>
#include "Tree_lc94.cpp"
/*
 * 给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。
 * 两棵树重复是指它们具有相同的结构以及相同的结点值。
 *      1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
    递归方式，
 */
class Solution652 {
public:
    vector<TreeNode *> j结果;
    unordered_map<string, int> z子树重复次数;//unorders_map的下标操作返回的是关键字对应的值
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if (root == nullptr) return {};
        d递归序列化子树(root);
        return j结果;
    }

    string d递归序列化子树(TreeNode* root){
        if (root == nullptr) return "#";
        string z左子树 = d递归序列化子树(root->left);
        string y右子树 = d递归序列化子树(root->right);
        //下方得到了当前节点作为根节点时，树的形状。那么如何将重复的树存入一个列表并且保持树的唯一性。
        string d当前子树结果 = to_string(root->val)+','+z左子树+','+y右子树;

        //在“z子树重复次数”中如果没有“d当前子树结果”，那么会自动创建其对应的值，默认为指定类型的默认值，如指定int，那么默认为0

        //“z子树重复次数[d当前子树结果]“初始为0,即当前子树先不加入结果中，
        if (z子树重复次数[d当前子树结果] == 1) j结果.push_back(root);
        //初始为0然后增加到1，在之后的递归执行中，如果该子树又出现了，那么经过上面的if判断就会被加入到结果中。
        //然后从1增加到2，这样以后再出现这个子树也不会加入到结果中，避免了重复加入
        ++z子树重复次数[d当前子树结果];

        return d当前子树结果;
    }
};