/*
 * Test by Oliveer Tan (otan@cse.unsw.edu.au);
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Graph.h"

#define VERTICES 30
#define EDGES 80
#define ITERATIONS 1000

int it(int x) {
    switch (x % 4) {
        case 3:
            return 1;
        case 2:
            return 2;
            break;
        case 1:
            return 4;
            break;
        default:
            return EDGES;
    }
}

void testEulerPath(void) {
    int i, j;
    for (i = 0; i < ITERATIONS; i++) {
        Graph g = initGraph(VERTICES);
        int tos[VERTICES];
        
        memset(tos, 0, sizeof(int) * VERTICES);
        for (j = 0; j < (i % 2 ? 2 : (EDGES + rand() % EDGES)); j++) {
            int f = rand() % VERTICES;
            int t = rand() % VERTICES;
           
            if (insertEdge(g, f, t)) {
                tos[f]++;
                if (f != t) {
                    tos[t]++;
                }
            }
        }

        int i;
        int odds;
        for (i = 0, odds = 0; i < g->nV; i++) {
            if (tos[i] % 2 == 1) {
                odds++;
            }
        }
        printf("Graph we are testing on:\n");
        printGraph(g);
        printf("Does it have an Euler Path? %s\n", (odds == 2) ? "YES" : "NO");
        int res = isEulerPath(g); 
        printf("Do you think there's an Euler Path? %s\n", res ? "YES" : "NO");
        if (odds == 2) {
            assert(res);
        } else {
            assert(!res);
        }
        destroyGraph(g);
        printf("Test passed!\n");
        printf("================================================\n");
    }
}

int main(void) {
    srand(1927);
    testEulerPath();
    printf("i am satisfied with your function. congratulations. asian father approves.\n");
    return 0;
}
