// Q61: Straight Card
// Decription: Randomly pick out 5 or more cards from a set of poke and check whether they can be
// arranged in a straight. Cards contains numbers of 2 - 10, A for 1, J for 11, Q for 12, K for 13.
// Jockers can be regards as any number.

#include <bits/stdc++.h>
using namespace std;

bool IsStraight(int nums[], int length) {
    if (nums == nullptr || length < 5) return false;

    sort(nums, nums + length);

    int nZeros = 0;
    for (int i = 0; i < length; i++) {
        if (nums[i] == 0) nZeros++;
        else break;
    }
    if (nZeros > 2) return false;

    int nGaps = 0;
    for (int i = nZeros + 1; i < length; i++) {
        if (nums[i - 1] == nums[i]) return false;
        nGaps += nums[i] - nums[i - 1] - 1;
    }
    return nGaps <= nZeros;
}

void Test(const char* testName, int* numbers, int length, bool expected) {
    if (testName != nullptr) printf("%s begins: ", testName);

    if (IsStraight(numbers, length) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void Test1() {
    int numbers[] = {1, 3, 2, 5, 4};
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test2() {
    int numbers[] = {1, 3, 2, 6, 4};
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test3() {
    int numbers[] = {0, 3, 2, 6, 4};
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test4() {
    int numbers[] = {0, 3, 1, 6, 4};
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test5() {
    int numbers[] = {1, 3, 0, 5, 0};
    Test("Test5", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test6() {
    int numbers[] = {1, 3, 0, 7, 0};
    Test("Test6", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test7() {
    int numbers[] = {1, 0, 0, 5, 0};
    Test("Test7", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test8() {
    int numbers[] = {1, 0, 0, 7, 0};
    Test("Test8", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test9() {
    int numbers[] = {3, 0, 0, 0, 0};
    Test("Test9", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test10() {
    int numbers[] = {0, 0, 0, 0, 0};
    Test("Test10", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test11() {
    int numbers[] = {1, 0, 0, 1, 0};
    Test("Test11", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test12() {
    Test("Test12", nullptr, 0, false);
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
    Test10();
    Test11();
    Test12();

    return 0;
}