#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "interpolationSearch.h"

// 랜덤 배열 생성 함수
void generateRandomArray(int* array) {
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 10000;  // 0부터 9999까지의 값
    }
}

// QuickSort 구현
void QuickSort(int* array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        QuickSort(array, low, pi - 1);  // 왼쪽 부분 정렬
        QuickSort(array, pi + 1, high);  // 오른쪽 부분 정렬
    }
}

int partition(int* array, int low, int high) {
    int pivot = array[high];  // 피벗 선택
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return i + 1;
}

// 배열 출력 함수 (처음 20개, 마지막 20개)
void printArray(int* array) {
    printf("Array Sorting Result:\n");
    for (int i = 0; i < 20; i++)
        printf("%4d ", array[i]);
    printf("\n");
    for (int i = SIZE - 20; i < SIZE; i++)
        printf("%4d ", array[i]);
    printf("\n\n");
}

// 이진 탐색
int binarySearch(int* array, int target) {
    int left = 0, right = SIZE - 1;
    int compareCount = 0;

    while (left <= right) {
        compareCount++;
        int mid = left + (right - left) / 2;

        if (array[mid] == target)
            return compareCount;  // 타겟을 찾으면 비교 횟수 반환
        else if (array[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return compareCount;  // 타겟을 찾지 못한 경우
}

// Interpolation 탐색
int interpolationSearch(int* array, int target) {
    int left = 0, right = SIZE - 1;
    int compareCount = 0;

    while (left <= right && target >= array[left] && target <= array[right]) {
        compareCount++;
        int pos = left + ((target - array[left]) * (right - left)) / (array[right] - array[left]);

        if (array[pos] == target)
            return compareCount;  // 타겟을 찾으면 비교 횟수를 반환
        else if (array[pos] < target)
            left = pos + 1;
        else
            right = pos - 1;
    }
    return compareCount;  // 타겟을 찾지 못한 경우
}

// 이진 탐색의 평균 비교 횟수
double getAverageBinarySearchCompareCount(int* array) {
    int totalCompareCount = 0;
    for (int i = 0; i < 1000; i++) {
        int target = array[rand() % SIZE];  // 랜덤한 값 선택
        totalCompareCount += binarySearch(array, target);
    }
    return totalCompareCount / 1000.0;
}

// Interpolation 탐색의 평균 비교 횟수
double getAverageInterpolationSearchCompareCount(int* array) {
    int totalCompareCount = 0;
    for (int i = 0; i < 1000; i++) {
        int target = array[rand() % SIZE];  // 랜덤한 값 선택
        totalCompareCount += interpolationSearch(array, target);
    }
    return totalCompareCount / 1000.0;
}
