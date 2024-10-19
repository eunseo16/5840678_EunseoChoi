#ifndef HEAP_H
#define HEAP_H

void swap(int* a, int* b);
void heapify(int arr[], int n, int i);
void BuildMaxHeap(int arr[], int n);
void BuildMaxHeapAndSort(int inputData[], int n);
void printArray(int arr[], int n);

#endif // HEAP_H
