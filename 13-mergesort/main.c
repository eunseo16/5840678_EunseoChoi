#include "mergesort.h"

int main() {
    int array[SIZE];

    srand(time(NULL)); // 랜덤 시드 설정

    for (int i = 0; i < 20; i++) {
        generateRandomArray(array);
        comparisonCount = 0;
        moveCount = 0;

        if (i == 0) {
            printf("Merge Sort Run\n");
            doIterativeMergeSort(array, SIZE);

            printf("Result\n");
            printArray(array, SIZE);
            isFirst++;
        }
        else {
            doIterativeMergeSort(array, SIZE);
        }

        totalComparisons += comparisonCount;
        totalMoves += moveCount;
    }

    printf("\nAverage Comparisons: %.2f\n", totalComparisons / 20.0);
    printf("Average Moves: %.2f\n", totalMoves / 20.0);

    return 0;
}
