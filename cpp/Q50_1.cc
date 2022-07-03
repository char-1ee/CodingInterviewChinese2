//==================================================================
// Find the first not repeating character in a given string.
//==================================================================

#include <bits/stdc++.h>

using namespace std;

char FindFirstNotRepeatChar(const string s) {
    if (s.empty())
        return '\0';
    if (s.length() == 1)
        return s[0];

    const int TABLE_SIZE = 256;
    unsigned int table[TABLE_SIZE] = { 0 }; // initailze all elements 0
    for (int i = 0; i < s.length(); ++i) {
        table[s[i]]++;
    }

    for (int i = 0; i < s.length(); ++i) {
        if (table[s[i]] == 1) {
            return s[i];
        }
    }
    return '\0';
}

void Test(string test_name, string s, char expected) {
    if (FindFirstNotRepeatChar(s) == expected) {
        cout << test_name << ": Passed." << endl;
    } else {
        cout << test_name << ": FAILED." << endl;
    }
}

int main(int argc, char* argv[]) {
    Test("Test 1", "google", 'l');
    Test("Test 2", "aabbccss", '\0');
    Test("Test 3", "abcdef", 'a');
    Test("Test 4", "a", 'a');
    Test("Test 5", "", '\0');

    return 0;
}
