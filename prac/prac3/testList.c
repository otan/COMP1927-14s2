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

List createSequentialList(int n) {
    List l = createList();
    int i;
    for (i = 0; i < n; i++) {
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

void testAppend(void) {
    int t, i, j, k, l;
    for (t = 0; t < THIS_IS_MADNESS; t++) {
        for (i = 0; i < t; i++) {
           for (j = 0; j < t; j++) {
                List l1 = createSequentialList(i);
                List l2 = createSequentialList(j);
                Node ptr = l2->last;
                if (j == 0) {
                    ptr = l1->last;
                }
                Node ptrb = l1->first;
                if (i == 0) {
                    ptrb = l2->first;
                }

                printf("appending a %d item l1 to a %d item l2\n", i, j);
                append(l1, l2);
                printf("append did not seg fault!\n");
                printf("if you seg fault after here, you probably made a bad link\n");
                printf("is l2 empty?\n");
                assert(l2->first == NULL);
                assert(l2->last == NULL);
                assert(l2->size == 0);

                Node curr = l1->first;

                printf("testing going forwards\n");
                for (k = 1; k <= i; k++) {
                    assert(curr->data == k);
                    curr = curr->next;
                }
                for (l = 1; l <= j; l++) {
                    assert(curr->data == l);
                    curr = curr->next;
                }
                assert(curr == NULL);

                printf("test going backward\n");
                curr = l1->last;
                for (l = j; l >= 1; l--) {
                    assert(curr->data == l);
                    curr = curr->prev;
                }
                for (k = i; k >= 1; k--) {
                    assert(curr->data == k);
                    curr = curr->prev;
                }
                assert(curr == NULL);
                
                printf("are the pointers assigned correctly?\n");
                assert(l1->first == ptrb); 
                assert((l1->last) == ptr);
                assert(l1->size == i + j);

                printf("*** passed (l1=%d, l2=%d)! ***\n\n", i, j);
                freeList(l1->first);
                free(l1);
                free(l2);
            }
        }
    }
}

int main(void) {
    testAppend();
    printf("i am satisfied with your function. congratulations. asian father approves.\n");
    return 0;
}
