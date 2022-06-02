#include <cstdio>
#include <iostream>
#include <string>
#include "utils/cpp/Array.h"

using namespace std;

// O(n), Partition()
void LeastKNumber_1(int arr[], int length, int k) {
    if (arr == nullptr || k > length || length < 1 || k < 1) {
        printf("Invalid input");
        return;
    }

    int start = 0;
    int end = length - 1;
    int index = Partition(arr, length, start, end); // O(n)

    while (index != k - 1) {
        if (index > k - 1) {
            index = Partition(arr, index, start, index - 1);
        }
        else
        {
            index = Partition(arr, index, index + 1, end);
        }
    }

    PrintArray(arr, length, 0, index); // k numbers are not guaranteed sorted
}

// O(nlogk), Heap (good ar dealing with big data -> save space)
void LeastKNumber_2(int arr[], int length, int k) {

}

// ============= test ===============
void Test(const string test_name, int arr[], int k) {
    cout << test_name << endl;
    const int length = sizeof(arr) / sizeof(int);
    int arr_copy[length];
    copy(arr, arr + length, arr_copy);

    PrintArray(arr_copy, length, 0, length - 1);

    printf("Solution 1: \n");
    LeastKNumber_1(arr, length, k);

    printf("Solution 2: \n");
    LeastKNumber_2(arr_copy, length, k);

    delete[] arr_copy;
}

int main(int argc, char** argv) {
    int arr[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int arr2[] = {4, 5, 1, 6, 2, 7, 2, 8};
    
    Test("Test 1", arr, 4); // k < length
    Test("Test 2", arr, 8); // k = length
    Test("Test 3", arr, 10); // k > length
    Test("Test 4", arr, 1); // k = 1
    Test("Test 5", arr, 0); // k = 0
    Test("Test 6", arr2, 4); // same elements
    Test("Test 7", nullptr, 0); // nullptr

    return 0;
}