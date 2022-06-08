#include <bits/stdc++.h>

using namespace std;

// O(nlogn), O(1): For number N, there is logN digits in N
int CountNumberOf1_1(unsigned int n) {
    int cnt = 0;
    for (unsigned int i = 1; i <= n; ++i) {
        int num = i;
        while (num > 0) {
            if (num % 10 == 1) {
                ++cnt;
            }
            num /= 10;
        }
    }
    return cnt;
}

// O(logN), O(1): a math point of view
int NumberOf1(const char* n);
int PowerBase10(unsigned int n);

int CountNumberOf1_2(unsigned int n) {
    if (n <= 0) {
        return 0;
    }

    char str_n[50];
    sprintf(str_n, "%d", n);

    return NumberOf1(str_n);
}

// 1-21345
int NumberOf1(const char* n) {
    if (n == nullptr || *n < '0' || *n > '9' || *n == '\0') {
        return 0;
    }

    int first = *n - '0'; // the MSB number
    unsigned int length = static_cast<unsigned int>(strlen(n)); // the length of number n

    if (length == 1 && first == 0) {
        return 0;
    }
    if (length == 1 && first > 0) {
        return 1;
    }

    // the 1s in MSB/first digit, e.g. 10000-19999
    int num_of_1_msb = 0;
    if (first > 1) {
        num_of_1_msb = PowerBase10(length - 1);
    } else if (first == 1) {
        num_of_1_msb = atoi(n + 1) + 1;
    }

    // the 1s except the first digit, e.g. 01346-21345
    int num_of_1_other = first * (length - 1) * PowerBase10(length - 2);

    // the 1s from 1-1345
    int num_of_1_recurrsion = NumberOf1(n + 1);

    return num_of_1_recurrsion + num_of_1_other + num_of_1_msb;
}

int PowerBase10(unsigned int n) {
    int res = 1;
    for (unsigned int i = 0; i < n; i++) {
        res *= 10;
    }
    return res;
}

// ============= testing =============
void Test(string test_name, unsigned int n, int expected) {
    cout << test_name << ": ";
    int result1 = CountNumberOf1_1(n);
    if (result1 != expected) {
        printf("FAILED");
    } else {
        printf("Passed");
    }
    printf("\t");

    int result2 = CountNumberOf1_2(n);
    if (result2 != expected) {
        printf("FAILED");
    } else {
        printf("Passed");
    }
    printf("\n");
}

// unit testing
int main(int argc, char** argv) {
    Test("Test 1", 5, 1);
    Test("Test 2", 10, 2);
    Test("Test 3", 55, 16);
    Test("Test 4", 99, 20);       // functional test
    Test("Test 5", 1, 1);
    Test("Test 6", 0, 0);         // boundary test
    Test("Test 7", 10000, 4001);
    Test("Test 8", 21345, 18821); // performance test

    return 0;
}

// TODO: using math formula