// Q55: Balanced Binary Tree.
// Description: Given a root node of a binary tree, tell if it is balanced tree.
// Balanced tree is defined as its left subtree and righht subtree depth difference
// not exceeds 1.

#include <bits/stdc++.h>
#include "./utils/TreeNode.h"

using namespace std;

bool IsBalancedTreeCore(TreeNode* root, int* depth);

bool IsBalancedTree(TreeNode* root) {
    int depth = 0;
    return IsBalancedTreeCore(root, &depth);
}

bool IsBalancedTreeCore(TreeNode* root, int* depth) {
    if (root == nullptr) {
        depth = 0;
        return true;
    }

    int left_depth = 0;
    int right_depth = 0;
    bool flag = IsBalancedTreeCore(root->left, &left_depth) &&
                IsBalancedTreeCore(root->right, &right_depth);

    if (flag) {
        int diff = abs(left_depth - right_depth);
        if (diff <= 1) {
            *depth = 1 + (left_depth > right_depth ? left_depth : right_depth);
            return true;
        }
    }
    return false;
}

void Test(const char* test_name, TreeNode* root, bool expected) {
    if (IsBalancedTree(root) == expected) {
        printf("%s: Passed.\n", test_name);
    } else {
        printf("%s: FAILED.\n", test_name);
    }
}


void Test1() {
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n3 = new TreeNode(3, n6, nullptr);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5, n7, nullptr);
    TreeNode* n2 = new TreeNode(2, n4, n5);
    TreeNode* n1 = new TreeNode(1, n2, n3);

    Test("Test 1", n1, true);
    DestroyTree(n1);
}

void Test2() {
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5, n6, nullptr);
    TreeNode* n2 = new TreeNode(2, n4, n5);
    TreeNode* n1 = new TreeNode(1, n2, n3);

    Test("Test 2", n1, false);
    DestroyTree(n1);
}

void Test3() {
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n4 = new TreeNode(4, nullptr, n5);
    TreeNode* n3 = new TreeNode(3, nullptr, n4);
    TreeNode* n2 = new TreeNode(2, nullptr, n3);
    TreeNode* n1 = new TreeNode(1, nullptr, n2);

    Test("Test 3", n1, false);
    DestroyTree(n1);
}

void Test4() {
    TreeNode* n1 = new TreeNode(1);

    Test("Test 3", n1, true);
    DestroyTree(n1);
}

void Test5() {
    Test("Test 4", nullptr, true);
}

int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}