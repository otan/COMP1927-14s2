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

List createSequentialListBut(int n, int but) {
    List l = createList();
    int i;
    for (i = 0; i < n; i++) {
        if (but == i) {
            continue;
        }
        if (l->first == NULL) {
            l->first = l->last = createNode(i);
        } else {
            l->last->next = createNode(i);
            l->last->next->prev = l->last;
            l->last = l->last->next;
        }
    }
    l->size = n - 1;
    return l;
}

List createSequentialList(int n) {
    List l = createList();
    int i;
    for (i = 0; i <= n; i++) {
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

void testIIO(void) {
    int t, i, j;
    for (t = 0; t < THIS_IS_MADNESS; t++) {
        for (i = 0; i < t; i++) {
            List l = createSequentialListBut(t, i);
            printf("Starting List: ");
            printList(l->first);
            printf("Adding element: [%d]\n", i);
            insertInOrder(l, createNode(i));
            printf("* Progress! Your insertInOrder did not segfault! But does the list work...\n");
            printf("go forwards... output of your list:");

            Node curr = l->first, prev = NULL;
            for (j = 0; j < t; j++) {
                printf("[%d]->", curr->data);
                assert(curr != NULL);
                assert(curr->data == j);
                assert(curr->prev == prev);
                prev = curr; 
                curr = curr->next;
            }
            printf("[X]\n");

            assert(l->last == prev);
            assert(curr == NULL);
            printf("go backwards... output of your list:");

            curr = l->last; prev = NULL;
            for (j = t - 1; j >= 0; j--) {
                printf("[%d]->", curr->data);
                assert(curr != NULL);
                assert(curr->data == j);
                assert(curr->next == prev);
                prev = curr;
                curr = curr->prev;
            }
            printf("[X]\n");

            assert(l->first == prev);
            assert(curr == NULL);

            printf("is the size right?\n");
            assert(l->size == t);
            
            printf("You have passed this test!\n");
            freeList(l->first);
            free(l);
            printf("==================================================\n");
        }
    }
}

int main(void) {
    testIIO();
    printf("i am satisfied with your function. congratulations. asian father approves.\n");
    return 0;
}
