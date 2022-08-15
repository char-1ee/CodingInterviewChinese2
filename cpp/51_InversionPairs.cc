// Q51: Inversion pairs in array
// Description: given an array, return the count of inversion pairs
// (a[x], a[y]) in which x < y and a[x] > a[y] in array.
// Example: {7, 5, 6, 4}, (7,6), (7,5), (7,4), (6,4), (5,4), return 5.

#include <bits/stdc++.h>

using namespace std;

int FindInversionPairsHelper(int* data, int* copy, int start, int end);

int FindInversionPairs(int* data, int length) {
    if (data == nullptr || length < 2) return -1;

    if (length == 2) return (data[0] > data[1]) ? 1 : 0;

    int* copy = new int[length];
    for (int i = 0; i < length; i++) {
        copy[i] = data[i];
    }

    int res = FindInversionPairsHelper(data, copy, 0, length - 1);
    delete[] copy;
    return res;
}

int FindInversionPairsHelper(int* data, int* copy, int start, int end) {
    if (start == end) {
        copy[end] = data[end];
        return 0;
    }

    // Divide, swap copy[] and data[] position when pass as parameters
    int mid = start + (end - start) / 2;
    int left_count = FindInversionPairsHelper(copy, data, start, mid);
    int right_count = FindInversionPairsHelper(copy, data, mid + 1, end);

    // Conquer and merge
    int left_ptr = mid; // point to the last number of left subarray
    int right_ptr = end; // point to the last number of right subarray

    int index = end; // pointer of new sorted array (copy[])
    int count = 0; // count of inversion pairs

    while (left_ptr >= start && right_ptr >= mid + 1) {
        if (data[left_ptr] > data[right_ptr]) {
            count += right_ptr - mid;
            copy[index--] = data[left_ptr--];
        } else {
            copy[index--] = data[right_ptr--];
        }
    }

    while (left_ptr >= start) {
        copy[index--] = data[left_ptr--];
    }
    while (right_ptr >= mid + 1) {
        copy[index--] = data[right_ptr--];
    }

    return left_count + right_count + count;
}

// ===== Test methods =====
void Test(string test_name, int* data, int length, int expected) {
    if (FindInversionPairs(data, length) == expected) {
        cout << test_name << ": Passed." << endl;
    } else {
        cout << test_name << ": FAILED." << endl;
    }
}

// Normal case
void Test1() {
    int data[] = {1, 2, 3, 4, 7, 6, 5};
    int expected = 3;
    Test("Test1", data, sizeof(data) / sizeof(int), expected);
}

// Descending case
void Test2() {
    int data[] = {6, 5, 4, 3, 2, 1};
    int expected = 15;
    Test("Test2", data, sizeof(data) / sizeof(int), expected);
}

// Ascending case
void Test3() {
    int data[] = {1, 2, 3, 4, 5, 6};
    int expected = 0;
    Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

// Only 1 element
void Test4() {
    int data[] = {1};
    int expected = -1;
    Test("Test4", data, sizeof(data) / sizeof(int), expected);
}

// Only two elements (0 pair)
void Test5() {
    int data[] = {1, 2};
    int expected = 0;
    Test("Test5", data, sizeof(data) / sizeof(int), expected);
}

// Only two elements (1 pair)
void Test6() {
    int data[] = {2, 1};
    int expected = 1;
    Test("Test6", data, sizeof(data) / sizeof(int), expected);
}

// Duplicates
void Test7() {
    int data[] = {1, 2, 1, 2, 1};
    int expected = 3;
    Test("Test7", data, sizeof(data) / sizeof(int), expected);
}

// Nullptr
void Test8() {
    int expected = -1;
    Test("Test8", nullptr, 0, expected);
}

// Example case
void Test9() {
    int data[] = {7, 5, 6, 4};
    int expected = 5;
    Test("Test9", data, sizeof(data) / sizeof(int), expected);
}

// Unit test
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

    return 0;
}
