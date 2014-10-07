/* Complete "isEulerPath". self explanatory.
 * prac exam question last year.
 *
 * testGraph: gcc -Wall -Werror -O -o testGraph testGraph.c Graph.c
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "Graph.h"

Graph initGraph(int nV) {
    Graph g = malloc(sizeof(*g));
    g->edges = calloc(nV, sizeof(int*));
    int i;
    for (i = 0; i < nV; i++) {
        g->edges[i] = calloc(nV, sizeof(int));
    }
    g->nV = nV;
    return g;
}

void destroyGraph(Graph g) {
    int i;
    for (i = 0; i < g->nV; i++) {
        free(g->edges[i]);
    }
    free(g->edges);
    free(g);
}

void printGraph(Graph g) {
    int i, j;
    printf("    |");
    for (j = 0; j < g->nV; j++) {
        printf(" %2d |", j);
    }
    printf("\n");
    for (j = 0; j < g->nV + 1; j++) {
        printf("-----");
    }
    printf("\n");
    for (i = 0; i < g->nV; i++) {
        printf(" %2d |", i);
        for (j = 0; j < g->nV; j++) {
            printf(" %2d |", g->edges[i][j]);
        }
        printf("\n");
    }
}

int insertEdge(Graph g, Vertex from, Vertex to) {
    if (g->edges[from][to]) {
        return 0;
    }
    int random_weight = rand() % 100 + 1;
    g->edges[from][to] = random_weight;
    g->edges[to][from] = random_weight;
    return 1;
}

int isEulerPath(Graph g) {
    return 0;
}
