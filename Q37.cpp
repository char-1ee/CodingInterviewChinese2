// Serialize and deserialize a binary tree

#include <cstdio>
#include <iostream>
#include <sstream>
#include "utils/cpp/TreeNode.h"

using namespace std;

void SerializeHelper(const TreeNode* root, ostringstream& out_stream);
TreeNode* DeserializeHelper(istringstream& in_stream);

string Serialize(const TreeNode* root) {
    ostringstream out_stream;
    SerializeHelper(root, out_stream);
    return out_stream.str();
}

void SerializeHelper(const TreeNode* root, ostringstream& out_stream) {
    if (root == nullptr) {
        out_stream << "$ ";
        return;
    }

    out_stream << root->val << ' ';
    SerializeHelper(root->left, out_stream);
    SerializeHelper(root->right, out_stream);
}

TreeNode* Deserialize(const string data) {
    istringstream in_stream(data);
    return DeserializeHelper(in_stream); 
}

TreeNode* DeserializeHelper(istringstream& in_stream) {
    string s;
    in_stream >> s;

    if (s == "$") {
        return nullptr;
    }

    TreeNode* root = new TreeNode(stoi(s));
    root->left = DeserializeHelper(in_stream);
    root->right = DeserializeHelper(in_stream);
    return root;
}

// ========= Testing ==========
bool isSameTree(const TreeNode* root1, const TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr) { // terminal condition
        return true;
    }

    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }

    if (root1->val != root2->val) {
        return false;
    }

    return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
}

void Test(const string test_name, const TreeNode* root) {
    cout << "------" << test_name << "------" << endl;

    TreeNode* new_root = Deserialize(Serialize(root));

    if (isSameTree(root, new_root)) {
        cout << "Passed" << endl;
    } else {
        cout << "FAILED" << endl;
    }

    DestroyTree(new_root); // TODO: undefined reference to DestroyTree(TreenNode*)
}

void Test1() {
    TreeNode* node1 = new TreeNode(5);
    TreeNode* node2 = new TreeNode(7);
    TreeNode* node3 = new TreeNode(9);
    TreeNode* node4 = new TreeNode(11);
    TreeNode* node5 = new TreeNode(6, node1, node2);
    TreeNode* node6 = new TreeNode(10, node3, node4);
    TreeNode* node7 = new TreeNode(8, node5, node6);

    Test("Test 1", node7);

    DestroyTree(node7);
}

void Test2() {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2, node1, nullptr);
    TreeNode* node3 = new TreeNode(3, node2, nullptr);
    TreeNode* node4 = new TreeNode(4, node3, nullptr);
    TreeNode* node5 = new TreeNode(5, node4, nullptr);

    Test("Test 2", node5);

    DestroyTree(node5);
}

void Test3() {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2, nullptr, node1);
    TreeNode* node3 = new TreeNode(3, nullptr, node2);
    TreeNode* node4 = new TreeNode(4, nullptr, node3);
    TreeNode* node5 = new TreeNode(5, nullptr, node4);

    Test("Test 3", node5);

    DestroyTree(node5);
}

void Test4() {
    TreeNode* node = new TreeNode(1);

    Test("Test 4", node);

    DestroyTree(node);
}

void Test5() {
    Test("Test 5", nullptr);
}

// unti testing
int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}
