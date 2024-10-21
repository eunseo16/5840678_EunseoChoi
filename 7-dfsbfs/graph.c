#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// 스택 구조체 및 함수
typedef struct {
    int data[MAX_VERTICES];
    int top;
} Stack;

void init_stack(Stack* s) {
    s->top = -1;
}

int is_stack_empty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int item) {
    if (s->top < MAX_VERTICES - 1) {
        s->data[++(s->top)] = item;
    }
}

int pop(Stack* s) {
    if (!is_stack_empty(s)) {
        return s->data[(s->top)--];
    }
    return -1;
}

// 큐 구조체 및 함수
typedef struct {
    int data[MAX_VERTICES];
    int front, rear;
} Queue;

void init_queue(Queue* q) {
    q->front = q->rear = 0;
}

int is_queue_empty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, int item) {
    if ((q->rear + 1) % MAX_VERTICES != q->front) {
        q->data[q->rear] = item;
        q->rear = (q->rear + 1) % MAX_VERTICES;
    }
}

int dequeue(Queue* q) {
    if (!is_queue_empty(q)) {
        int item = q->data[q->front];
        q->front = (q->front + 1) % MAX_VERTICES;
        return item;
    }
    return -1;
}

// 그래프 생성 및 초기화
GraphMatType* create_mat_graph() {
    return (GraphMatType*)malloc(sizeof(GraphMatType));
}

void destroy_mat_graph(GraphMatType* g) {
    free(g);
}

void init_mat_graph(GraphMatType* g) {
    g->n = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            g->adj_mat[i][j] = 0;
        }
    }
}

void insert_vertex_mat_graph(GraphMatType* g, int v) {
    g->n++;
}

void insert_edge(GraphMatType* g, int start, int end) {
    if (start >= g->n || end >= g->n) {
        fprintf(stderr, "정점 번호 오류\n");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

// 깊이 우선 탐색 (DFS)
void dfs(GraphMatType* g, int start, int goal) {
    int visited[MAX_VERTICES] = { 0 };
    Stack s;
    int visited_count = 0;
    int node;

    init_stack(&s);
    push(&s, start);

    while (!is_stack_empty(&s)) {
        node = pop(&s);
        if (!visited[node]) {
            visited[node] = 1;
            visited_count++;
            printf("%d ", node);
            if (node == goal) {
                printf("\n탐색 성공: 목표 %d 찾음\n", goal);
                printf("방문한 노드의 수: %d\n", visited_count);
                return;
            }
            // 큰 번호부터 푸시하여 작은 번호를 먼저 방문하게 함
            for (int i = g->n - 1; i >= 0; i--) {
                if (g->adj_mat[node][i] && !visited[i]) {
                    push(&s, i);
                }
            }
        }
    }
    printf("\n탐색 실패: 목표 %d 찾지 못함\n", goal);
    printf("방문한 노드의 수: %d\n", visited_count);
}


// 너비 우선 탐색 (BFS)
void bfs(GraphMatType* g, int start, int goal) {
    int visited[MAX_VERTICES] = { 0 };
    Queue q;
    int visited_count = 0;

    init_queue(&q);
    enqueue(&q, start);
    visited[start] = 1;

    while (!is_queue_empty(&q)) {
        int v = dequeue(&q);
        printf("%d ", v);
        visited_count++;

        if (v == goal) {
            printf("\n탐색 성공: 목표 %d 찾음\n", goal);
            printf("방문한 노드의 수: %d\n", visited_count);
            return;
        }

        for (int i = 0; i < g->n; i++) {
            if (g->adj_mat[v][i] && !visited[i]) {
                enqueue(&q, i);
                visited[i] = 1;
            }
        }
    }
    printf("\n탐색 실패: 목표 %d 찾지 못함\n", goal);
    printf("방문한 노드의 수: %d\n", visited_count);
}
