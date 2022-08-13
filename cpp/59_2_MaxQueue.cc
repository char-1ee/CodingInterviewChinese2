// Q59_2: Max Queue
// Description: Implement a queue data structure that get maximum elements in queue. max(),
// push_back() and pop_front() must be in time O(1).

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class MaxQueue {
public:
    MaxQueue() {}
    ~MaxQueue() {}

    T max() {
        if (maxq.empty()) {
            throw "Empty queue";
        }
        return maxq.front();
    }

    void push_back(T t) {
        while (!maxq.empty() && t >= maxq.back()) {
            maxq.pop_back();
        }
        dataq.push_back(t);
        maxq.push_back(t);
    }

    void pop_front() {
        if (maxq.empty()) {
            throw "Empty queue";
        }
        T t = dataq.front();
        dataq.pop_front();
        if (t == maxq.front()) {
            maxq.pop_front();
        }
    }

    void clear() {
        deque<T> empty1, empty2;
        swap(empty1, dataq);
        swap(empty2, maxq);
    }

private:
    deque<T> dataq;
    deque<T> maxq;
};

void Test(const char* testName, MaxQueue<int>& queue, int expected) {
    printf("%s begins: ", testName);

    if (queue.max() == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[]) {
    MaxQueue<int> queue;

    queue.push_back(2); // {2}
    Test("Test1", queue, 2);

    queue.push_back(3); // {2, 3}
    Test("Test2", queue, 3);

    queue.push_back(4); // {2, 3, 4}
    Test("Test3", queue, 4);

    queue.push_back(2); // {2, 3, 4, 2}
    Test("Test4", queue, 4);


    queue.pop_front(); // {3, 4, 2}
    Test("Test5", queue, 4);

 
    queue.pop_front(); // {4, 2}
    Test("Test6", queue, 4);


    queue.pop_front(); // {2}
    Test("Test7", queue, 2);


    queue.push_back(6); // {2, 6}
    Test("Test8", queue, 6);

    queue.push_back(2); // {2, 6, 2}
    Test("Test9", queue, 6);

    queue.push_back(5); // {2, 6, 2, 5}
    Test("Test9", queue, 6);

    queue.pop_front(); // {6, 2, 5}
    Test("Test10", queue, 6);

    queue.pop_front(); // {2, 5}
    Test("Test11", queue, 5);

    queue.pop_front(); // {5}
    Test("Test12", queue, 5);

    queue.push_back(1); // {5, 1}
    Test("Test13", queue, 5);

    return 0;
}