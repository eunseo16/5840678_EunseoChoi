#include <stdio.h>
#include <stdlib.h>
#include "primmst.h"

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

// 그래프 초기화 함수
void graph_init(GraphType* g) {
    g->n = MAX_VERTICES;
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            g->weight[i][j] = INF;
        }
    }
}

// 그래프를 생성하는 함수
void GenerateGraph(GraphType* g) {
    g->n = 10;
    g->weight[0][1] = 3; g->weight[0][5] = 11; g->weight[0][6] = 12;
    g->weight[1][2] = 5; g->weight[1][3] = 4; g->weight[1][4] = 1;
    g->weight[1][5] = 7; g->weight[1][6] = 8;
    g->weight[2][3] = 2; g->weight[2][6] = 6; g->weight[2][7] = 5;
    g->weight[3][4] = 13; g->weight[3][7] = 14; g->weight[3][9] = 16;
    g->weight[4][5] = 9; g->weight[4][8] = 18; g->weight[4][9] = 17;
    g->weight[6][7] = 13; g->weight[7][9] = 15; g->weight[8][9] = 10;

    // 대칭으로 설정 (무향 그래프)
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            if (g->weight[i][j] != INF) {
                g->weight[j][i] = g->weight[i][j];
            }
        }
    }
}

// 최소 distance[v] 값을 갖는 정점을 반환
int get_min_vertex(int n) {
    int v = -1;
    for (int i = 0; i < n; i++)
        if (!selected[i]) {
            v = i;
            break;
        }
    for (int i = 0; i < n; i++)
        if (!selected[i] && (distance[i] < distance[v]))
            v = i;
    return v;
}

// Prim 알고리즘 함수
void prim(GraphType* g, int s) {
    int u, v;
    for (u = 0; u < g->n; u++)
        distance[u] = INF;
    distance[s] = 0;
    printf("Prim MST Algorithm\n");
    for (int i = 0; i < g->n; i++) {
        u = get_min_vertex(g->n);
        selected[u] = TRUE;
        if (distance[u] == INF) return;
        printf("정점 %d 추가\n", u + 1);
        for (v = 0; v < g->n; v++)
            if (g->weight[u][v] != INF)
                if (!selected[v] && g->weight[u][v] < distance[v])
                    distance[v] = g->weight[u][v];
    }
}

// Prim을 이용해 MST를 찾는 함수
void FindPrimMST(GraphType* g) {
    for (int i = 0; i < g->n; i++) selected[i] = FALSE;
    prim(g, 0);  // 시작 정점은 0으로 설정
}
