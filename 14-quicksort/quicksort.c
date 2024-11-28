#include "quicksort.h"

int comparisonCount = 0;
int moveCount = 0;
int totalComparisons = 0;
int totalMoveCount = 0;
int isFirst = 0;
int rounds = 0;

void generateRandomArray(int array[]) {
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000; // 0~999 범위의 랜덤 값 생성
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%3d ", array[i]);
    }
    printf("\n");
}

void doIterativeQuickSort(int array[], int size) {
    // 스택 크기를 충분히 크게 설정
    int stack[2 * SIZE];
    int top = -1;

    // 초기 범위 추가
    stack[++top] = 0;
    stack[++top] = size - 1;

    while (top >= 0) {
        // 스택에서 현재 범위를 가져옴
        int high = stack[top--];
        int low = stack[top--];

        if (low < high) {
            // 분할
            int pivotIndex = partition(array, low, high);

            // 정렬 과정 출력
            rounds++;
            if (rounds % 10 == 0 && isFirst == 0) {
                for (int i = 40; i < 60; i++) // 40~60 위치 값 출력
                    printf("%3d ", array[i]);
                printf("\n\n");
            }

            // 오른쪽 부분 배열 추가
            if (pivotIndex + 1 < high) {
                stack[++top] = pivotIndex + 1;
                stack[++top] = high;
            }

            // 왼쪽 부분 배열 추가
            if (pivotIndex - 1 > low) {
                stack[++top] = low;
                stack[++top] = pivotIndex - 1;
            }
        }
    }
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisonCount++;
        if (array[j] < pivot) {
            i++;
            // Swap
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            moveCount += 3;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    moveCount += 3;

    return i + 1;
}
