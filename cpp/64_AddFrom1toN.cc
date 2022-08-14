// Q64: Add 1 + 2 + ... + n
// Description: Find result of 1 + 2 + ... + n, without using *, /, for , while, if, else, switch, case and (A ? B : C)

#include <bits/stdc++.h>
using namespace std;

// ============== Method 1 ==============
// Constructor: call n times constructors.
class Temp {
public:
    Temp() {
        cnt++;
        sum += cnt;
    }
    static unsigned int GetSum() { return sum; }
    static void Reset() { cnt = 0, sum = 0; }

private:
    static unsigned int sum;
    static unsigned int cnt;
};

// static members should be initialized outside class
unsigned int Temp::sum = 0;
unsigned int Temp::cnt = 0;

unsigned int Sum_Solution1(unsigned int n) {
    Temp::Reset();

    Temp* t = new Temp[n];
    delete[] t;
    // t = nullptr; // pointer is a stack variable

    return Temp::GetSum();
}

// ============== Method 2 ==============
// Virtual Function: play as if in recursion
class A {
public:
    virtual unsigned int Sum(unsigned int n) { return 0; }
};

A* arr[2];

class B : public A {
public:
    unsigned int Sum(unsigned int n) { return arr[!!n]->Sum(n - 1) + n; }
};

unsigned int Sum_Solution2(unsigned int n) {
    A a;
    B b;
    arr[0] = &a;
    arr[1] = &b;
    return arr[1]->Sum(n);
}

// ============== Method 3 ==============
// Function pointer: in a pure C environment
typedef unsigned int (*fun)(unsigned int);

unsigned int Terminator(unsigned int n) {
    return 0;
}

unsigned int Sum_Solution3(unsigned int n) {
    static fun f[2] = {Terminator, Sum_Solution3};
    return n + f[!!n](n - 1);
}

// ============== Method 4 ==============
// Template: TODO template related knowledges


void Test(int n, int expected) {
    printf("Test for %d begins:\n", n);

    if (Sum_Solution1(n) == expected)
        printf("Solution1 passed.\n");
    else
        printf("Solution1 failed.\n");

    if (Sum_Solution2(n) == expected)
        printf("Solution2 passed.\n");
    else
        printf("Solution2 failed.\n");

    if (Sum_Solution3(n) == expected)
        printf("Solution3 passed.\n");
    else
        printf("Solution3 failed.\n");
}

void Test1() {
    const unsigned int number = 1;
    int expected = 1;
    Test(number, expected);
    // if (Sum_Solution4<number>::N == expected)
    //     printf("Solution4 passed.\n");
    // else
    //     printf("Solution4 failed.\n");
}

void Test2() {
    const unsigned int number = 5;
    int expected = 15;
    Test(number, expected);
    // if (Sum_Solution4<number>::N == expected)
    //     printf("Solution4 passed.\n");
    // else
    //     printf("Solution4 failed.\n");
}

void Test3() {
    const unsigned int number = 10;
    int expected = 55;
    Test(number, expected);
    // if (Sum_Solution4<number>::N == expected)
    //     printf("Solution4 passed.\n");
    // else
    //     printf("Solution4 failed.\n");
}

void Test4() {
    const unsigned int number = 0;
    int expected = 0;
    Test(number, expected);
    // if (Sum_Solution4<number>::N == expected)
    //     printf("Solution4 passed.\n");
    // else
    //     printf("Solution4 failed.\n");
}

int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}