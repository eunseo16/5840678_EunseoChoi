#ifndef MERGESORT_H
#define MERGESORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

// 전역 변수
extern int comparisonCount;
extern int moveCount;
extern int totalComparisons;
extern int totalMoves;
extern int isFirst;
extern int rounds;

// 함수 선언
void generateRandomArray(int array[]);
void printArray(int array[], int size);
void doIterativeMergeSort(int array[], int size);
void merge(int array[], int left, int mid, int right);

#endif
