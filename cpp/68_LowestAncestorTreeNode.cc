// Q68: Lowest ancestor nodes in tree.
// Description: Given root node and two nodes in tree, find the lowest ancestor node of these two
// in-tree nodes.
// When the tree is BST -> inorder traversal.
// When the tree is Binary Tree, and assume each node has a link to its parent node -> find the
// first common node.
// What if the tree is not binary tree?

#include <bits/stdc++.h>
#include "utils/TreeNode.h"

using namespace std;

// Return the path from root to target node
bool FindPath(Node* head, Node* target, list<Node*>& path) {
    if (head == target) return true;

    bool found = false;
    path.push_back(head);
    auto it = head->children.begin();

    // Iterate all children nodes of head node
    while (!found && it < head->children.end()) {
        found = FindPath(*it, target, path);
        it++;
    }

    // Children all iterated but still not found -> backtrack
    if (!found) {
        path.pop_back();
    }

    return found;
}

// Find the common node from root
Node* FindLastCommonNode(const list<Node*>& path1, const list<Node*>& path2) {
    auto it1 = path1.begin();
    auto it2 = path2.begin();
    Node* node = nullptr;
    
    while (it1 != path1.end() && it2 != path2.end()) {
        if (*it1 == *it2) {
            node = *it1;
        }
        it1++;
        it2++;
    }
    return node;
}

// Main function
Node* LowestAncestorNode(Node* root, Node* node1, Node* node2) {
    if (!root || !node1 || !node2) return nullptr;

    list<Node*> path1, path2;
    FindPath(root, node1, path1);
    FindPath(root, node2, path2);

    return FindLastCommonNode(path1, path2);
}

void Test(const char* testName, Node* pRoot, Node* pNode1, Node* pNode2, Node* pExpected) {
    Node* pResult = LowestAncestorNode(pRoot, pNode1, pNode2);

    if((pExpected == nullptr && pResult == nullptr) || 
        (pExpected != nullptr && pResult != nullptr && pResult->val == pExpected->val))
        printf("%s Passed.\n", testName);
    else
        printf("%s Failed.\n", testName);
}

// Functional test
//              1
//            /   \
//           2     3
//       /       \
//      4         5
//     / \      / |  \
//    6   7    8  9  10
void Test1() {
    Node* pNode1 = CreateTreeNode(1);
    Node* pNode2 = CreateTreeNode(2);
    Node* pNode3 = CreateTreeNode(3);
    Node* pNode4 = CreateTreeNode(4);
    Node* pNode5 = CreateTreeNode(5);
    Node* pNode6 = CreateTreeNode(6);
    Node* pNode7 = CreateTreeNode(7);
    Node* pNode8 = CreateTreeNode(8);
    Node* pNode9 = CreateTreeNode(9);
    Node* pNode10 = CreateTreeNode(10);

    ConnectTreeNodes(pNode1, pNode2);
    ConnectTreeNodes(pNode1, pNode3);

    ConnectTreeNodes(pNode2, pNode4);
    ConnectTreeNodes(pNode2, pNode5);

    ConnectTreeNodes(pNode4, pNode6);
    ConnectTreeNodes(pNode4, pNode7);

    ConnectTreeNodes(pNode5, pNode8);
    ConnectTreeNodes(pNode5, pNode9);
    ConnectTreeNodes(pNode5, pNode10);

    Test("Test1", pNode1, pNode6, pNode8, pNode2);
}

// A linked list.
//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test2() {
    Node* pNode1 = CreateTreeNode(1);
    Node* pNode2 = CreateTreeNode(2);
    Node* pNode3 = CreateTreeNode(3);
    Node* pNode4 = CreateTreeNode(4);
    Node* pNode5 = CreateTreeNode(5);

    ConnectTreeNodes(pNode1, pNode2);
    ConnectTreeNodes(pNode2, pNode3);
    ConnectTreeNodes(pNode3, pNode4);
    ConnectTreeNodes(pNode4, pNode5);

    Test("Test2", pNode1, pNode5, pNode4, pNode3);
}

// A linked list with one node oot in tree.
//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test3() {
    Node* pNode1 = CreateTreeNode(1);
    Node* pNode2 = CreateTreeNode(2);
    Node* pNode3 = CreateTreeNode(3);
    Node* pNode4 = CreateTreeNode(4);
    Node* pNode5 = CreateTreeNode(5);

    ConnectTreeNodes(pNode1, pNode2);
    ConnectTreeNodes(pNode2, pNode3);
    ConnectTreeNodes(pNode3, pNode4);
    ConnectTreeNodes(pNode4, pNode5);

    Node* pNode6 = CreateTreeNode(6);

    Test("Test3", pNode1, pNode5, pNode6, nullptr);
}

// Nullptr
void Test4() {
     Test("Test4", nullptr, nullptr, nullptr, nullptr);
}

int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}