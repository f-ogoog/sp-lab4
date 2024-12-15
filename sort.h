#ifndef SORT
#define SORT
#include "stringProcessor.h"
#include <string.h>

void swap(char** a, char** b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort_recursive(char** arr, int left, int right) {
    if (left >= right) {
        return;
    }

    char* pivot = arr[right];
    int partition_index = left;

    for (int i = left; i < right; i++) {
        if (strcmp(arr[i], pivot) < 0) {
            swap(&arr[i], &arr[partition_index]);
            partition_index++;
        }
    }

    swap(&arr[partition_index], &arr[right]);


    quick_sort_recursive(arr, left, partition_index - 1);
    quick_sort_recursive(arr, partition_index + 1, right);
}

void quick_sort(char** arr, size_t length) {
    if (length > 1) {
        quick_sort_recursive(arr, 0, length - 1);
    }
}
#endif // !SORT
