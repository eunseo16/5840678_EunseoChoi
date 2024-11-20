#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "shellsort.h"

// 랜덤 숫자를 생성하여 배열에 저장함
void generateRandomNumbers(int* array) {
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000;
    }
}
// 배열을 제한된 개수만 출력
void printArrayWithLimit(int* array, int size, int limit) {
    for (int i = 0; i < size && i < limit; i++) {
        printf("%d ", array[i]);
    }
    if (size > limit) {
        printf("...");
    }
    printf("\n");
}
// 배열의 모든 값을 출력
void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
// Shell Sort 알고리즘 실행 함수
void doShellSort(int* array, int gap_divisor, int* comparisonCount, int* moveCount) {
    int tempArray[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) tempArray[i] = array[i];

    int gap, i, j, temp;
    *comparisonCount = 0; // 비교 횟수 초기화
    *moveCount = 0; //이동 횟수 초기화

    if (gap_divisor == 2) {
        gap = ARRAY_SIZE / 2;
    }
    else if (gap_divisor == 3) {
        gap = ARRAY_SIZE / 3;
    }
    else {
        return; // 잘못된 간격 기준인 경우 종료
    }

    printf("Shell Sort (n/%d):", gap_divisor);
    while (gap > 0) { // 간격이 0이 될 때까지 반복
        printf("\nSorting with gap = %d:\n", gap);
        printArrayWithLimit(tempArray, ARRAY_SIZE, 20); // 최대 20개 출력

        for (i = gap; i < ARRAY_SIZE; i++) {
            temp = tempArray[i]; // 현재 값 저장
            (*moveCount)++; // 이동 횟수 증가
            for (j = i; j >= gap && tempArray[j - gap] > temp; j -= gap) {
                tempArray[j] = tempArray[j - gap]; // 값을 이동
                (*comparisonCount)++; // 비교 횟수 증가
                (*moveCount)++; // 이동 횟수 증가
            }
            tempArray[j] = temp; // 값을 삽입
            (*moveCount)++; // 이동 횟수 증가
            (*comparisonCount)++; // 비교 횟수 증가
        }
        gap = (gap == 1) ? 0 : gap / gap_divisor;
    }

    printf("\nSorted ShellArray (gap = %d):\n", gap_divisor);
    printArray(tempArray, ARRAY_SIZE); // 전체 출력
    printf("\nShell Sort (n/%d) - Comparisons: %d, Moves: %d\n\n", gap_divisor, *comparisonCount, *moveCount);
}

// 삽입 정렬(Insertion Sort) 실행 함수
void doInsertionSort(int* array, int* comparisonCount, int* moveCount) {
    int tempArray[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) tempArray[i] = array[i];

    int i, j, temp;
    *comparisonCount = 0; // 비교 횟수 초기화
    *moveCount = 0; // 이동 횟수 초기화

    printf("Insertion Sort:\n");
    for (i = 1; i < ARRAY_SIZE; i++) {
        temp = tempArray[i];
        (*moveCount)++;
        for (j = i; j > 0 && tempArray[j - 1] > temp; j--) {
            tempArray[j] = tempArray[j - 1];
            (*comparisonCount)++;
            (*moveCount)++;
        }
        tempArray[j] = temp;
        (*moveCount)++;
        (*comparisonCount)++;
    }
    printf("Sorted insertionArray:\n");
    printArray(tempArray, ARRAY_SIZE); // 전체 출력
    printf("\nInsertion Sort - Comparisons: %d, Moves: %d\n", *comparisonCount, *moveCount);
}
