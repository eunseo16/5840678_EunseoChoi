#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "compareSearches.h"

int main(int argc, char* argv[]) {
    srand(time(NULL));
    int array[SIZE];
    for (int run = 1; run <= 3; run++) {

        generateRandomArray(array);

        printf("Average Linear Search Compare Count: %.2f\n",
            getAverageLinearSearchCompareCount(array));

        getQuickSortCompareCount(array);
        printf("Quick Sort Compare Count: %d\n", compareCount);

        printf("Average Binary Search Compare Count: %.2f\n\n",
            getAverageBinarySearchCompareCount(array));

        printArray(array);
    }
    return 0;
}
