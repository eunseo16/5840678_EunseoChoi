#include <stdio.h>
#include <stdlib.h>
#include "findmst.h"

int main(void) {
    GraphType* g = (GraphType*)malloc(sizeof(GraphType));
    graph_init(g); // 그래프 초기화

    GenerateGraph(g); // 간선 추가

    QuickKruskal(g);     // qsort 기반 Kruskal 실행
    MinHeapKruskal(g);   // MinHeap 기반 Kruskal 실행

    free(g); // 동적 메모리 해제
    return 0;
}
