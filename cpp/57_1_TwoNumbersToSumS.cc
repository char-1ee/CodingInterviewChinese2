// Q57_1: Two Numbers To Sum s.
// Description: Given a increasing array and a number s, find two numbers in array such that their
// sum equals to s. If there are mutiple pairs of numbers to s, return any of them.

#include <bits/stdc++.h>
using namespace std;

// Sliding window, time O(n), space O(1)
bool FindTwoNumbersToSum(int data[], int length, int s, int& num1, int& num2) {
    if (data == nullptr || length < 1) return false;

    int left = 0;
    int right = length - 1;
    while (left < right) {
        long long sum = data[left] + data[right];
        if (sum > s) {
            right--;
        } else if (sum < s) {
            left++;
        } else {
            num1 = data[left];
            num2 = data[right];
            return true;
        }
    }
    return false;
}

void Test(const char* testName, int data[], int length, int sum, bool expectedReturn) {
    int num1, num2;
    int result = FindTwoNumbersToSum(data, length, sum, num1, num2);

    if (result == expectedReturn) {
        if (result) {
            if (num1 + num2 == sum)
                printf("Passed. \n");
            else
                printf("FAILED. \n");
        } else
            printf("Passed. \n");
    } else
        printf("FAILED. \n");
}

void Test1() {
    int data[] = {1, 2, 4, 7, 11, 15};
    Test("Test1", data, sizeof(data) / sizeof(int), 15, true);
}

void Test2() {
    int data[] = {1, 2, 4, 7, 11, 16};
    Test("Test2", data, sizeof(data) / sizeof(int), 17, true);
}

void Test3() {
    int data[] = {1, 2, 4, 7, 11, 16};
    Test("Test3", data, sizeof(data) / sizeof(int), 10, false);
}

void Test4() {
    Test("Test4", nullptr, 0, 0, false);
}

int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}