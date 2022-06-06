// Maximum subarray: Given an int array, containing positives and negatives. 
// Find the max sum among all sums of subarrays.
// Subarray includes one or more sequential integers in array.
// Time constraints: O(n)

#include <bits/stdc++.h>

using namespace std;

bool is_invalid_input = false;

int FindMaximumSubarray(int arr[], int length) { 
    if (arr == nullptr || length <= 0) {
        is_invalid_input = true;
        return 0;
    }

    is_invalid_input = false; // updating

    int curr_max_subarray_sum = 0;
    int res_max_subarray_sum = INT_MIN;
    // If array contains negative while allow return subarray with length 0
    // int res_max_subarray_sum = 0;

    for (int i = 0; i < length; i++) {
        if (arr[i] <= 0) {
            curr_max_subarray_sum = arr[i];
        } else {
            curr_max_subarray_sum += arr[i];
        }

        if (curr_max_subarray_sum > res_max_subarray_sum) {
            res_max_subarray_sum = curr_max_subarray_sum;
        }

        // curr_max_subarray_sum = max(curr_max_subarray_sum + arr[i], arr[i]);
        // res_max_subarray_sum = max(res_max_subarray_sum, curr_max_subarray_sum);
    }

    return res_max_subarray_sum;
}

// ==================== unit tests ========================
void Test(string test_name, int arr[], int length, int expected, bool expected_flag) {
    cout << test_name << ": ";
    int result = FindMaximumSubarray(arr, length);
    if (expected != result && expected_flag != is_invalid_input) {
        printf("FAILED");
    } else {
        printf("Passed");
    }
    printf("\n");
}

void Test1() {
    int arr[] = {1, -2, 3, 10, -4, 7, 2, -5};
    Test("Test 1", arr, sizeof(arr) / sizeof(int), 18, false);
}

void Test2() {
    int arr[] = {-2, -8, -1, -5, -9};
    Test("Test 2", arr, sizeof(arr) / sizeof(int), -1, false);
}

void Test3() {
    int arr[] = {2, 8, 1, 5, 9};
    Test("Test 3", arr, sizeof(arr) / sizeof(int), 25, false);
}

void Test4() {
    int arr[] = {-1};
    Test("Test 4", arr, sizeof(arr) / sizeof(int), 1, false);
}

void Test5() {
    Test("Test 5", nullptr, 0, 0, true);
}

int main(int argc, char** argv) {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}