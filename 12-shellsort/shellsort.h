#ifndef SHELLSORT_H
#define SHELLSORT_H

#define ARRAY_SIZE 100

void generateRandomNumbers(int* array);
void printArray(int* array, int size);
void doShellSort(int* array, int gap_divisor, int* comparisonCount, int* moveCount);
void doInsertionSort(int* array, int* comparisonCount, int* moveCount);

#endif // SHELLSORT_H
