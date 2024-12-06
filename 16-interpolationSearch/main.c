#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "interpolationSearch.h"

#define SIZE 10000

int main(int argc, char* argv[]) {
    srand(time(NULL));

    int array[SIZE];
    for (int i = 0; i < 3; i++) {
        generateRandomArray(array);  // 배열에 10000개의 랜덤 값 생성

        // QuickSort를 사용하여 배열 정렬
        QuickSort(array, 0, SIZE - 1);

        // 배열 출력 (처음 20개, 마지막 20개)
        printArray(array);

        // 이진 탐색과 Interpolation 탐색의 평균 비교 횟수 출력
        printf("Average Compare Count of Binary Search: %.2f\n", getAverageBinarySearchCompareCount(array));
        printf("Average Compare Count of Interpolation Search: %.2f\n", getAverageInterpolationSearchCompareCount(array));
    }

    return 0;
}
