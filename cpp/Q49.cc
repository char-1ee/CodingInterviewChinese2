//==================================================================
// Ugly number aree defined as numbers that onyl containns factors 2, 3, 5,
// and counted from 1, 2, 3, 4, 5, 6 ...
// Given index n, write a function returns the n-th ugly number.
//==================================================================

#include <bits/stdc++.h>

using namespace std;

int MinOf3(int x, int y, int z) {
    return min({x, y, z});
    // return min(min(x, y), z);
}

bool isUgly(int number) {
    while (number % 5 == 0) {
        number /= 5;
    }
    while (number % 3 == 0) {
        number /= 3;
    }
    while (number % 2 == 0) {
        number /= 2;
    }
    return number == 1;
}

// ===== Time consuming =====
// Check ugly number for each iterations.
int GetUglyNumberSolution1(int index) {
    if (index < 1)
        return 0;

    int i = 0;  // iteration counter
    int cnt = 0; // count of ugly number
    while (cnt < index) {
        ++i;
        if (isUgly(i)) {
            ++cnt;
        }
    }
    return i;
}

// ===== Space tradeoff for time =====
// A similar idea as Sieve of Eratosthenes, keep an array of ugly numbers.
int GetUglyNumberSolution2(int index) {
    if (index < 1)
        return 0;
    if (index < 2)
        return 1;

    int *nums = new int[index]; // Array of sorted ugly numbers
    nums[0] = 1;
    int next_ugly_num_index = 1; // next generate ugly number

    int *bound_of_2 = nums; // T2
    int *bound_of_3 = nums; // T3
    int *bound_of_5 = nums; // T5

    while (next_ugly_num_index < index) {

        int multiply_of_2 = *bound_of_2 * 2; // M2
        int multiply_of_3 = *bound_of_3 * 3; // M3
        int multiply_of_5 = *bound_of_5 * 5; // M5

        int next_ugly_num = MinOf3(multiply_of_2, multiply_of_3, multiply_of_5);
        nums[next_ugly_num_index] = next_ugly_num;

        while (*bound_of_2 * 2 <= next_ugly_num) 
            ++bound_of_2;
        while (*bound_of_3 * 3 <= next_ugly_num) 
            ++bound_of_3;
        while (*bound_of_5 * 5 <= next_ugly_num) 
            ++bound_of_5;

        next_ugly_num_index++;
    }

    int res = nums[index - 1];
    delete[] nums;
    return res;
}

void Test(string test_name, int index, int expected) {
    cout << "-----" << test_name << "-----" << endl;

    if (GetUglyNumberSolution1(index) == expected) {
        cout << "Solution 1: Passed." << endl;
    } else {
        cout << "Solution 1: FAILED." << endl;
    }

    if (GetUglyNumberSolution2(index) == expected) {
        cout << "Solution 2: Passed." << endl;
    } else {
        cout << "Solution 2: FAILED." << endl;
    }
}

int main(int argc, char** argv) {

    // Functional testing
    Test("Test 1", 2, 2);
    Test("Test 2", 3, 3);
    Test("Test 3", 6, 6);
    Test("Test 4", 11, 15);

    // Boudary testing
    Test("Test 5", 0, 0);
    Test("Test 6", 1, 1);

    // Performance testing
    Test("Test 7", 1500, 859963392);

    return 0;
}

//==================================================================
// Nromally when we encounter TLE, we can tradeoff time with space.
// Since the TLE method checks non-ugly number and ugly number, 
// so we try to only count and check ugly number. Here we keep an array  
// of sorted ugly numbers, and we count every ugly number by multiplying
// frontier ugly numbers with 2, 3, 5.
// 
// To ensure it is sorted, we assume there are already sorted numbers 
// and the maximum ugly number among them is M. For next ugly number, 
// we multiply 2 with every already-have ugly numbers to find the next
// ugly number. We keep that to-find ugly number as M2 (>M). Similarly,
// we noted M3, M5. Thus, next ugly number must be in M2, M3 and M5 (>M).
// 
// When multiplying 2, 3, 5 with each ugly numbers in array, there must
// be a ugly number T2, for which all ugly numbers before T2 multiply
// 2 must be less than M and all after T2 multiply 2 must be more than 
// M. So we mark position of T2, everytime we update T2 after generate 
// next ugly number. Similarly for T3 and T5.
//==================================================================