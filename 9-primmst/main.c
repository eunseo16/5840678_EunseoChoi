#include <stdio.h>
#include <stdlib.h>
#include "primmst.h"

int main(void) {
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    graph_init(g);

    // 그래프를 생성하는 함수 호출
    GenerateGraph(g);

    FindPrimMST(g);// Prim을 이용해 MST를 찾음

    free(g);
    return 0;
}
