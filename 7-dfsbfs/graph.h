#pragma once

#define MAX_VERTICES 100

// �׷��� ����ü ����
typedef struct {
    int n;  // ������ ����
    int adj_mat[MAX_VERTICES][MAX_VERTICES];  // ���� ���
} GraphMatType;

// �Լ� ������Ÿ�� ����
GraphMatType* create_mat_graph();
void destroy_mat_graph(GraphMatType* g);
void init_mat_graph(GraphMatType* g);
void insert_vertex_mat_graph(GraphMatType* g, int v);
void insert_edge(GraphMatType* g, int start, int end);
void dfs(GraphMatType* g, int start, int goal);
void bfs(GraphMatType* g, int start, int goal);
