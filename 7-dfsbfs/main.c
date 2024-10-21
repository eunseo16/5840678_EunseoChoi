#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    GraphMatType* g = create_mat_graph();
    init_mat_graph(g);

    // ���� �߰�
    for (int i = 0; i < 11; i++) {  // 0���� 10���� ���� �߰�
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

    printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
    printf("1       : ���� �켱 Ž��   | \n2       : �ʺ� �켱 Ž��   |\n3       : ����             |\n");
    printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤ�");


    while (1) {
        printf("\n�޴� �Է�: ");
        scanf_s("%d", &choice);

        if (choice == 3) {
            printf("���α׷� ����...\n");
            break;
        }

        printf("���� ��ȣ�� Ž���� �� �Է�: ");
        scanf_s("%d %d", &start, &goal);

        switch (choice) {
        case 1:
            dfs(g, start, goal);
            break;
        case 2:
            bfs(g, start, goal);
            break;
        default:
            printf("�߸��� �����Դϴ�!\n");
        }
    }

    destroy_mat_graph(g);
    return 0;
}
