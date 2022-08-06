// Q58_1: Reverse a sentence.
// Description: Given a sentence containing english words, invert the order of words but keep
// letters in words not changed.
// Example: "I am a student." -> "student. a am I"

#include <bits/stdc++.h>
using namespace std;

void Reverse(string& s, int start, int end);

void ReverseSentence(string& sentence) {
    if (sentence.empty()) return;

    int len = sentence.length();
    Reverse(sentence, 0, len - 1);

    int start = 0, end = 0;
    // for (int idx = 0; idx < len; ) {
        // while (idx < len && sentence[idx++] == ' ')
        //     ;
        // start = idx;
        // end = start;
        // while (end < len && sentence[end++] != ' ')
        //     ;
        // Reverse(sentence, start, end - 1);
        // idx = end;
    // }

    while (sentence[start] != ' ') {
        if (sentence[start] == ' ') {
            start++;
            end++;
        } else if (sentence[end] == ' ' || end == len - 1) {
            Reverse(sentence, start, --end);
            start = ++end;
        } else {
            end++;
        }
    }
}

void Reverse(string& s, int start, int end) {
    for (int i = start, j = end; i < j; i++, j--) {
        swap(s[i], s[j]);
    }
}

void Test(const char* test_name, string input, string expected) {
    printf("-----%s-----\n", test_name);
    cout << input << endl;

    ReverseSentence(input);

    cout << input << endl;
    if (input.compare(expected) == 0)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void Test1() {
    string s1 = "I am a student.";
    string s2 = "student. a am I";
    Test("Test1", s1, s2);
}

void Test2() {
    string s1= "Wonderful";
    string s2 = "Wonderful";
    Test("Test2", s1, s2);
}

void Test3() {
    Test("Test4", "", "");
}

void Test4() {
    string s1 = "   ";
    string s2 = "   ";
    Test("Test5", s1, s2);
}

int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}