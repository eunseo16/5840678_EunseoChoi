#include <stdio.h>
#include "heap.h"

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i; // ��Ʈ
    int left = 2 * i + 1; // ���� �ڽ�
    int right = 2 * i + 2; // ������ �ڽ�

    // ���� �ڽİ� ��
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // ������ �ڽİ� ��
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // largest�� ��Ʈ�� �ٸ��� �����ϰ� ��������� heapify
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void resortHeap(int arr[], int n) {
    // ������ ��� ���� ���� ������ heapify ����
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void BuildMaxHeapAndSort(int inputData[], int n) {
    // ���� �ϳ��� �÷����� ����
    for (int i = 0; i < n; i++) {
        // ���ο� ��� �߰�
        swap(&inputData[i], &inputData[0]); // �� �տ� �߰�
        resortHeap(inputData, i + 1); // �� �籸��
        printArray(inputData, i + 1); // ���� ���� ���
    }

    // �ִ밪�� �ϳ��� ����
    for (int i = n - 1; i > 0; i--) {
        swap(&inputData[0], &inputData[i]); // ������ ��ҿ� ����
        heapify(inputData, i, 0); // �� �籸��
        printArray(inputData, i); // ���� ���� ���
    }
}

void printArray(int arr[], int n) {
    for (int j = 0; j < n; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");
}
