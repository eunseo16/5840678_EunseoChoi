#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "compareAVL.h"

int main() {
    for (int i = 0; i < 3; i++) {
        Node* root = NULL;
        srand(time(NULL));
        float allCount = 0.0;

        // AVL 트리 작업
        doAVLBatch(root);
        allCount = (float)compareCount / searchCount;
        printf("average AVL compare count: %.2f\n", allCount);

        freeTree(root);
        root = NULL;
        compareCount = allCount = 0;

        // 이진 탐색 트리 작업
        doBinaryBatch(root);
        allCount = (float)compareCount / searchCount;
        printf("average Bin compare count: %.2f\n", allCount);

        freeTree(root);
    }
    return 0;
}
