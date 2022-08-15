// Q66: Construtc array by production
// Description: Given an array A[0, 1, ..., n-1]. Construct an array B[0, 1, 2, ..., n-1], and
// elements in B should be B[i] = A[0] * A[1] * ... * A[i-1] * A[i+1] * ... * A[n-1]. Do not allow
// to use divisions.

#include <bits/stdc++.h>
using namespace std;

void Construct1(vector<double>& A, vector<double>& B) {
    if (A.empty() || B.empty() || A.size() != B.size()) return;

    int length = A.size();
    vector<double> C (length, 1);
    vector<double> D (length, 1);

    for (int i = 1; i < length; i++)
        C[i] = C[i - 1] * A[i - 1];
    for (int i = length - 2; i >= 0; i--)
        D[i] = D[i + 1] * A[i + 1];
    for (int i = 0; i < length; i++) 
        B[i] = C[i] * D[i];
    return;
}

void Construct2(vector<double>& A, vector<double>& B) {
    if (A.empty() || B.empty() || A.size() != B.size()) return;

    int length = A.size();
    B[0] = 1;

    for (int i = 1; i < length; i++) {
        B[i] = B[i - 1] * A[i - 1];
    }

    double tmp = 1.0; // stimulate vector D[i]
    for (int i = length - 2; i >= 0; i--) {
        tmp *= A[i + 1];
        B[i] *= tmp;
    }
    return;
}

void Test(
    const char* testName,
    vector<double>& input,
    vector<double>& output,
    vector<double>& expected) {
    printf("%s Begins: ", testName);

    Construct1(input, output);
    if (output == expected)
        printf(" Construct 1: Passed.\n");
    else
        printf("Construct 1: FAILED.\n");

    Construct2(input, output);
    if (output == expected)
        printf(" Construct 2: Passed.\n");
    else
        printf("Construct 2: FAILED.\n");
}

void Test1() {
    vector<double> input = {1, 2, 3, 4, 5};
    vector<double> output = {0, 0, 0, 0, 0};
    vector<double> expected = {120, 60, 40, 30, 24};
    Test("Test 1", input, output, expected);
}

void Test2() {
    vector<double> input = {1, 2, 0, 4, 5};
    vector<double> output = {0, 0, 0, 0, 0};
    vector<double> expected = {0, 0, 40, 0, 0};
    Test("Test 2", input, output, expected);
}

void Test3() {
    vector<double> input = {1, 2, 0, 4, 0};
    vector<double> output = {0, 0, 0, 0, 0};
    vector<double> expected = {0, 0, 0, 0, 0};
    Test("Test 3", input, output, expected);
}

void Test4() {
    vector<double> input = {1, -2, 3, -4, 5};
    vector<double> output = {0, 0, 0, 0, 0};
    vector<double> expected = {120, -60, 40, -30, 24};
    Test("Test 4", input, output, expected);
}

void Test5() {
    vector<double> input = {1, -2};
    vector<double> output = {0, 0};
    vector<double> expected = {-2, 1};
    Test("Test 5", input, output, expected);
}

int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}