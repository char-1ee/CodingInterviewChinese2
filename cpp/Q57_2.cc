// Q57_2: Continuous positive sequence sum to s.
// Description: Given a positive number s, print out all continuous positive sequences
// (contains at least 2 numbers) each that sums up to s.
// Example: 1+2+3+4+5 = 4+5+6 = 7+8 = 15, so print {1, 2, 3, 4, 5}, {4, 5, 6}, {7, 8}

#include <bits/stdc++.h>
using namespace std;

// Sliding window, time O(n) space O(1)
void PrintContinuousSequence1(int sum) {
    if (sum < 3) return;

    int small = 1, large = 2;
    int curr_sum = 3;
    int bound = (1 + sum) / 2;

    while (small < bound) {
        if (curr_sum == sum) {
            for (int i = small; i <= large; i++) {
                printf("%d ", i);
            }
            printf("\n");
        }

        while (curr_sum > sum && small < bound) {
            curr_sum -= small;
            small++;

            if (curr_sum == sum) {
                for (int i = small; i <= large; i++) {
                    printf("%d ", i);
                }
                printf("\n");
            }
        }

        large++;
        curr_sum += large;
    }
}

// Solution 2: left ptr increase indicates to find next sequence,
// right ptr increase indicates to adjust window size.
// In this way, it gurantees all answers can be iterated.
void PrintContinuousSequence2(int sum) {
    if (sum < 3) return;

    int small = 1, large = 2;
    int curr_sum = 3;
    int bound = (1 + sum) / 2;

    while (small < bound) {
        if (curr_sum == sum) {
            for (int i = small; i <= large; ++i) {
                printf("%d ", i);
            }
            printf("\n");
            curr_sum -= small;
            small++;
        } else if (curr_sum < sum) {
            large++;
            curr_sum += large;
        } else { // find next new sequence
            curr_sum -= small;
            small++;
        }
    }
}

// Solution 3: math
// x + (x + 1) + ... + (x + i - 1) == sum
// i * x + i * (i - 1) / 2 == sum
// x = target - i * (i - 1) / 2
void PrintContinuousSequence3(int sum) {
    if (sum < 3) return;

    int i = 2; // sequence consists of i numbers
    int x = numeric_limits<int>::max();

    while (x > 0) {
        x = sum - i * (i - 1) / 2;
        if (x > 0 && x % i == 0) {
            for (int base = x / i; base < x / i + i; base++) {
                printf("%d ", base);
            }
            printf("\n");
        }
        i++;
    }
}

void Test(const char* test_name, int sum) {
    printf("======= %s =======\n", test_name);
    printf("----- Solution 1 -----\n");
    PrintContinuousSequence1(sum);

    printf("----- Solution 2 -----\n");
    PrintContinuousSequence2(sum);

    printf("----- Solution 3 -----\n");
    PrintContinuousSequence3(sum);
}

int main(int argc, char* argv[]) {
    Test("test1", 1);
    Test("test2", 3);
    Test("test3", 4);
    Test("test4", 9);
    Test("test5", 15);
    Test("test6", 100);

    return 0;
}