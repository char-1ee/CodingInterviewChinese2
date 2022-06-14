// A stream of integers in serialization 012345678910111213141516...
// Write a function, find the n-th digit in this stream.
// e.g. 5->5, 13->1, 19->4 ... n->f(n)

#include <bits/stdc++.h>

using namespace std;

int CountOfIntegers(int digits);
int BeginNumber(int digits);

// Solution
int DigitAtIndex(int n) {
    if (n < 0) {
        return -1;
    } 
    if (n < 10) {
        return n;
    }

    int digit = 1; // number of digit
    int count = 9; // count of m-digit numbers

    // Locate the range (how many digits) that the number (n-th digit in) is in
    while (n > count) {
        n -= count;
        ++digit;
        count = CountOfIntegers(digit);
    }

    // Find the beginning number for m-digit numbers. 10, 100, 10000 ... 
    int begin = BeginNumber(digit);

    // Find the number that n-th digit is in
    int num = begin + (n - 1) / digit;

    // Find the n-th digit by converting to string
    string s_num = to_string(num);
    int index = (n - 1) % digit;
    int res = s_num[index] - '0';

    return res;
}

// How many digit count in a m-digits number range, 100~999 => 2700.
int CountOfIntegers(int m) {
    int cnt;
    if (m == 1) {
        cnt = 10;
    } else {
        cnt = 9 * m * (int) pow(10, m - 1);
    }
    return cnt;
}

// To find the 1st m-digits integer.
int BeginNumber(int m) {
    if (m == 1) {
        return 0;
    }
    return (int) pow(10, m - 1);
}

// =========== testing ===========
void Test(string test_name, int n, int expected) {
    if (DigitAtIndex(n) != expected) {
        cout << test_name  << ": FAILED" << endl;
    } else {
        cout << test_name  << ": Passed" << endl;
    }
}

// unit test
int main() {
    Test("Test 1", 0, 0);
    Test("Test 2", 1, 1);
    Test("Test 3", 5, 5);
    Test("Test 4", 10, 1);
    Test("Test 5", 189, 9);
    Test("Test 6", 1000, 3);
    Test("Test 7", 1001, 7); 
	Test("Test 8", 1002, 0); 
    Test("Test 9", -1, -1);

    return 0;
}

// Three steps:
//  1. Find the digit of the number that n refers to; m = Digit(n);
//  2. Find the number that n refers to; num = Numbe(r(m, n);
//  3. Find the position of n in num; res = Position(num, n);
// 