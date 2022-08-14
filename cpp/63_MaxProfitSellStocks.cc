// Q63: Maximum profit to sell stocks
// Description: Assume price of a stock which changes to time is stored in an array. What is the mex
// profit can make by sell and buy this stock for once?
// Example: {9, 11, 8, 5, 7, 12, 16, 14} if we buy when price is 5 and then sell when price is 16,
// we can make profit 11.

#include <bits/stdc++.h>
using namespace std;

int MaxProfit(int* nums, int length) {
    if (nums == nullptr || length < 2) return 0;

    int minPrice = nums[0];
    int maxProfit = nums[1] - minPrice;

    // start from 2 since profit produced by at least 2-length gaps
    for (int i = 2; i < length; i++) { 
        minPrice = min(minPrice, nums[i - 1]);
        maxProfit = max(nums[i] - minPrice, maxProfit);
    }
    return maxProfit;
}

void Test(const char* testName, int* numbers, int length, int expected) {
    if (testName != nullptr) printf("%s begins: ", testName);

    if (MaxProfit(numbers, length) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void Test1() {
    int numbers[] = {4, 1, 3, 2, 5};
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), 4);
}

void Test2() {
    int numbers[] = {1, 2, 4, 7, 11, 16};
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), 15);
}

void Test3() {
    int numbers[] = {16, 11, 7, 4, 2, 1};
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), -1);
}

void Test4() {
    int numbers[] = {16, 16, 16, 16, 16};
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), 0);
}

void Test5() {
    int numbers[] = {9, 11, 5, 7, 16, 1, 4, 2};
    Test("Test5", numbers, sizeof(numbers) / sizeof(int), 11);
}

void Test6() {
    int numbers[] = {2, 4};
    Test("Test6", numbers, sizeof(numbers) / sizeof(int), 2);
}

void Test7() {
    int numbers[] = {4, 2};
    Test("Test7", numbers, sizeof(numbers) / sizeof(int), -2);
}

void Test8() {
    Test("Test8", nullptr, 0, 0);
}

int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();

    return 0;
}