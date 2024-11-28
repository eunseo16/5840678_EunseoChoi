#include "mergesort.h"

int comparisonCount = 0;
int moveCount = 0;
int totalComparisons = 0;
int totalMoves = 0;
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

void doIterativeMergeSort(int array[], int size) {
    int currentSize;  // 현재 부분 배열의 크기
    int leftStart;    // 부분 배열의 왼쪽 시작점

    // 부분 배열 크기를 1부터 시작하여 점진적으로 늘림
    for (currentSize = 1; currentSize < size; currentSize *= 2) {
        // 부분 배열의 시작점 설정
        for (leftStart = 0; leftStart < size - 1; leftStart += 2 * currentSize) {
            int mid = leftStart + currentSize - 1;
            int rightEnd = (leftStart + 2 * currentSize - 1 < size - 1) ? (leftStart + 2 * currentSize - 1) : (size - 1);

            // 병합 수행
            merge(array, leftStart, mid, rightEnd);

            // 출력 조건
            rounds++;
            if (rounds % 10 == 0 && isFirst == 0) {
                for (int i = 0; i < 10; i++) // 처음부터 10개 출력
                    printf("%3d ", array[i]);
                printf("| ");
                for (int i = SIZE / 2 - 1; i < SIZE / 2 + 10; i++) // 중앙-1 ~ 중앙+10
                    printf("%3d ", array[i]);
                printf("\n\n");
            }
        }
    }
}

void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* leftArray = (int*)malloc(n1 * sizeof(int));
    int* rightArray = (int*)malloc(n2 * sizeof(int));

    // 서브 배열 복사
    for (int i = 0; i < n1; i++) {
        leftArray[i] = array[left + i];
        moveCount++;
    }
    for (int i = 0; i < n2; i++) {
        rightArray[i] = array[mid + 1 + i];
        moveCount++;
    }

    int i = 0, j = 0, k = left;

    // 병합
    while (i < n1 && j < n2) {
        comparisonCount++;
        if (leftArray[i] <= rightArray[j]) {
            array[k++] = leftArray[i++];
        }
        else {
            array[k++] = rightArray[j++];
        }
        moveCount++;
    }

    // 나머지 복사
    while (i < n1) {
        array[k++] = leftArray[i++];
        moveCount++;
    }
    while (j < n2) {
        array[k++] = rightArray[j++];
        moveCount++;
    }

    free(leftArray);
    free(rightArray);
}
