// Q56_1: Two numbers appears only once in array.
// Description: In a integer array, all numbers appears twice except two numbers.
// Constraints: time in O(n) space O(1)

#include <bits/stdc++.h>
#include "utils/Array.h"
using namespace std;

unsigned int FindLSB1(int num);
bool IsBit1(int num, int index);

void FindNumbersAppearOnce(int data[], int length) {
    if (data == nullptr || length < 1) return;

    int res = 0; // result of XOR all numbers
    for (int i = 0; i < length; i++) {
        res ^= data[i];
    }

    // index of rightmost bit 1
    unsigned int index = FindLSB1(res);
    int num1 = 0, num2 = 0;

    for (int j = 0; j < length; j++) {
        if (IsBit1(data[j], index)) {
            num1 ^= data[j];
        } else {
            num2 ^= data[j];
        }
    }
    printf("%d, %d\n", num1, num2);
}

// Find the rightmost bit 1 index.
unsigned int FindLSB1(int num) {
    int mask = 0x1;
    int index = 0;
    while (!(num & mask) && (index < 8 * sizeof(int))) {
        ++index;
        num >>= 1;
    }
    return index;
}

// Check whether number num has bit 1 in given index.
bool IsBit1(int num, int index) {
    int mask = 0x1;
    return ((num >> index) & mask);
}

void Test(string test_name, int data[], int length) {
    cout << "-----" << test_name << "-----" << endl;
    PrintArray(data, length, 0, length - 1);
    FindNumbersAppearOnce(data, length);
}

int main(int argc, char** argv) {
    int data1[] = {2, 4, 3, 6, 3, 2, 5, 5};
    int data2[] = {4, 6};
    int data3[] = {4, 6, 1, 1, 1, 1};

    Test("Test 1", data1, sizeof(data1) / sizeof(int));
    Test("Test 2", data2, sizeof(data2) / sizeof(int));
    Test("Test 3", data3, sizeof(data3) / sizeof(int));
    return 0;
}