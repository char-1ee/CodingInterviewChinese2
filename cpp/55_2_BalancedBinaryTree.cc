// Q55: Balanced Binary Tree.
// Description: Given a root node of a binary tree, tell if it is height balanced.
// Balanced tree is defined as its left subtree and righht subtree depth difference
// not exceeds 1.

#include <bits/stdc++.h>
#include "./utils/TreeNode.h"

using namespace std;

bool IsBalancedTreeCore(TreeNode* root, int* depth);

// ===== Method 1 =====
bool IsBalancedTree_Solution1(TreeNode* root) {
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

// ===== Method 2 =====
int Depth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(Depth(root->left), Depth(root->right));
}

bool IsBalancedTree_Solution2(TreeNode* root) {
    if (!root) return true;
    if (abs(Depth(root->left) - Depth(root->right)) <= 1) {
        return false;
    }
    return IsBalancedTree_Solution2(root->right) && IsBalancedTree_Solution2(root->left);
}

// ===== Test =====
void Test(const char* test_name, TreeNode* root, bool expected) {
    if (IsBalancedTree_Solution1(root) == expected) {
        printf("Solution 1: Passed.\n");
    } else {
        printf("Solution 1: FAILED.\n");
    }

    if (IsBalancedTree_Solution2(root) == expected) {
        printf("Solution 1: Passed.\n");
    } else {
        printf("Solution 1: FAILED.\n");
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
    // DestroyTree(n1);
}

void Test2() {
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5, n6, nullptr);
    TreeNode* n2 = new TreeNode(2, n4, n5);
    TreeNode* n1 = new TreeNode(1, n2, n3);

    Test("Test 2", n1, false);
    // DestroyTree(n1);
}

void Test3() {
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n4 = new TreeNode(4, nullptr, n5);
    TreeNode* n3 = new TreeNode(3, nullptr, n4);
    TreeNode* n2 = new TreeNode(2, nullptr, n3);
    TreeNode* n1 = new TreeNode(1, nullptr, n2);

    Test("Test 3", n1, false);
    // DestroyTree(n1);
}

void Test4() {
    TreeNode* n1 = new TreeNode(1);

    Test("Test 3", n1, true);
    // DestroyTree(n1);
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