// Q65: Add two numbers without using +, -, *, /

#include <bits/stdc++.h>
using namespace std;

int Add(int num1, int num2) {
    int sum, carry;

    do {
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;
        num1 = sum;
        num2 = carry;
    } while (num2 != 0);

    return sum;
}

void Test(const char* testName, int x, int y, int expected) {
    if (Add(x, y) == expected) {
        printf("%s: Passed.\n", testName);
    } else {
        printf("%s: FAILED.\n", testName);
    }
}

int main(int argc, char* argv[]) {
    Test("test 1", 1, 2, 3);
    Test("test 2", 111, 899, 1010);

    Test("test 3", -1, 2, 1);
    Test("test 4", 1, -2, -1);

    Test("test 5", 3, 0, 3);
    Test("test 6", 0, -4, -4);

    Test("test 7", -2, -8, -10);
    return 0;
}