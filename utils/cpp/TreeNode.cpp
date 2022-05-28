#include <cstdio>;
#include <iostream>;
#include "TreeNode.h";

using namespace std;

void DestroyTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    TreeNode* left_tree = root->left;
    TreeNode* right_tree = root->right;

    delete root;
    root = nullptr;

    DestroyTree(left_tree);
    DestroyTree(right_tree);
}

void PrintTree(const TreeNode* root) {
    string prefix = "";
    bool is_left = true;

    PrintTreeHelper(root, prefix, is_left);
}

void PrintTreeHelper(const TreeNode* root, string prefix, bool is_left) {
    if (root == nullptr) {
        cout << "Empty Tree" << endl;
        return;
    }

    if (root->right != nullptr) {
            string new_prefix = prefix + (is_left ? "    " : "   |");
            PrintTreeHelper(root->right, new_prefix, true);
        }

    cout << prefix + (is_left ? "└── " : "┌── ") + to_string(root->val) + "\n";

    if (root->left != nullptr) {
        string new_prefix = prefix + (is_left ? "|   " : "    ");
        PrintTreeHelper(root->left, new_prefix, false);
    }
}