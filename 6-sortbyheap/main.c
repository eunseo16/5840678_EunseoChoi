#include <stdio.h>
#include "heap.h"

int main() {
    int inputData[] = { 34, 12, 76, 59, 32, 55, 88, 26, 16, 79, 35, 85, 29, 78, 41, 56, 86 };
    int size = sizeof(inputData) / sizeof(inputData[0]);

    // �� ���� ����
    printf("<Sort>\n");
    BuildMaxHeapAndSort(inputData, size);

    // ���ĵ� ��� ���
    printf("Sorted Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", inputData[i]);
    }
    printf("\n");

    return 0;
}
