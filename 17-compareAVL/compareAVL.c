#include <stdio.h>
#include <stdlib.h>
#include "compareAVL.h"
int compareCount = 0; // 비교 횟수 누적
int searchCount = 0;  // 탐색 횟수

// AVL 트리 구현
Node* insertAVL(Node* node, int key) {
    if (node == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->key = key;
        newNode->left = newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }

    if (key < node->key) {
        node->left = insertAVL(node->left, key);
    }
    else if (key > node->key) {
        node->right = insertAVL(node->right, key);
    }
    else {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* deleteAVL(Node* node, int key) {
    if (node == NULL) return node;

    if (key < node->key) {
        node->left = deleteAVL(node->left, key);
    }
    else if (key > node->key) {
        node->right = deleteAVL(node->right, key);
    }
    else {
        if (node->left == NULL || node->right == NULL) {
            Node* temp = node->left ? node->left : node->right;
            free(node);
            return temp;
        }

        Node* temp = node->right;
        while (temp->left != NULL) temp = temp->left;

        node->key = temp->key;
        node->right = deleteAVL(node->right, temp->key);
    }

    if (node == NULL) return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);
    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* searchAVL(Node* node, int key) {
    compareCount++;
    if (node == NULL || node->key == key) {
        searchCount++;
        return node;
    }

    return (key < node->key) ? searchAVL(node->left, key) : searchAVL(node->right, key);
}

// 이진 탐색 트리 구현
Node* insertBST(Node* node, int key) {
    if (node == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->key = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (key < node->key) {
        node->left = insertBST(node->left, key);
    }
    else if (key > node->key) {
        node->right = insertBST(node->right, key);
    }

    return node;
}

Node* deleteBST(Node* node, int key) {
    if (node == NULL) return node;

    if (key < node->key) {
        node->left = deleteBST(node->left, key);
    }
    else if (key > node->key) {
        node->right = deleteBST(node->right, key);
    }
    else {
        if (node->left == NULL || node->right == NULL) {
            Node* temp = node->left ? node->left : node->right;
            free(node);
            return temp;
        }

        Node* temp = node->right;
        while (temp->left != NULL) temp = temp->left;

        node->key = temp->key;
        node->right = deleteBST(node->right, temp->key);
    }

    return node;
}

Node* searchBST(Node* node, int key) {
    compareCount++;
    if (node == NULL || node->key == key) {
        searchCount++;
        return node;
    }

    return (key < node->key) ? searchBST(node->left, key) : searchBST(node->right, key);
}

// 공통 함수 구현
void freeTree(Node* node) {
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

void doAVLBatch(Node* root) {
    for (int i = 0; i < 2000; i++) {
        int action = rand() % 3;
        int value = rand() % 1000;
        if (action == 0) {
            root = insertAVL(root, value);
        }
        else if (action == 1) {
            root = deleteAVL(root, value);
        }
        else {
            searchAVL(root, value);
        }
    }
}

void doBinaryBatch(Node* root) {
    for (int i = 0; i < 2000; i++) {
        int action = rand() % 3;
        int value = rand() % 1000;
        if (action == 0) {
            root = insertBST(root, value);
        }
        else if (action == 1) {
            root = deleteBST(root, value);
        }
        else {
            searchBST(root, value);
        }
    }
}

int height(Node* node) {
    return (node == NULL) ? 0 : node->height;
}

int mymax(int a, int b) {
    return (a > b) ? a : b;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(Node* node) {
    return (node == NULL) ? 0 : height(node->left) - height(node->right);
}
