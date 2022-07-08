// Q53: Find a number's occurences in a sorted array.
// Description: Count number of occurences of a given number in a sorted array.
// Example: {1, 2, 3, 3, 3, 4, 5} and number 3, return 3.

#include <bits/stdc++.h>

using namespace std;

int FindFirstOccurrence(int* data, int length, int target) {
    int left = 0;
    int right = length;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (data[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return right;
}

int FindLastOccurrence(int* data, int length, int target) {
    int left = 0;
    int right = length;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (data[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return right - 1;
}

int CountNumberOccurrences(int* data, int length, int target) {
    if (data == nullptr || length < 1) return 0;
    if (length == 1) return target == data[0] ? 1 : 0;

    int count = 0;
    int first_occurrence = FindFirstOccurrence(data, length, target);
    int last_occurrence = FindLastOccurrence(data, length, target);

    if (first_occurrence > -1 && last_occurrence > -1) {
        count = last_occurrence - first_occurrence + 1;
    }
    return count;
}

// Test method
void Test(string test_name, int* data, int length, int target, int expected) {
    if (CountNumberOccurrences(data, length, target) == expected) {
        cout << test_name << ": Passed." << endl;
    } else {
        cout << test_name << ": FAILED." << endl;
    }
}

// Target found in between of array
void Test1() {
    int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
    Test("Test1", data, sizeof(data) / sizeof(int), 3, 4);
}

// Target found at the beginning of array
void Test2() {
    int data[] = {3, 3, 3, 3, 4, 5};
    Test("Test2", data, sizeof(data) / sizeof(int), 3, 4);
}

// Taregt found in the end of array
void Test3() {
    int data[] = {1, 2, 3, 3, 3, 3};
    Test("Test3", data, sizeof(data) / sizeof(int), 3, 4);
}

// target not found
void Test4() {
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test4", data, sizeof(data) / sizeof(int), 2, 0);
}

// Target smaller than min array
void Test5() {
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test5", data, sizeof(data) / sizeof(int), 0, 0);
}

// Target larger than max in array
void Test6() {
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test6", data, sizeof(data) / sizeof(int), 6, 0);
}

// All duplicates, that is teh target
void Test7() {
    int data[] = {3, 3, 3, 3};
    Test("Test7", data, sizeof(data) / sizeof(int), 3, 4);
}

// All duplicates, that is not target
void Test8() {
    int data[] = {3, 3, 3, 3};
    Test("Test8", data, sizeof(data) / sizeof(int), 4, 0);
}

// Only one number in array, and that is target
void Test9() {
    int data[] = {3};
    Test("Test9", data, sizeof(data) / sizeof(int), 3, 1);
}

// Only one number in array, and that is not target
void Test10() {
    int data[] = {3};
    Test("Test10", data, sizeof(data) / sizeof(int), 4, 0);
}

// nullptr
void Test11() {
    Test("Test11", nullptr, 0, 0, 0);
}

// Unit testing
int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
    Test11();

    return 0;
}
