#pragma once

#include <string>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

void PrintTree(const TreeNode* root);
void PrintTreeHelper(const TreeNode* root, std::string prefix, bool is_left);
void DestroyTree(TreeNode* root); 
