#ifndef TREENODE_H
#define TREENODE_H

#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(-1), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

struct Node {
    int val;
    std::vector<Node*> children;
};

void PrintTree(const TreeNode* root);
void DestroyTree(TreeNode* root);
Node* CreateTreeNode(int val);
void ConnectTreeNodes(Node* root, Node* child);

#endif