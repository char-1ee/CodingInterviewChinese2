#ifndef TREENODE_H
#define TREENODE_H

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

void PrintTree(const TreeNode* root);
void DestroyTree(TreeNode* root); 

#endif