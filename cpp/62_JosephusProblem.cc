// Q62: Josephus Problem
// Description: n numbers 0, 1, ... , n - 1 are arranged in a circle. Start from 0, every time
// delete the m-th number in the circle and then continue iterating m numbers and then delete next
// m-th number. Find the number last stands.
// Example: [ 0, 1, 2, 3, 4 ], m = 3. Then delete in sequence: 2, 0, 4, 1 and leave 3 stands.

#include <bits/stdc++.h>
using namespace std;

int Helper(unsigned int n, unsigned int m);

// Circular linked list. Time O(mn), space O(n)
int LastRemaining_Solution1(unsigned int n, unsigned int m) {
    if (m == 0 || n == 0) return -1;

    list<int> ll;
    for (int i = 0; i < n; ++i) {
        ll.push_back(i);
    }

    list<int>::iterator it = ll.begin();
    while (ll.size() > 1) {
        for (int cnt = 1; cnt < m; cnt++) {
            it++;
            if (it == ll.end()) {
                it = ll.begin();
            }
        }
        list<int>::iterator next = ++it;
        if (next == ll.end()) {
            next = ll.begin();
        }
        it--;
        ll.erase(it);
        it = next;
    }
    return *it;
}

// Math reduction. Time O(n) space O(1)
// f(n, m) = 0                      (n = 1)
//         = [f(n - 1, m) + m] % n  (n > 1)
int LastRemaining_Solution2(unsigned int n, unsigned int m) {
    if (m == 0 || n == 0) return -1;
    return Helper(n, m);
}

int Helper(unsigned int n, unsigned int m) {
    if (n == 1) return 0;
    return (Helper(n - 1, m) + m) % n;
}

// Iterative approach
int LastRemaining_Solution3(unsigned int n, unsigned int m) {
    if (m == 0 || n == 0) return -1;

    int lastStands = 0;
    for (int i = 2; i <= n; i++) {
        lastStands = (lastStands + m) % i;
    }
    return lastStands;
}


void Test(const char* testName, unsigned int n, unsigned int m, int expected) {
    if (testName != nullptr) printf("%s begins: \n", testName);

    if (LastRemaining_Solution1(n, m) == expected)
        printf("Solution 1 passed.\n");
    else
        printf("Solution 1 failed.\n");

    if (LastRemaining_Solution2(n, m) == expected)
        printf("Solution 2 passed.\n");
    else
        printf("Solution 2 failed.\n");

    if (LastRemaining_Solution3(n, m) == expected)
        printf("Solution 3 passed.\n");
    else
        printf("Solution 3 failed.\n");

    printf("\n");
}

void Test1() {
    Test("Test1", 5, 3, 3);
}

void Test2() {
    Test("Test2", 5, 2, 2);
}

void Test3() {
    Test("Test3", 6, 7, 4);
}

void Test4() {
    Test("Test4", 6, 6, 3);
}

void Test5() {
    Test("Test5", 0, 0, -1);
}

void Test6() {
    Test("Test6", 4000, 997, 1027);
}

int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}