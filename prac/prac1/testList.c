#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

int main(void) {
    int i, t;
    Node start;
    for (t = 0; t <= 100; t++) {
        printf("testing createSequentialList(%d);\n", t);
        start = createSequentialList(t);
        printf("created okay. now traversing it...\n");
        for (i = 1; i <= t; i++) {
            assert(start != NULL);
            assert(start->data == i);
            start = start->next;
        }
        assert(start == NULL);
        printf("you win createSequentialList(%d);\n", t);
        int j; for (j = 0; j < 50; j++) printf("*");
        printf("\n");
    }
    printf("Jade sucks!\n");
    return 0;
}
