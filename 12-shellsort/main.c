#include <stdio.h>
#include "shellsort.h"

int main() {
    int array[ARRAY_SIZE];
    int comparisonCount, moveCount;

    generateRandomNumbers(array);

    // Shell Sort (n/2)
    doShellSort(array, 2, &comparisonCount, &moveCount);

    // Shell Sort (n/3)
    doShellSort(array, 3, &comparisonCount, &moveCount);

    // Insertion Sort
    doInsertionSort(array, &comparisonCount, &moveCount);

    return 0;
}
