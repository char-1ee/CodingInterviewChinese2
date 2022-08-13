// Q58_2: Left rotate string
// Description: Left rotation means move several characters in the front of string to the end of
// string. Write a function implements left rotation.
// Example: "abcdefg" and k = 2, return "cdefgab"

#include <bits/stdc++.h>
using namespace std;

void Reverse(string& s, int start, int end) {
    for (int i = start, j = end; i < j; i++, j--) {
        swap(s[i], s[j]);
    }
}

void LeftRotateString(string& s, int k) {
    if (s.empty() || k < 1) return;

    int len = s.length();
    Reverse(s, 0, len - 1);
    Reverse(s, 0, len - k - 1);
    Reverse(s, len - k, len - 1);
}

void Test(string test_name, string input, int num, string expected) {
    cout << "-----" << test_name << "-----\n";
    cout << input << endl;

    LeftRotateString(input, num);

    cout << input << endl;
    if (input.compare(expected) == 0)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void Test1() {
    string input = "abcdefg";
    string expected = "cdefgab";

    Test("Test1", input, 2, expected);
}

void Test2() {
    string input = "abcdefg";
    string expected = "bcdefga";

    Test("Test2", input, 1, expected);
}

void Test3() {
    string input = "abcdefg";
    string expected = "gabcdef";

    Test("Test3", input, 6, expected);
}

void Test4() {
    Test("Test4", "", 6, "");
}
void Test5() {
    string input = "abcdefg";
    string expected = "abcdefg";

    Test("Test5", input, 0, expected);
}

void Test6() {
    string input = "abcdefg";
    string expected = "abcdefg";

    Test("Test6", input, 7, expected);
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