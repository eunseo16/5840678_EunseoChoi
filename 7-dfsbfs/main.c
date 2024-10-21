#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    GraphMatType* g = create_mat_graph();
    init_mat_graph(g);

    // 정점 추가
    for (int i = 0; i < 11; i++) {  // 0부터 10까지 정점 추가
        insert_vertex_mat_graph(g, i);
    }

    int edges[][2] = {
    {0, 2}, {0, 4}, {0, 5}, {0, 6}, {0, 9},
    {1, 4}, {1, 5}, {1, 7}, {1, 10},
    {2, 3}, {2, 4},
    {3, 4}, {3, 5},
    {4, 5}, {4, 6}, {4, 7},
    {6, 7}, {6, 8},
    {7, 10},
    {8, 9}, {8, 10}
    };

    int num_edges = sizeof(edges) / sizeof(edges[0]);
    for (int i = 0; i < num_edges; i++) {
        insert_edge(g, edges[i][0], edges[i][1]);
    }

    int choice, start, goal;

    printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
    printf("1       : 깊이 우선 탐색   | \n2       : 너비 우선 탐색   |\n3       : 종료             |\n");
    printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");


    while (1) {
        printf("\n메뉴 입력: ");
        scanf_s("%d", &choice);

        if (choice == 3) {
            printf("프로그램 종료...\n");
            break;
        }

        printf("시작 번호와 탐색할 값 입력: ");
        scanf_s("%d %d", &start, &goal);

        switch (choice) {
        case 1:
            dfs(g, start, goal);
            break;
        case 2:
            bfs(g, start, goal);
            break;
        default:
            printf("잘못된 선택입니다!\n");
        }
    }

    destroy_mat_graph(g);
    return 0;
}
