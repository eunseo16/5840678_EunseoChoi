#pragma once

#define MAX_VERTICES 100

// 그래프 구조체 정의
typedef struct {
    int n;  // 정점의 개수
    int adj_mat[MAX_VERTICES][MAX_VERTICES];  // 인접 행렬
} GraphMatType;

// 함수 프로토타입 선언
GraphMatType* create_mat_graph();
void destroy_mat_graph(GraphMatType* g);
void init_mat_graph(GraphMatType* g);
void insert_vertex_mat_graph(GraphMatType* g, int v);
void insert_edge(GraphMatType* g, int start, int end);
void dfs(GraphMatType* g, int start, int goal);
void bfs(GraphMatType* g, int start, int goal);
