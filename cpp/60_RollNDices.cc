// Q60: Indexes of n dices.
// Description: Roll n dices and sum of their indexes is s. Input n, print out all probabilities of
// value of s.
// Examples:
// Input: 1, output: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
// input: 2, output:
// [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]

#include <bits/stdc++.h>
using namespace std;

const int nSides = 6;

// ===== DP based on iteration =====
void Roll(int n) {}

void Test(int n) {
    printf("Test for %d begins:\n", n);
    Roll(n);
    printf("\n");
}

int main(int argc, char* argv[]) {
    Test(1);
    Test(2);
    Test(3);
    Test(4);
    Test(11);
    Test(0);

    return 0;
}
