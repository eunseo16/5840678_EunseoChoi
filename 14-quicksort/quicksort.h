#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

// 전역 변수
extern int comparisonCount;
extern int moveCount;
extern int totalComparisons;
extern int totalMoveCount;
extern int isFirst;
extern int rounds;

// 함수 선언
void generateRandomArray(int array[]);
void printArray(int array[], int size);
void doIterativeQuickSort(int array[], int size);
int partition(int array[], int low, int high);

#endif
