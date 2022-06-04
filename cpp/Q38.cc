// permutation of string
// backtracking: for a sub problem/problem, swap the beginning char with all chars 
// after itself to get new permutations.

#include <cstdio>

using namespace std;

void Permutation(char* s, char* start);

void Permutation(char* s) {
    if (s == nullptr) {
        return;
    }
    Permutation(s, s);
}

void Permutation(char* s, char* start) {
    if (*start == '\0') {
        printf("%s\n", s);
        return;
    }
    
    for (char* c = start; *c != '\0'; ++c) {
        // swap char value of pStart and a position after pStart
        char tmp = *c;
        *c = *start;
        *start = tmp;

        Permutation(s, start + 1); 

        // backtracking
        tmp = *c;
        *c = *start;
        *start = tmp;
    }
}

void Test(char* s) {
    if (s == nullptr) {
        printf("Test for nullptr:\n");
    } else {
        printf("Test for %s:\n", s);
    }

    Permutation(s);
    printf("\n");
}

// unit testing
int main(int argc, char** argv) {
    char s1[] = "abcd";
    char s2[] = "abc";
    char s3[] = "a";
    char s4[] = "";
    
    Test(s1);
    Test(s2);
    Test(s3);
    Test(s4);
    Test(nullptr);

    return 0;
}