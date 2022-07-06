#include <cstdio>
#include <iostream>
#include "List.h"

// Insert a new node into the end of list
void AddToTail(ListNode** root, int new_value) {
    ListNode* node = new ListNode(new_value);

    if (*root == nullptr) {
        *root = node;
    } else {
        ListNode* tmp = *root;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = node;
    }
}

// Print out the list
void PrintList(ListNode* root) {
    if (root == nullptr) {
        std::cout << "Empty" << std::endl;
    }

    ListNode* curr = root;
    while (curr->next != nullptr) {
        std::cout << curr->val << "->";
        curr = curr->next;
    }
    std::cout << curr->val << std::endl;
}   

// Create a linked list given a value list
ListNode* CreateList(int values[], int length) {
    if (values == nullptr || length < 1) {
        return nullptr;
    }

    ListNode *head = new ListNode();
    ListNode *curr = head;

    for (int i = 0; i < length; i++) {
        ListNode* node = new ListNode(values[i]);
        curr->next = node;
        curr = node;
    }

    return head->next;
}

// Destroy the list
void DestroyList(ListNode* head) {
    ListNode *curr = head;
    while (curr != nullptr) {
        head = head->next;
        delete head;
        curr = head;
    }
}