#include <stdio.h>
#include <stdlib.h>
#include "huffman.h"

// �� ����ü�� �����ϴ� �Լ�
HeapType* create() {
    return (HeapType*)malloc(sizeof(HeapType));
}

// ���� �ʱ�ȭ�ϴ� �Լ�
void init(HeapType* h) {
    h->heap_size = 0;
}

// ���� ���� ���¸� ����ϴ� �Լ�
void print_heap(HeapType* h) {
    for (int i = 1; i <= h->heap_size; i++) {
        printf("%d ", h->heap[i].key);
    }
    printf("\n");
}

// �ּ� ���� ���ο� ��Ҹ� �����ϴ� �Լ�
void insert_min_heap(HeapType* h, element item) {
    int i = ++(h->heap_size);

    // ���ο� ��Ҹ� ������ ��ġ�� �����ϱ� ���� �θ�� ��
    while ((i != 1) && (item.key < h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;

    // �� ���� ���
    print_heap(h);
}

// �ּ� ������ �ּҰ��� �����ϴ� �Լ�
element delete_min_heap(HeapType* h) {
    int parent, child;
    element item = h->heap[1];  // ������ �ּҰ�
    element temp = h->heap[(h->heap_size)--];  // ������ ������ ��Ҹ� ������

    parent = 1;
    child = 2;

    // �ڽĵ�� ���Ͽ� ������ ��ġ�� ����
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

// Ʈ���� �����ϴ� �Լ� (����, ������ �ڽ��� �޾� ���ο� ��� ����)
TreeNode* make_tree(TreeNode* left, TreeNode* right) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->left = left;
    node->right = right;
    return node;
}

// ���� Ʈ���� �����ϴ� �Լ� (���� ��ȸ ������� ����)
void destroy_tree(TreeNode* root) {
    if (root == NULL) return;
    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root);
}

// �ܸ� ���(���� ���)���� Ȯ���ϴ� �Լ�
int is_leaf(TreeNode* root) {
    return !(root->left) && !(root->right);
}

// �־��� �ڵ带 ����ϴ� �Լ�
void print_array(int codes[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d", codes[i]);
    printf("\n");
}

// ������ �ڵ带 ����ϴ� �Լ�
void print_codes(TreeNode* root, int codes[], int top) {
    // ���� �ڽĿ� 1 �Ҵ�
    if (root->left) {
        codes[top] = 1;
        print_codes(root->left, codes, top + 1);
    }

    // ������ �ڽĿ� 0 �Ҵ�
    if (root->right) {
        codes[top] = 0;
        print_codes(root->right, codes, top + 1);
    }

    // �ܸ� ��忡 �����ϸ� �ڵ带 ���
    if (is_leaf(root)) {
        printf("%c: ", root->ch);
        print_array(codes, top);
    }
}

// ������ Ʈ���� �����ϴ� �Լ�
void GenerateHuffmanCodes(int frequencies[], char characters[], int size) {
    int i;
    TreeNode* node, * x;
    HeapType* heap;
    element e, e1, e2;
    int arr[100];  // ������ �ڵ� ���� �迭
    int top = 0;  // �ڵ� �迭�� �ε���

    // �� ���� �� �ʱ�ȭ
    heap = create();
    init(heap);

    //��� ���ڿ� �󵵸� ���� ����
    for (i = 0; i < size; i++) {
        node = make_tree(NULL, NULL);  // �� ��� ����
        e.ch = node->ch = characters[i];  // ���ڸ� ��忡 ����
        e.key = node->weight = frequencies[i];  // �󵵸� ��忡 ����
        e.root = node;
        insert_min_heap(heap, e);  // ���� ����
    }

    //������ Ʈ�� ����
    for (i = 1; i < size; i++) {
        // �ּҰ��� ������ �� ���� ��带 ����
        e1 = delete_min_heap(heap);
        e2 = delete_min_heap(heap);

        // �� ���� ��带 ��ģ��.
        x = make_tree(e1.root, e2.root);
        e.key = x->weight = e1.key + e2.key;
        e.root = x;

        // ���� ������ ���
        printf("///%d + %d -> %d\n", e1.key, e2.key, e.key);

        // ���ο� ��带 ���� ����
        insert_min_heap(heap, e);
    }

    e = delete_min_heap(heap); // ���� Ʈ��
    print_codes(e.root, arr, top);

    //Ʈ�� �� �� �޸� ����
    destroy_tree(e.root);
    free(heap);
}
