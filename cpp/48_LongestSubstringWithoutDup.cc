// Q48: Longest substring without repeating character.
// Description: find the length of longest substring without duplicates in given string.
// Example:in "arabcacfr", return 4, "acfr"

#include <bits/stdc++.h>
using namespace std;

// Sliding window
int LongestSubStrinigWithoutDuplicates_solution1(const string& s) {
    if (s.length() < 2) return s.length();

    int res = 0; // the max length of qualified substring
    vector<int> pos(26);

    for (int i = 0, j = 0; i < s.length(); ++i) {
        while (pos[s[i] - 'a']) {
            pos[s[j] - 'a']--;
            j++;
        }

        pos[s[i] - 'a']++;
        res = max(res, i - j + 1);
    }
    return res;
}

// DP
int LongestSubStrinigWithoutDuplicates_solution2(const string& s) {
    if (s.length() < 2) return s.length();

    int max_length = 0; // result max length
    int curr_length = 0; // f(i - 1), update as f(i) for each iteration
    int* pos = new int[26]; // map(char -> index where it appears in string)
    for (int i = 0; i < 26; i++) {
        pos[i] = -1;
    }

    for (int i = 0; i < s.length(); ++i) {
        // the most previous index where s[i] appears in string
        int prev_index = pos[s[i] - 'a'];

        if (prev_index < 0 || (i - prev_index) > curr_length) {
            curr_length++;
        } else if (i - prev_index <= curr_length) {
            curr_length = i - prev_index;
        }

        max_length = max(max_length, curr_length);
        pos[s[i] - 'a'] = i;
    }

    delete[] pos;
    return max_length;
}

// ===== unit testing =====
void Test(string test_name, string s, int expected) {
    cout << "-----" << test_name << "-----" << endl;

    if (LongestSubStrinigWithoutDuplicates_solution1(s) == expected) {
        cout << "Solution 1: Passed." << endl;
    } else {
        cout << "Solution 1: FAILED." << endl;
    }

    if (LongestSubStrinigWithoutDuplicates_solution2(s) == expected) {
        cout << "Solution 2: Passed." << endl;
    } else {
        cout << "Solution 2: FAILED." << endl;
    }
}

// ===== testing driver =====
int main(int argc, char** argv) {
    Test("test 1", "abcacfrar", 4);
    Test("test 1.1", "acfrarabc", 4);
    Test("test 1.2", "arabcacfr", 4);
    Test("test 2", "aaaa", 1);
    Test("test 2.1", "aaabbbccc", 2);
    Test("test 3", "abcdefg", 7);
    Test("test 4", "a", 1);
    Test("test 5", "", 0);

    return 0;
}

// DP:
// f(i) stands for the max length of substring without duplicates which ends with index i
// 1. If s[i] has no duplicates in previous substr[0, i) : f(i) = f(i-1) + 1
// 2. If s[i] has duplicates in previous substr[0, i) :
//      Given d is the distance between current character and nearest duplicate,
//      2.1. if d > f(i-1), f(i) = f(i-1) + 1;
//      2.2. if d <= f(i-1), f(i) = d.