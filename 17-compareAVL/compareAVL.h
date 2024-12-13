#ifndef COMPARE_AVL_H
#define COMPARE_AVL_H

typedef struct Node {
    int key;
    struct Node* left, * right;
    int height;
} Node;

// AVL 트리를 위한 함수
Node* insertAVL(Node* node, int key);
Node* deleteAVL(Node* node, int key);
Node* searchAVL(Node* node, int key);
int height(Node* node);
int mymax(int a, int b);
Node* rightRotate(Node* y);
Node* leftRotate(Node* x);
int getBalance(Node* node);

// 이진 탐색 트리를 위한 함수
Node* insertBST(Node* node, int key);
Node* deleteBST(Node* node, int key);
Node* searchBST(Node* node, int key);

// 공통 함수
void freeTree(Node* node);
void doAVLBatch(Node* root);
void doBinaryBatch(Node* root);

extern int compareCount;
extern int searchCount;

#endif // COMPARE_AVL_H
