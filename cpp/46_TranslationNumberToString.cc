// Q46: Translate number into string
// Description: Given a number, translate it to string according to the rules: 0->a, 1->b, ...
// 11->l, ... , 25->z. A number may have various translations. For example, 12258 has 5
// translations, "bccfi", "bwfi", "bczi", "mcfi", "mzi". Please implement a function to computer how
// many translations are there for a number.

#include <bits/stdc++.h>

using namespace std;

int CountTranslation(const string& num);

int CountTranslation(int num) {
    if (num < 0) {
        return 0;
    }

    string num_in_string = to_string(num);
    return CountTranslation(num_in_string);
}

int CountTranslation(const string& num) {
    int length = num.length();

    int* dp = new int[length];
    int count = 0; // count of f(i)

    for (int i = length - 1; i >= 0; i--) {
        if (i == length - 1) {
            dp[i] = 1;
        } else {
            count = dp[i + 1];

            int digit1 = num[i] - '0';
            int digit2 = num[i + 1] - '0';
            int double_digit = digit1 * 10 + digit2;

            if (double_digit >= 10 && double_digit <= 25) {
                if (i == length - 2) {
                    count += 1;
                } else {
                    count += dp[i + 2];
                }
            }

            dp[i] = count;
        }
    }

    count = dp[0];
    delete[] dp;

    return count;
}

void Test(string test_name, int num, int expected) {
    cout << test_name << ": ";
    if (CountTranslation(num) == expected) {
        printf("Passed.\n");
    } else {
        printf("FAILED.\n");
    }
}

int main(int argc, char** argv) {
    Test("Test 1", 0, 1);
    Test("Test 2", 1, 1);
    Test("Test 3", 10, 2);
    Test("Test 4", 125, 3);
    Test("Test 5", 426, 1);
    Test("Test 6", 101, 2);
    Test("Test 7", 100, 2);
    Test("Test 8", 12258, 5);
    Test("Test 9", -100, 0);

    return 0;
}

// Assume f(i) stands for the count starting from index i.
// Then we have f(i) = f(i+1) + g(i, i+1) * f(i+2)
// where g(i, i+1) is 1 when the number from index i to i+1 is in 10~25
// otherwise g(i, i+1) is 0