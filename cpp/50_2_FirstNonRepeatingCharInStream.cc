// Q50_2: first character appears once in a character stream
// Description: find the first non-repeating character in a given character stream.
// Example: when read in "go", return 'g; when read in "google", return 'l'.

#include <cstdio>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

const int TABLE_SIZE = 256;

class CharacterStream {
public:
    CharacterStream()
        : index(0) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = -1;
        }
    }

    void Insert(char c) {
        if (table[c] == -1) {
            table[c] = index;
        } else if (table[c] >= 0) {
            table[c] = -2;
        }

        index++;
    }

    char FirstUniqueChar() {
        char c = '\0'; // if not found non-repeating char, return '\0'
        int first_occurrence_index = numeric_limits<int>::max(); // defined in cpp standard

        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] >= 0 && table[i] < first_occurrence_index) {
                first_occurrence_index = table[i];
                c = i;
            }
        }
        return c;
    }

private:
    // table[i] = i:  character's occurence index
    // table[i] = -1: character not found
    // table[i] = -2: character found multiple times
    // table[i] >= 0: character found only once
    int table[TABLE_SIZE];
    int index;
};

void Test(string test_name, CharacterStream char_stream, char expected) {
    if (char_stream.FirstUniqueChar() == expected) {
        cout << test_name << ": Passed." << endl;
    } else {
        cout << test_name << ": FAILED." << endl;
    }
}

int main(int argc, char* argv[]) {
    CharacterStream chars;

    Test("Test1", chars, '\0');

    chars.Insert('g');
    Test("Test2", chars, 'g');

    chars.Insert('o');
    Test("Test3", chars, 'g');

    chars.Insert('o');
    Test("Test4", chars, 'g');

    chars.Insert('g');
    Test("Test5", chars, '\0');

    chars.Insert('l');
    Test("Test6", chars, 'l');

    chars.Insert('e');
    Test("Test7", chars, 'l');

    return 0;
}