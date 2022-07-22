// Q55: Tree depth.
// Description: Given a root of a binary tree, find the depth of the tree.
// The distance from root to leaf node is regarded as a path. Longest path is its depth.

#include <bits/stdc++.h>
#include "utils/TreeNode.h"

using namespace std;

int FindTreeDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int left_depth = FindTreeDepth(root->left);
    int right_depth = FindTreeDepth(root->right);

    return max(left_depth, right_depth) + 1;
}

void Test(const char* test_name, TreeNode* root, int expected) {
    if (FindTreeDepth(root) == expected) {
        printf("%s: passed.\n", test_name);
    } else {
        printf("%s: FAILED.\n", test_name);
    }
}

void Test1() {
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n5 = new TreeNode(5, n7, nullptr);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n2 = new TreeNode(2, n4, n5);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n3 = new TreeNode(3, nullptr, n6);
    TreeNode* n1 = new TreeNode(1, n2, n3);

    Test("Test 1", n1, 4);
    DestroyTree(n1);
}

void Test2() {
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n3 = new TreeNode(3, n4, nullptr);
    TreeNode* n2 = new TreeNode(2, n3, nullptr);
    TreeNode* n1 = new TreeNode(1, n2, nullptr);

    Test("Test 2", n1, 4);
    DestroyTree(n1);
}

void Test3() {
    TreeNode* n1 = new TreeNode(1);

    Test("Test 3", n1, 1);
    DestroyTree(n1);
}

void Test4() {
    Test("Test 4", nullptr, 0);
}

int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}