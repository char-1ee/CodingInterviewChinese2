// Q60: Indexes of n dices.
// Description: Roll n dices and sum of their indexes is s. Input n, print out all probabilities of
// value of s.

#include <bits/stdc++.h>
using namespace std;



void Test(int n) {
    printf("Test for %d begins:\n", n);

    printf("Test for solution1\n");
    PrintProbability1(n);

    printf("Test for solution2\n");
    PrintProbability2(n);

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
