#pragma once

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

// 그래프 구조체 정의
typedef struct {
    int n;  // 정점의 개수
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// 함수 프로토타입 선언
void graph_init(GraphType* g);
void GenerateGraph(GraphType* g);
int get_min_vertex(int n);
void prim(GraphType* g, int s);
void FindPrimMST(GraphType* g);
