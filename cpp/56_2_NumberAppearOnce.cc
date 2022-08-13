// Q56_2: Number appears only once in array.
// Description: An array element only appear once, while wll other elements appear exactly three
// times. Fine that appear-once number in array.

#include <bits/stdc++.h>
using namespace std;

// Time O(n), space O(1)
int FindNumberAppearOnce(int nums[], int length) {
    if (nums == nullptr || length < 1) {
        // throw "Invalid input.\n";
        throw new exception();
    }

    int sums[32] = {0};
    for (int i = 0; i < length; ++i) {
        int mask = 0x1;
        for (int j = 31; j >= 0; --j) {
            int bit = nums[i] & mask;
            if (bit != 0)
                sums[j] += 1;
            mask <<= 1;
        }
    }

    int res = 0;
    for (int i = 0; i < 32; ++i) {
        res <<= 1;
        res += sums[i] % 3;
    }
    return res;
}

void Test(const char* testName, int numbers[], int length, int expected) {
    int result = FindNumberAppearOnce(numbers, length);
    if (result == expected)
        printf("%s: passed.\n", testName);
    else
        printf("%s: FAILED.\n", testName);
}

void Test1() {
    int numbers[] = {1, 1, 2, 2, 2, 1, 3};
    int expected = 3;
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), expected);
}

void Test2() {
    int numbers[] = {4, 3, 3, 2, 2, 2, 3};
    int expected = 4;
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), expected);
}

void Test3() {
    int numbers[] = {4, 4, 1, 1, 1, 7, 4};
    int expected = 7;
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), expected);
}

void Test4() {
    int numbers[] = {-10, 214, 214, 214};
    int expected = -10;
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), expected);
}

void Test5() {
    int numbers[] = {-209, 3467, -209, -209};
    int expected = 3467;
    Test("Test5", numbers, sizeof(numbers) / sizeof(int), expected);
}

void Test6() {
    int numbers[] = {1024, -1025, 1024, -1025, 1024, -1025, 1023};
    int expected = 1023;
    Test("Test6", numbers, sizeof(numbers) / sizeof(int), expected);
}

void Test7() {
    int numbers[] = {-1024, -1024, -1024, -1023};
    int expected = -1023;
    Test("Test7", numbers, sizeof(numbers) / sizeof(int), expected);
}

void Test8() {
    int numbers[] = {-23, 0, 214, -23, 214, -23, 214};
    int expected = 0;
    Test("Test8", numbers, sizeof(numbers) / sizeof(int), expected);
}

void Test9() {
    int numbers[] = {0, 3467, 0, 0, 0, 0, 0, 0};
    int expected = 3467;
    Test("Test9", numbers, sizeof(numbers) / sizeof(int), expected);
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
    Test9();

    return 0;
}
