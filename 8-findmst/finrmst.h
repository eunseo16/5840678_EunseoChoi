#ifndef FINDMST_H
#define FINDMST_H

#define MAX_VERTICES 100
#define MAX_EDGES 100

typedef struct {
    int start, end, weight;
} Edge;

typedef struct {
    int n; // 정점의 개수
    int m; // 간선의 개수
    Edge edges[MAX_EDGES];
} GraphType;

// Union-Find에 사용될 부모 배열
extern int parent[MAX_VERTICES];

// 집합 초기화 함수
void set_init(int n);

// 집합의 루트를 찾는 함수
int set_find(int vertex);

// 두 집합을 합치는 함수
void set_union(int root1, int root2);

// qsort를 위한 간선 비교 함수
int compare(const void* a, const void* b);

// qsort 기반 Kruskal 알고리즘 함수
void QuickKruskal(GraphType* g);

// MinHeap 구성 함수
void heapify(Edge arr[], int n, int i);

// MinHeap 생성 함수
void buildMinHeap(Edge arr[], int n);

// MinHeap에서 최소 가중치 간선을 추출하는 함수
Edge extractMin(Edge arr[], int* n);

// MinHeap 기반 Kruskal 알고리즘 함수
void MinHeapKruskal(GraphType* g);

// 그래프 초기화 함수
void graph_init(GraphType* g);

// 그래프 생성 함수 (간선을 직접 추가)
void GenerateGraph(GraphType* g);

#endif // FINDMST_H
