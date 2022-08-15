// Q54: K-th largest node in BST.
// Description: Given a binary search tree, find the k-th largest node among all node.
// Example: k = 3
//           5
//       3       7
//      2 4     6 8
// 3rd largest node is 4.

#include <bits/stdc++.h>
#include "utils/TreeNode.h"

using namespace std;

TreeNode* FindKthNodeCore(TreeNode* root, unsigned int& k);

// Inorder traversal
TreeNode* FindKthNode(TreeNode* root, unsigned int k) {
    if (root == nullptr || k < 1) {
        return nullptr;
    }

    return FindKthNodeCore(root, k);
}

// Traversal helper function
TreeNode* FindKthNodeCore(TreeNode* root, unsigned int& k) {
    TreeNode* target = nullptr;

    if (root->left != nullptr) {
        target = FindKthNodeCore(root->left, k);
    }

    if (target == nullptr) {
        if (k == 1) target = root;
        k--;
    }

    if (target == nullptr && root->right != nullptr) {
        target = FindKthNodeCore(root->right, k);
    }

    return target;
}

void Test(const char* test_name, TreeNode* root, unsigned int k, bool is_null, int expected) {
    TreeNode* result = FindKthNode(root, k);

    if (is_null || root == nullptr || (!is_null && result->val == expected)) {
        printf("%s: Passed.\n", test_name);
    } else {
        printf("%s: FAILED.\n", test_name);
    }
}

void Test1() {
    TreeNode* n1 = new TreeNode(5);
    TreeNode* n2 = new TreeNode(7);
    TreeNode* n3 = new TreeNode(6, n1, n2);
    TreeNode* n4 = new TreeNode(9);
    TreeNode* n5 = new TreeNode(11);
    TreeNode* n6 = new TreeNode(10, n4, n5);
    TreeNode* n7 = new TreeNode(8, n3, n6);

    Test("TestA0", n7, 0, true, -1);
    Test("TestA1", n7, 1, false, 5);
    Test("TestA2", n7, 2, false, 6);
    Test("TestA3", n7, 3, false, 7);
    Test("TestA4", n7, 4, false, 8);
    Test("TestA5", n7, 5, false, 9);
    Test("TestA6", n7, 6, false, 10);
    Test("TestA7", n7, 7, false, 11);
    Test("TestA8", n7, 8, true, -1);
}

void Test2() {
    Test("TestE0", nullptr, 0, true, -1);
    Test("TestE1", nullptr, 1, true, -1);
}

void Test3() {
    TreeNode* n1 = new TreeNode(1);

    Test("TestB0", n1, 0, true, -1);
    Test("TestB1", n1, 1, false, 1);
}

int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();

    return 0;
}
