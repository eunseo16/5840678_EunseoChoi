#pragma once
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000

typedef struct {
    int n;  // 정점의 개수
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

extern int distance[MAX_VERTICES]; // 시작 정점으로부터의 최단경로 거리
extern int found[MAX_VERTICES];    // 방문한 정점 표시

// 함수 선언
int choose(int distance[], int n, int found[]);
void shortest_path(GraphType* g, int start);
void print_status(GraphType* g);
void print_found(GraphType* g);
void print_found_order();

#endif // DIJKSTRA_H
