// Q52: First common node of two linked lists
// Description: Given two linked lists, find the first node that they cross.

#include "./utils/List.h"
#include <bits/stdc++.h>

using namespace std;

unsigned int GetListLength(ListNode *head);
void GC(ListNode *node);

// Solution 1: time O(m + n), space O(m + n)
ListNode *FindFirstCommonNode_solution1(ListNode *head1, ListNode *head2) {
    if (head1 == nullptr || head2 == nullptr) return nullptr;

    stack<ListNode *> s1;
    stack<ListNode *> s2;

    ListNode *curr1 = head1;
    ListNode *curr2 = head2;
    while (curr1 != nullptr) {
        s1.push(curr1);
        curr1 = curr1->next;
    }
    while (curr2 != nullptr) {
        s2.push(curr2);
        curr2 = curr2->next;
    }

    ListNode *res = new ListNode();
    while (!s1.empty() && !s2.empty()) {
        ListNode *node1 = s1.top();
        ListNode *node2 = s2.top();
        if (node1 == node2) {
            res = node1;
        }
        s1.pop();
        s2.pop();
    }

    // If no common node then return nullptr
    return res;
}

// Solution 2: time O(m + n), space O(1)
ListNode *FindFirstCommonNode_solution2(ListNode *head1, ListNode *head2) {
    if (!head1 || !head2) return nullptr;

    unsigned int l1_length = GetListLength(head1);
    unsigned int l2_length = GetListLength(head2);
    int diff = 0; // length difference of two lists

    ListNode *long_node = head1;  // iterating node of long list
    ListNode *short_node = head2; // iterating node of short list

    if (l1_length < l2_length) {
        diff = l2_length - l1_length;
        short_node = head1;
        long_node = head2;
    }

    for (int i = diff; i > 0; --i) {
        long_node = long_node->next;
    }

    ListNode *res = new ListNode();
    while (long_node && short_node) {
        if (long_node == short_node) {
            res = long_node;
            break;
        }
        long_node = long_node->next;
        short_node = short_node->next;
    }

    return res;
}

unsigned int GetListLength(ListNode *head) {
    if (head == nullptr) return 0;

    int cnt = 0;
    ListNode *curr = head;
    while (curr != nullptr) {
        curr = curr->next;
        cnt++;
    }
    return cnt;
}

void Test(string test_name, ListNode *head1, ListNode *head2,
          ListNode *expected) {
    ListNode *result1 = FindFirstCommonNode_solution1(head1, head2);
    if (result1 == expected) {
        cout << test_name << ": Passed" << endl;
    } else {
        cout << test_name << ": FAILED" << endl;
    }

    ListNode *result2 = FindFirstCommonNode_solution2(head1, head2);
    if (result2 == expected) {
        cout << test_name << ": Passed" << endl;
    } else {
        cout << test_name << ": FAILED" << endl;
    }
}

void Test1() {
    ListNode *n7 = new ListNode(7);
    ListNode *n6 = new ListNode(6, n7);
    ListNode *n5 = new ListNode(5, n6);
    ListNode *n4 = new ListNode(4, n5);
    ListNode *n3 = new ListNode(3, n6);
    ListNode *n2 = new ListNode(2, n3);
    ListNode *n1 = new ListNode(1, n2);

    Test("Test 1", n1, n4, n6);

    GC(n1);
    GC(n2);
    GC(n3);
    GC(n4);
    GC(n5);
    GC(n6);
    GC(n7);
}

void Test2() {
    ListNode *n4 = new ListNode(4);
    ListNode *n3 = new ListNode(3, n4);
    ListNode *n2 = new ListNode(2, n3);
    ListNode *n1 = new ListNode(1, n2);

    ListNode *n7 = new ListNode(7);
    ListNode *n6 = new ListNode(6, n7);
    ListNode *n5 = new ListNode(5, n6);

    Test("Test 2", n1, n5, nullptr);

    // DestroyList(n1);
    // DestroyList(n5);
}

void GC(ListNode *node) {
    delete node;
    node = nullptr;
}

int main(int argc, char *argv[]) {
    Test1();
    Test2();

    return 0;
}
