#ifndef LIST_H
#define LIST_H

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(-1), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

void AddToTail(ListNode** root, int new_value);

void PrintList(ListNode *root);

ListNode *CreateList(int values[], int length);

void DestroyList(ListNode *head);

#endif