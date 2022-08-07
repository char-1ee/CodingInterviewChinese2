// Q59_1: Maximum sliding window.
// Description: Given a array and the size of sliding window, find the maximum elements in
// every sliding window.
// Example: {2, 3, 4, 2, 6, 2, 5, 1} and k = 3, then there are 6 windows. For 6 windows, each
// window max element is {4, 4, 6, 6, 6, 5}.

#include <bits/stdc++.h>
using namespace std;

vector<int> maxInWindows(vector<int> nums, int k) {
    vector<int> res;
    if (nums.size() < k || k <= 0) return res;

    deque<int> q; // store index not values

    // Firstly, fill in window up to its size
    for (unsigned int i = 0; i < k; i++) {
        while (!q.empty() && nums[i] >= nums[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }

    // Secondly, slide the window
    for (unsigned int i = k; i < nums.size(); ++i) {
        res.push_back(nums[q.front()]); // store last window's max value

        while (!q.empty() && nums[i] >= nums[q.back()]) {
            q.pop_back();
        }
        if (!q.empty() && q.front() <= (i - k)) {
            q.pop_front();
        }

        q.push_back(i);
    }
    res.push_back(nums[q.front()]);
    return res;
}

void Test(string testName, vector<int> nums, int k, vector<int> expected) {
    cout << "-----" << testName << "-----" << endl;

    vector<int> res = maxInWindows(nums, k);

    vector<int>::const_iterator itResult = res.begin();
    vector<int>::const_iterator itExpected = expected.begin();
    while (itResult < res.end() && itExpected < expected.end()) {
        if (*itResult != *itExpected) break;
        itResult++;
        itExpected++;
    }

    if (itResult == res.end() && itExpected == expected.end()) {
        printf("Passed.\n");
    } else {
        printf("FAILED.\n");
    }

    cout << "original vector: \n";
    for (int num : nums) cout << num << " ";
    cout << "\nmax in windows: \n";
    for (int num : res) cout << num << " ";
    printf("\n");
}

void Test1() {
    int num[] = {2, 3, 4, 2, 6, 2, 5, 1};
    vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

    int expected[] = {4, 4, 6, 6, 6, 5};
    vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

    unsigned int size = 3;

    Test("Test1", vecNumbers, size, vecExpected);
}

void Test2() {
    int num[] = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

    int expected[] = {3, 3, 5, 5, 6, 7};
    vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

    unsigned int size = 3;

    Test("Test2", vecNumbers, size, vecExpected);
}

void Test3() {
    int num[] = {1, 3, 5, 7, 9, 11, 13, 15};
    vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

    int expected[] = {7, 9, 11, 13, 15};
    vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

    unsigned int size = 4;

    Test("Test3", vecNumbers, size, vecExpected);
}

void Test4() {
    int num[] = {16, 14, 12, 10, 8, 6, 4};
    vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

    int expected[] = {16, 14, 12};
    vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

    unsigned int size = 5;

    Test("Test4", vecNumbers, size, vecExpected);
}

void Test5() {
    int num[] = {10, 14, 12, 11};
    vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

    int expected[] = {10, 14, 12, 11};
    vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

    unsigned int size = 1;

    Test("Test5", vecNumbers, size, vecExpected);
}

void Test6() {
    int num[] = {10, 14, 12, 11};
    vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

    int expected[] = {14};
    vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

    unsigned int size = 4;

    Test("Test6", vecNumbers, size, vecExpected);
}

void Test7() {
    int num[] = {10, 14, 12, 11};
    vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

    vector<int> vecExpected;

    unsigned int size = 0;

    Test("Test7", vecNumbers, size, vecExpected);
}

void Test8() {
    int num[] = {10, 14, 12, 11};
    vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

    vector<int> vecExpected;

    unsigned int size = 5;

    Test("Test8", vecNumbers, size, vecExpected);
}

void Test9() {
    vector<int> vecNumbers;
    vector<int> vecExpected;

    unsigned int size = 5;

    Test("Test9", vecNumbers, size, vecExpected);
}

int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}