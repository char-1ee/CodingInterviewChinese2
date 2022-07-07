#include <bits/stdc++.h>

using namespace std;

bool StrComparator(string s1, string s2);

/**
 * @parameter: arr[] integer array, all integers in int range
 * @parameter: length: length of arr[]
 * @return the minimum value(can be overflow) the integers in arr[] can concatenate to
 */
string FindMinPermutation(int arr[], int length) {
    if (length <= 0 || arr == nullptr) {
        return "Invalid";
    }
    if (length == 1) {
        return to_string(arr[0]);
    }

    string str_num;
    string str_arr[length];
    for (int i = 0; i < length; ++i) {
        str_arr[i] = to_string(arr[i]);
    }

    sort(str_arr, str_arr + length, StrComparator);
    // TODO: qsort and proof comparator

    for (int i = 0; i < length; ++i) {
        str_num.append(str_arr[i]);
    }

    return str_num;
}

bool StrComparator(const string s1, const string s2) {
    string mn = s1 + s2;
    string nm = s2 + s1;
    return mn < nm;
}

// ====== testing ========
void Test(string test_name, int arr[], int length, string expected) {
    cout << "-----" << test_name << "-----" << endl;

    // the result can be overflow, so using string
    string result = FindMinPermutation(arr, length);
    if (result == expected) {
        printf("Passed.\n");
    } else {
        printf("FAILED.\n");
    }
}

void Test1() {
    int numbers[] = {3, 5, 1, 4, 2};
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), "12345");
}

void Test2() {
    int numbers[] = {3, 32, 321};
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), "321323");
}

void Test3() {
    int numbers[] = {3, 323, 32123};
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), "321233233");
}

void Test4() {
    int numbers[] = {1, 11, 111};
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), "111111");
}

void Test5() {
    int numbers[] = {321};
    Test("Test5", numbers, sizeof(numbers) / sizeof(int), "321");
}

void Test6() {
    Test("Test6", nullptr, 0, "Invalid");
}

int main(int argc, char** argv) {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}

// 1. Give all permutations and find the smallest (backtracking + min heap)' -> n!
// 2. Greedy -> x
// 3. Convert to string and sort string array -> O(nlogn)