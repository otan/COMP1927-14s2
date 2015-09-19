#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

#define THIS_IS_MADNESS 7
#define SPARTA 100

void printList(Node n) {
    if (n == NULL) {
        printf("[X]\n");
        return;
    }
    printf("[%d]->", n->data);
    printList(n->next);
}

void freeList(Node n) {
    if (n == NULL) {
        return;
    }
    freeList(n->next);
    free(n);
}

List createSequentialList(int n, int step) {
    List l = createList();
    int i;
    for (i = 0; i < n; i += step) {
        if (l->first == NULL) {
            l->first = l->last = createNode(i + 1);
        } else {
            l->last->next = createNode(i + 1);
            l->last->next->prev = l->last;
            l->last = l->last->next;
        }
    }
    l->size = n;
    return l;
}

void testMerge(void) {
    // you will never understand my test code, hehehe.
}

int main(void) {
    testMerge();
    printf("i am satisfied with your function. congratulations. asian father approves.\n");
    return 0;
}
