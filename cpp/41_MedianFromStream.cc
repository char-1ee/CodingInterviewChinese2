// Q41: Median number in a data stream.
// Read median from a data stream.

#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

// Insert O(logn), GetMedian O(1)
template <class T>
class MedianFinder {
public:
    // Insert into min heap when even size, max heap when odd size.
    void Insert(T t) {
        if (((max.size() + min.size()) & 1) == 0) // even size
        {
            if (max.size() > 0 && t < max[0]) {
                max.push_back(t);
                push_heap(max.begin(), max.end(), less<T>());

                t = max[0];

                pop_heap(max.begin(), max.end(), less<T>());
                max.pop_back();
            }

            min.push_back(t);
            push_heap(min.begin(), min.end(), greater<T>());
        } else // odd size
        {
            if (min.size() > 0 && min[0] < t) {
                min.push_back(t);
                push_heap(min.begin(), min.end(), greater<T>());

                t = min[0];

                pop_heap(min.begin(), min.end(), greater<T>());
                min.pop_back();
            }

            max.push_back(t);
            push_heap(max.begin(), max.end(), less<T>());
        }
    }

    T GetMedian() {
        int size = min.size() + max.size();
        if (size == 0) {
            return -1;
        }

        T median = 0;
        if ((size & 1) == 0) {
            median = (min[0] + max[0]) / 2;
        } else {
            median = min[0];
        }

        return median;
    }

private:
    vector<T> min; // min heap, larger than median, min[0]->p2
    vector<T> max; // max heap, smaller than median, max[0]->p1
};

// unit testing
void Test(string test_name, MedianFinder<double>& data, double expected) {
    cout << test_name << ": ";

    if (abs(data.GetMedian() - expected) < 0.000001) {
        printf("Passed\n");
    } else {
        printf("FAILED\n");
    }
}

int main(int argc, char** argv) {
    MedianFinder<double> data;

    printf("Test1 begins: \n");

    data.Insert(5);
    Test("Test2", data, 5);

    data.Insert(2);
    Test("Test3", data, 3.5);

    data.Insert(3);
    Test("Test4", data, 3);

    data.Insert(4);
    Test("Test6", data, 3.5);

    data.Insert(1);
    Test("Test5", data, 3);

    data.Insert(6);
    Test("Test7", data, 3.5);

    data.Insert(7);
    Test("Test8", data, 4);

    data.Insert(0);
    Test("Test9", data, 3.5);

    data.Insert(8);
    Test("Test10", data, 4);

    return 0;
}
