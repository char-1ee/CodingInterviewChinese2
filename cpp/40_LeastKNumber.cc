// Q40: Smallest k numbers
// Description: given n integers, find the smallest k numbers among them.
// Example: {4, 5, 1, 6, 2, 7, 3, 8} k = 4. Then return {1, 2, 3, 4}.

#include <bits/stdc++.h>
#include "utils/Array.h"

using namespace std;

// O(n), Partition() + binary search
void LeastKNumber_1(int arr[], int length, int k) {
    if (arr == nullptr || k > length || length < 1 || k < 1) {
        printf("Invalid input\n");
        return;
    }

    int start = 0;
    int end = length - 1;
    int index = Partition(arr, length, start, end); // O(n)

    while (index != k - 1) {
        if (index > k - 1) {
            end = index - 1;
            index = Partition(arr, length, start, end);
        } else {
            start = index + 1;
            index = Partition(arr, length, start, end);
        }
    }

    PrintArray(arr, length, 0, index); // k numbers are not guaranteed sorted
}

// O(nlogk), Heap (good ar dealing with big data -> save space)
void LeastKNumber_2(int arr[], int length, int k) {
    if (arr == nullptr || k > length || length < 1 || k < 1) {
        printf("Invalid input\n");
        return;
    }

    priority_queue<int, vector<int>, less<int>> pq;

    for (int i = 0; i < length; i++) {
        pq.push(arr[i]);
        if (pq.size() > k) {
            pq.pop();
        }
    } // push first then pop max

    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
    cout << '\n';
}

// Same as solution 2, but using multiset in STL (implemented by RB tree)
typedef multiset<int, greater<int>> intSet;
typedef multiset<int, greater<int>>::iterator setIterator;

void LeastKNumber_3(const vector<int>& arr, intSet& leastKNumbers, int k) {
    leastKNumbers.clear();

    if (k < 1 || arr.size() < k) {
        return;
    }

    vector<int>::const_iterator iter = arr.begin();
    for (; iter != arr.end(); ++iter) {
        if ((leastKNumbers.size()) < k) {
            leastKNumbers.insert(*iter);
        } else {
            setIterator iterGreatest = leastKNumbers.begin();

            if (*iter < *(leastKNumbers.begin())) {
                leastKNumbers.erase(iterGreatest);
                leastKNumbers.insert(*iter);
            }
        }
    }

    for (setIterator iter = leastKNumbers.begin(); iter != leastKNumbers.end(); iter++) {
        cout << *iter << ' ';
    }
    cout << '\n';
}

// ============= test ===============
void Test(const string test_name, int arr[], int length, int k) {
    cout << "-----" << test_name << "-----" << endl;

    PrintArray(arr, length, 0, length - 1);

    printf("Solution 1: \n");
    LeastKNumber_1(arr, length, k);

    printf("Solution 2: ");
    if (arr == nullptr) {
        LeastKNumber_2(nullptr, length, k);
    } else {
        int arr_copy[length];
        copy(arr, arr + length, arr_copy);
        LeastKNumber_2(arr_copy, length, k);
    }

    printf("Solution 3: ");
    vector<int> list;
    if (arr != nullptr) {
        for (int i = 0; i < length; i++) {
            list.push_back(arr[i]);
        }
    }

    intSet leastKNumbers;
    LeastKNumber_3(list, leastKNumbers, k);
}

int main(int argc, char** argv) {
    int arr[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int arr2[] = {2, 5, 1, 2, 2, 7, 2, 8};

    Test("Test 1", arr, 8, 4); // k < length
    Test("Test 2", arr, 8, 8); // k = length
    Test("Test 3", arr, 8, 10); // k > length
    Test("Test 4", arr, 8, 1); // k = 1
    Test("Test 5", arr, 8, 0); // k = 0
    Test("Test 6", arr2, 8, 4); // same elements
    Test("Test 7", nullptr, 8, 0); // nullptr

    return 0;
}