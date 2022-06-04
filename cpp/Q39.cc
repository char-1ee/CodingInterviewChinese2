// Given an array with length n, find the number which appears more than n/2 times.
// Error handling: exit 0
// Input array can be modified or not.

#include <cstdio>
#include <iostream>
#include <string>
#include "utils/Array.h"

using namespace std;

bool CheckMajority(int* arr, int length, int res);

// O(N), partition + binary search
int FindMajority(int arr[], int length) {
    if (arr == nullptr || length <= 0) {
        return 0;
    }

    int mid = length >> 2;
    int start = 0, end = length - 1;
    int index = Partition(arr, length, start, end); // O(N)

    while (index != mid) { // O(logN)
        if (index > mid) {
            end = index - 1;
            index = Partition(arr, length, start, end);
        } else {
            start = index + 1;
            index = Partition(arr, length, start, end);
        }
    }

    int res = arr[index];
    if (!CheckMajority(arr, length, res)) {
        res = 0;
    }
    return res;
}

bool CheckMajority(int* arr, int length, int res) {
    int cnt = 0;
    for (int i = 0; i < length; i++) {
        if (arr[i] == res) {
            cnt++;
        }
    }
    return cnt * 2 > length;
}

// O(n), Boyer-Moore Voting algorithm
int FindMajorityBM(int* arr, int length) {
    if (arr == nullptr || length <= 0) {
        return 0;
    }

    int cnt = 1;
    int majority = arr[0];
    for (int i = 1; i < length; i++) {
        if (majority == arr[i]) {
            cnt++;
        } else {
            cnt--;
            if (cnt == 0) {
                majority = arr[i];
                cnt = 1;
            }
        }
    }
    return CheckMajority(arr, length, majority) ? majority : 0;
}

// Unit testing
void Test(string test_name, int arr[], int length, int expected) {
    cout << test_name << endl;

    printf("Solution 1: ");
    if (expected == FindMajority(arr, length)) {
        printf("Passed\n");
    } else {
        printf("FAILED\n");
    }

    printf("Solution 2: ");
    if (expected == FindMajorityBM(arr, length)) {
        printf("Passed\n");
    } else {
        printf("FAILED\n");
    }
}

int main(int argc, char* argv[]) {
    int arr1[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int arr2[] = {1, 2, 3, 2, 4, 2, 5, 2, 3};
    int arr3[] = {1, 2, 2, 2, 2, 3, 3, 3, 3};
    int arr4[] = {1};

    Test("Test 1", arr1, 9, 2);
    Test("Test 2", arr2, 9, 0);
    Test("Test 3", arr3, 9, 0);
    Test("Test 4", arr4, 1, 1);
    Test("Test 5", nullptr, 0, 0);

    return 0;
}