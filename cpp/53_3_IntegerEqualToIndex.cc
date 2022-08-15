// Q53_3: The array integer equals to its index 
// Description: Given a strictly ascending array, every element in the array is unique and integer.
// Please write a function that find any of element whose value is equals to its index.
// Example: {-3, -1, 1, 3, 5}, return 3.

#include <bits/stdc++.h>

using namespace std;

int FindElementAsIndex(const int* arr, int length) {
    if (arr == nullptr || length < 1) return -1;
    if (length == 1) return arr[0] == 0 ? 0 : -1;

    int left = 0, right = length - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == mid) {
            return mid;
        } else if (arr[mid] < mid) {
            left = mid + 1;
        } else { // arr[mid] > mid
            right = mid - 1;
        }
    }

    return -1;
}

void Test(const char* test_name, const int* arr, int length, int expected) {
    if (FindElementAsIndex(arr, length) == expected) {
        printf("%s: Passed\n", test_name);
    } else {
        printf("%s: FAILED\n", test_name);
    }
}

int main(int argc, char* argv[]) {
    int arr1[] = {-3, -1, 1, 3, 5};
    int arr2[] = {0, 1, 3, 5, 6};
    int arr3[] = {-1, 0, 1, 2, 4};
    int arr4[] = {-1, 0, 1, 2, 5};
    int arr5[] = {0};
    int arr6[] = {-1};

    Test("Test 1", arr1, sizeof(arr1) / sizeof(int), 3);
    Test("Test 2", arr2, sizeof(arr2) / sizeof(int), 0);
    Test("Test 3", arr3, sizeof(arr3) / sizeof(int), 4);
    Test("Test 4", arr4, sizeof(arr4) / sizeof(int), -1);
    Test("Test 5", arr5, sizeof(arr5) / sizeof(int), 0);
    Test("Test 6", arr6, sizeof(arr6) / sizeof(int), -1);
    Test("Test 7", nullptr, 0, -1);
}