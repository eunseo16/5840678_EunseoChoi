#ifndef INTERPOLATIONSEARCH_H
#define INTERPOLATIONSEARCH_H

#define SIZE 10000

// 함수 선언
void generateRandomArray(int* array);
void QuickSort(int* array, int low, int high);
int partition(int* array, int low, int high);
void printArray(int* array);
int binarySearch(int* array, int target);
int interpolationSearch(int* array, int target);
double getAverageBinarySearchCompareCount(int* array);
double getAverageInterpolationSearchCompareCount(int* array);

#endif // INTERPOLATIONSEARCH_H
