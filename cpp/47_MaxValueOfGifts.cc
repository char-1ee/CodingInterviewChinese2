// Q47: Max value of gifts
// Given a mxn grid in which every block places a gift with a value (>0),
// it requires to move starts from (0, 0) to (m-1, n-1). Everytime can only move right or down.
// Given the grid rows and cols, calculate the max value of gifts.


#include <bits/stdc++.h>

using namespace std;

int GetMaxValue_01(const int* values, int rows, int cols) {
    if (values == nullptr || rows < 1 || cols < 1) {
        return 0;
    }

    // C style to initialize a 2D array
    int** dp = new int*[rows];
    for (int i = 0; i < rows; i++) {
        dp[i] = new int[cols];
    }

    dp[0][0] = values[0];

    // When i=0 and j=0
    for (int i = 1; i < rows; i++) {
        dp[i][0] = values[i * cols] + dp[i - 1][0];
    }
    for (int j = 1; j < cols; ++j) {
        dp[0][j] = values[j] + dp[0][j - 1];
    }

    // f(i,j) = max(f(i-1, j), f(i, j-1)) + g(i,j)
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + values[i * cols + j];
        }
    }

    int max_value = dp[rows - 1][cols - 1];

    // Clear off the memory allocated
    for (int i = 0; i < rows; i++) {
        delete[] dp[i];
    }
    delete[] dp;

    return max_value;
}

int GetMaxValue_02(const int* values, int rows, int cols) {
    if (values == nullptr || rows < 1 || cols < 1) {
        return 0;
    }

    int* dp = new int[cols];

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int left = (j > 0) ? dp[j - 1] : 0; // f[i][j - 1]
            int up = (i > 0) ? dp[j] : 0; // f[i - 1][j]

            dp[j] = max(left, up) + values[i * cols + j];
        }
    }

    int max_value = dp[cols - 1];
    delete[] dp;
    return max_value;
}

void Test(string test_name, const int* values, int rows, int cols, int expected) {
    cout << "-----" << test_name << "-----" << endl;

    if (GetMaxValue_01(values, rows, cols) == expected) {
        cout << "Solution 1: Passed." << endl;
    } else {
        cout << "Solution 1: FAILED." << endl;
    }

    if (GetMaxValue_02(values, rows, cols) == expected) {
        cout << "Solution 2: Passed." << endl;
    } else {
        cout << "Solution 2: FAILED." << endl;
    }
}

void Test1() {
    int values[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int expected = 29;
    Test("Test 1", (const int*)values, 3, 3, expected);
}

void Test2() {
    int values[][4] = {{1, 10, 3, 8}, {12, 2, 9, 6}, {5, 7, 4, 11}, {3, 7, 16, 5}};
    int expected = 53;
    Test("Test 2", (const int*)values, 4, 4, expected);
}

void Test3() {
    int values[][4] = {{1, 10, 3, 8}};
    int expected = 22;
    Test("Test 3", (const int*)values, 1, 4, expected);
}

void Test4() {
    int values[4][1] = {{1}, {12}, {5}, {3}};
    int expected = 21;
    Test("Test 4", (const int*)values, 4, 1, expected);
}

void Test5() {
    int values[][1] = {{3}};
    int expected = 3;
    Test("Test 5", (const int*)values, 1, 1, expected);
}

void Test6() {
    int expected = 0;
    Test("Test 6", nullptr, 0, 0, expected);
}

int main(int argc, char** argv) {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}