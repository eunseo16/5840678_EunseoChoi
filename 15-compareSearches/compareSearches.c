#include <stdio.h>
#include <stdlib.h>
#include "compareSearches.h"

// 글로벌 변수 정의
int compareCount = 0;

// 랜덤 배열 생성
void generateRandomArray(int* array) {
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000; // 0~999 사이의 숫자
    }
}

// 순차 탐색
int linearSearch(int* array, int size, int target) {
    int comparisons = 0;
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (array[i] == target) {
            return comparisons;
        }
    }
    return comparisons;
}

// 평균 순차 탐색 비교 횟수 계산
double getAverageLinearSearchCompareCount(int* array) {
    double totalComparisons = 0.0;
    for (int i = 0; i < 100; i++) {
        int target = array[rand() % SIZE];
        totalComparisons += linearSearch(array, SIZE, target);
    }
    return totalComparisons / 100.0;
}

// 퀵 정렬
void quickSort(int* array, int low, int high) {
    if (low < high) {
        int pivot = array[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            compareCount++;
            if (array[j] < pivot) {
                i++;
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        int partitionIndex = i + 1;

        quickSort(array, low, partitionIndex - 1);
        quickSort(array, partitionIndex + 1, high);
    }
}

// 퀵 정렬 비교 횟수 계산
int getQuickSortCompareCount(int* array) {
    compareCount = 0;
    quickSort(array, 0, SIZE - 1);
    return compareCount;
}

// 이진 탐색
int binarySearch(int* array, int low, int high, int target) {
    int comparisons = 0;
    while (low <= high) {
        comparisons++;
        int mid = low + (high - low) / 2;

        if (array[mid] == target) {
            return comparisons;
        }
        if (array[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return comparisons;
}

// 평균 이진 탐색 비교 횟수 계산
double getAverageBinarySearchCompareCount(int* array) {
    double totalComparisons = 0.0;
    for (int i = 0; i < 100; i++) {
        int target = array[rand() % SIZE];
        totalComparisons += binarySearch(array, 0, SIZE - 1, target);
    }
    return totalComparisons / 100.0;
}

// 배열 출력
void printArray(int* array) {
    quickSort(array, 0, SIZE - 1); // 정렬 수행
    printf("Array Sorting Result:\n");
    for (int i = 0; i < 20; i++) {
        printf("%3d ", array[i]);
    }
    printf("...\n");
    for (int i = SIZE - 20; i < SIZE; i++) {
        printf("%3d ", array[i]);
    }
    printf("\n");
}
