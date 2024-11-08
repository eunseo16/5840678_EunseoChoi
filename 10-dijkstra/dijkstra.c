#include "dijkstra.h"
#include <stdio.h>
#include <limits.h>

int distance[MAX_VERTICES];
int found[MAX_VERTICES];
int found_order[MAX_VERTICES];  // 방문 순서 저장 배열
int found_count = 0;            // 방문한 정점 수 카운트

int choose(int distance[], int n, int found[]) {
    int i, min = INT_MAX, minpos = -1;
    for (i = 0; i < n; i++)
        if (distance[i] < min && !found[i]) {
            min = distance[i];
            minpos = i;
        }
    return minpos;
}

void shortest_path(GraphType* g, int start) {
    int i, u, w;
    for (i = 0; i < g->n; i++) { // 초기화
        distance[i] = g->weight[start][i];
        found[i] = FALSE;
    }
    found[start] = TRUE; // 시작 정점 방문 표시
    distance[start] = 0;
    found_order[found_count++] = start + 1;  // 첫 정점 추가

    // 초기 상태 출력
    print_status(g);
    print_found(g);
    printf("\n");

    // 알고리즘 실행
    for (i = 0; i < g->n - 1; i++) {
        u = choose(distance, g->n, found);
        found[u] = TRUE;
        found_order[found_count++] = u + 1;  // 방문 순서 기록
        for (w = 0; w < g->n; w++) {
            if (!found[w]) {
                if (distance[u] + g->weight[u][w] < distance[w]) {
                    distance[w] = distance[u] + g->weight[u][w];
                }
            }
        }
        print_status(g);  // 각 단계마다 거리 상태 출력
        print_found(g);   // 각 단계마다 방문 상태 출력
        printf("\n");
    }
    print_found_order();  // 방문 순서 출력
}

void print_status(GraphType* g) {
    printf("Distance: ");
    for (int i = 0; i < g->n; i++) {
        if (distance[i] == INF)
            printf("* ");
        else
            printf("%d ", distance[i]);
    }
    printf("\n");
}

void print_found(GraphType* g) {
    printf("Found: ");
    for (int i = 0; i < g->n; i++) {
        printf("%d ", found[i]);
    }
    printf("\n");
}

void print_found_order() {
    printf("Found Order: ");
    for (int i = 0; i < found_count; i++) {
        printf("%d ", found_order[i]);
    }
    printf("\n");
}
