#include <cstdlib>
#include <cstdio>
#include <exception>
#include "Array.h"

// Return a random number in range of [min, max]
int Random(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Swap two element in array
void Swap(int* num1, int* num2) {
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

// Random quick sort partition: reutrn the index whose element location can be determined
int Partition(int arr[], int length, int start, int end) {
    if (arr == nullptr || length < 0 || start < 0 || end >= length) {
        throw "Invalid parameters";
    }

    int index = Random(start, end);
    Swap(&arr[index], &arr[start]);

    int pivot = arr[start];
    int i = start, j = end + 1; // balance j

    while (true) {
        while (arr[++i] < pivot) { // find the first num >= pivot
            if (i == end) {
                break;
            }
        }

        while (arr[--j] > pivot) { // find the first num <= pivot
            if (j == start) {
                break;
            }
        }

        if (i >= j) { // check two ptr not cross
            break;
        }

        Swap(&arr[start], &arr[j]); // arrang smaller left, larger right
    }
    return j;
}

void PrintArray(int* arr, int length, int start, int end) {
    if (arr == nullptr || length <= 0 || start <= 0 || end >= length || end < start) {
        return;
    }
    for (int i = start; i <= end; ++i) {
        printf("%d  ", &arr[i]);
    }
    printf("\n");
}