#include <stdio.h>
#include "dijkstra.h"

int main(void) {
    GraphType g = { 10,
        {{0, 3, INF, INF, INF, 11, 12, INF, INF, INF},
        {3, 0, 5, 4, 1, 7, 8, INF, INF, INF},
        {INF, 5, 0, 2, INF, INF, 6, 5, INF, INF},
        {INF, 4, 2, 0, 13, INF, INF, 14, INF, 16},
        {INF, 1, INF, 13, 0, 9, INF, INF, 18, 17},
        {11, 7, INF, INF, 9, 0, INF, INF, INF, INF},
        {12, 8, 6, INF, INF, INF, 0, 13, INF, INF},
        {INF, INF, 5, 14, INF, INF, 13, 0, INF, 15},
        {INF, INF, INF, INF, 18, INF, INF, INF, 0, 10},
        {INF, INF, INF, 16, 17, INF, INF, 15, 10, 0}} };

    shortest_path(&g, 0);
    return 0;
}
