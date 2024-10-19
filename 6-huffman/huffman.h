#pragma once

#define MAX_ELEMENT 200

typedef struct TreeNode {
    int weight;
    char ch;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct {
    TreeNode* root;
    char ch;
    int key;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

HeapType* create();
void init(HeapType* h);
void insert_min_heap(HeapType* h, element item);
element delete_min_heap(HeapType* h);
TreeNode* make_tree(TreeNode* left, TreeNode* right);
void destroy_tree(TreeNode* root);
int is_leaf(TreeNode* root);
void print_array(int codes[], int n);
void print_codes(TreeNode* root, int codes[], int top);
void GenerateHuffmanCodes(int frequencies[], char characters[], int size);
void print_heap(HeapType* h); // 추가된 함수
