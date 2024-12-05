#ifndef COMPARE_SEARCHES_H
#define COMPARE_SEARCHES_H

#define SIZE 1000 // 배열 크기 정의

// 외부 변수 선언
extern int compareCount;

// 함수 프로토타입 선언
void generateRandomArray(int* array);
int linearSearch(int* array, int size, int target);
double getAverageLinearSearchCompareCount(int* array);
void quickSort(int* array, int low, int high);
int getQuickSortCompareCount(int* array);
int binarySearch(int* array, int low, int high, int target);
double getAverageBinarySearchCompareCount(int* array);
void printArray(int* array);

#endif // COMPARE_SEARCHES_H
