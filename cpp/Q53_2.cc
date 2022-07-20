// Q53: Find the missing number from 0 to n-1.
// Description: Given a sorted ascending array with length n - 1, all element in the array is
// unique, and each of them is in range of [0, n-1]. Thus, there is and only is a number in [0, n-1]
// is not in array. Please find this missing number.


#include <bits/stdc++.h>

using namespace std;

// Sum up all 0 to n-1, time O(n)
int FindMissingNumber1(const int* arr, int length) {
    if (arr == nullptr || length < 1) return -1;
    if (length == 1) return arr[0] == 1 ? 0 : 1;

    int sum = 0;
    int expected_sum = (1 + length) * length * 0.5;

    for (int i = 0; i < length; i++) {
        sum += arr[i];
    }

    return expected_sum - sum;
}

// Binary search the mismatch of index and number, O(logn)
int FindMissingNumber2(const int* arr, int length) {
    if (arr == nullptr || length < 1) return -1;
    if (length == 1) return arr[0] == 1 ? 0 : 1;

    int left = 0, right = length;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == mid) {
            left = mid + 1;
        } else {
            if (mid == 0 || arr[mid - 1] == mid - 1) { // mid < 1 and mid > 1
                return mid;
            } else {
                right = mid;
            }
        }
    }

    // When missing number is at the end of array
    if (left == length) return length;

    // Invalid input, including not well sorted array
    // or some number out of range [0, n-1]
    return -1;
}


void Test(string test_name, const int* arr, int length, int expected) {
    cout << "----- " << test_name << " -----\n";

    if (FindMissingNumber1(arr, length) == expected) {
        cout << "Solution 1: Passed." << endl;
    } else {
        cout << "Solution 1: FAILED." << endl;
    }

    if (FindMissingNumber2(arr, length) == expected) {
        cout << "Solution 2: Passed." << endl;
    } else {
        cout << "Solution 2: FAILED." << endl;
    }
}

int main(int argc, char* argv[]) {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {0, 1, 2, 3, 4};
    int arr3[] = {0, 1, 3, 4, 5};
    int arr4[] = {1};
    int arr5[] = {0};

    Test("Test 1", arr1, sizeof(arr1) / sizeof(int), 0);
    Test("Test 2", arr2, sizeof(arr2) / sizeof(int), 5);
    Test("Test 3", arr3, sizeof(arr3) / sizeof(int), 2);
    Test("Test 4", arr4, sizeof(arr4) / sizeof(int), 0);
    Test("Test 5", arr5, sizeof(arr5) / sizeof(int), 1);
    Test("Test 6", nullptr, 0, -1);
}
