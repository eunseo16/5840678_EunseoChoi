#include <stdio.h>
#include "heap.h"

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i; // 루트
    int left = 2 * i + 1; // 왼쪽 자식
    int right = 2 * i + 2; // 오른쪽 자식

    // 왼쪽 자식과 비교
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // 오른쪽 자식과 비교
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // largest가 루트와 다르면 스왑하고 재귀적으로 heapify
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void resortHeap(int arr[], int n) {
    // 마지막 비어 있지 않은 노드부터 heapify 수행
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void BuildMaxHeapAndSort(int inputData[], int n) {
    // 힙을 하나씩 늘려가며 구성
    for (int i = 0; i < n; i++) {
        // 새로운 요소 추가
        swap(&inputData[i], &inputData[0]); // 맨 앞에 추가
        resortHeap(inputData, i + 1); // 힙 재구성
        printArray(inputData, i + 1); // 현재 상태 출력
    }

    // 최대값을 하나씩 제거
    for (int i = n - 1; i > 0; i--) {
        swap(&inputData[0], &inputData[i]); // 마지막 요소와 스왑
        heapify(inputData, i, 0); // 힙 재구성
        printArray(inputData, i); // 현재 상태 출력
    }
}

void printArray(int arr[], int n) {
    for (int j = 0; j < n; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");
}
