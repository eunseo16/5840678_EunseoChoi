#include <stdio.h>
#include <stdlib.h>
#include "huffman.h"

// 힙 구조체를 생성하는 함수
HeapType* create() {
    return (HeapType*)malloc(sizeof(HeapType));
}

// 힙을 초기화하는 함수
void init(HeapType* h) {
    h->heap_size = 0;
}

// 힙의 현재 상태를 출력하는 함수
void print_heap(HeapType* h) {
    for (int i = 1; i <= h->heap_size; i++) {
        printf("%d ", h->heap[i].key);
    }
    printf("\n");
}

// 최소 힙에 새로운 요소를 삽입하는 함수
void insert_min_heap(HeapType* h, element item) {
    int i = ++(h->heap_size);

    // 새로운 요소를 적절한 위치에 삽입하기 위해 부모와 비교
    while ((i != 1) && (item.key < h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;

    // 힙 상태 출력
    print_heap(h);
}

// 최소 힙에서 최소값을 삭제하는 함수
element delete_min_heap(HeapType* h) {
    int parent, child;
    element item = h->heap[1];  // 삭제할 최소값
    element temp = h->heap[(h->heap_size)--];  // 힙에서 마지막 요소를 가져옴

    parent = 1;
    child = 2;

    // 자식들과 비교하여 적절한 위치에 삽입
    while (child <= h->heap_size) {
        if ((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key))
            child++;
        if (temp.key < h->heap[child].key) break;

        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;

    return item;
}

// 트리를 생성하는 함수 (왼쪽, 오른쪽 자식을 받아 새로운 노드 생성)
TreeNode* make_tree(TreeNode* left, TreeNode* right) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->left = left;
    node->right = right;
    return node;
}

// 이진 트리를 삭제하는 함수 (후위 순회 방식으로 삭제)
void destroy_tree(TreeNode* root) {
    if (root == NULL) return;
    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root);
}

// 단말 노드(리프 노드)인지 확인하는 함수
int is_leaf(TreeNode* root) {
    return !(root->left) && !(root->right);
}

// 주어진 코드를 출력하는 함수
void print_array(int codes[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d", codes[i]);
    printf("\n");
}

// 허프만 코드를 출력하는 함수
void print_codes(TreeNode* root, int codes[], int top) {
    // 왼쪽 자식에 1 할당
    if (root->left) {
        codes[top] = 1;
        print_codes(root->left, codes, top + 1);
    }

    // 오른쪽 자식에 0 할당
    if (root->right) {
        codes[top] = 0;
        print_codes(root->right, codes, top + 1);
    }

    // 단말 노드에 도착하면 코드를 출력
    if (is_leaf(root)) {
        printf("%c: ", root->ch);
        print_array(codes, top);
    }
}

// 허프만 트리를 생성하는 함수
void GenerateHuffmanCodes(int frequencies[], char characters[], int size) {
    int i;
    TreeNode* node, * x;
    HeapType* heap;
    element e, e1, e2;
    int arr[100];  // 허프만 코드 저장 배열
    int top = 0;  // 코드 배열의 인덱스

    // 힙 생성 및 초기화
    heap = create();
    init(heap);

    //모든 문자와 빈도를 힙에 삽입
    for (i = 0; i < size; i++) {
        node = make_tree(NULL, NULL);  // 새 노드 생성
        e.ch = node->ch = characters[i];  // 문자를 노드에 저장
        e.key = node->weight = frequencies[i];  // 빈도를 노드에 저장
        e.root = node;
        insert_min_heap(heap, e);  // 힙에 삽입
    }

    //허프만 트리 구축
    for (i = 1; i < size; i++) {
        // 최소값을 가지는 두 개의 노드를 삭제
        e1 = delete_min_heap(heap);
        e2 = delete_min_heap(heap);

        // 두 개의 노드를 합친다.
        x = make_tree(e1.root, e2.root);
        e.key = x->weight = e1.key + e2.key;
        e.root = x;

        // 결합 과정을 출력
        printf("///%d + %d -> %d\n", e1.key, e2.key, e.key);

        // 새로운 노드를 힙에 삽입
        insert_min_heap(heap, e);
    }

    e = delete_min_heap(heap); // 최종 트리
    print_codes(e.root, arr, top);

    //트리 및 힙 메모리 해제
    destroy_tree(e.root);
    free(heap);
}
