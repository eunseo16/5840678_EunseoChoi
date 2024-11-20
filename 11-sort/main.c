#include <stdio.h>
#include "sort.h"

int main() {
    srand(time(0));  // 난수 생성기 초기화
    int randomData[SIZE];
    generateRandomData(randomData);  // 랜덤 데이터 생성

    doSelectionSort(randomData);  // 선택 정렬 수행
    doInsertionSort(randomData);  // 삽입 정렬 수행
    doBubbleSort(randomData);  // 버블 정렬 수행

    return 0;
}
