// Graph.c ... implementation of Graph ADT
// Written by John Shepherd, May 2013

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "Graph.h"
#include "Queue.h"

// graph representation (adjacency matrix)
typedef struct GraphRep {
	int    nV;    // #vertices
	int    nE;    // #edges
	int  **edges; // matrix of weights (0 == no edge)
} GraphRep;

// check validity of Vertex
int validV(Graph g, Vertex v)
{
	return (g != NULL && v >= 0 && v < g->nV);
}

// make an edge
Edge mkEdge(Graph g, Vertex v, Vertex w)
{
	assert(g != NULL && validV(g,v) && validV(g,w));
	Edge new = {v,w}; // struct assignment
	return new;
}

// insert an Edge
// - sets (v,w) and (w,v)
void insertEdge(Graph g, Vertex v, Vertex w, int wt)
{
	assert(g != NULL && validV(g,v) && validV(g,w));
	if (g->edges[v][w] == 0) {
		g->edges[v][w] = wt;
		g->edges[w][v] = wt;
		g->nE++;
	}
}

// remove an Edge
// - unsets (v,w) and (w,v)
void removeEdge(Graph g, Vertex v, Vertex w)
{
	assert(g != NULL && validV(g,v) && validV(g,w));
	if (g->edges[v][w] != 0) {
		g->edges[v][w] = 0;
		g->edges[w][v] = 0;
		g->nE--;
	}
}

// create an empty graph
Graph newGraph(int nV)
{
    Graph g = malloc(sizeof(*g));
    g->nV = nV;
    g->nE = 0;
    g->edges = malloc(sizeof(int*) * nV);
    int i;
    for (i = 0; i < g->nV; i++) {
        g->edges[i] = calloc(nV, sizeof(int));
    }
    return g; // dummy ... doesn't create an empty graph
}

// free memory associated with graph
void dropGraph(Graph g)
{
	assert(g != NULL);
	// not needed for this lab
}

// display graph, using names for vertices
void showGraph(Graph g, char **names)
{
	assert(g != NULL);
	printf("#vertices=%d, #edges=%d\n\n",g->nV,g->nE);
	int v, w;
	for (v = 0; v < g->nV; v++) {
		printf("%d %s\n",v,names[v]);
		for (w = 0; w < g->nV; w++) {
			if (g->edges[v][w]) {
				printf("\t%s (%d)\n",names[w],g->edges[v][w]);
			}
		}
		printf("\n");
	}
}

// find a path between two vertices using breadth-first traversal
// only allow edges whose weight is less than "max"
int findPath(Graph g, Vertex src, Vertex dest, int max, int *path)
{
	assert(g != NULL && validV(g,src) && validV(g,dest));

    Edge e = mkEdge(g, src, src);
    int i, order = 0;
    int *pre = malloc(g->nV*sizeof(int));
    int *st = malloc(g->nV*sizeof(int));
    for (i = 0; i < g->nV; i++)
    { pre[i] = st[i] = -1; }
    Queue q = newQueue();
    QueueJoin(q,e); pre[e.w] = order++;
    while (!QueueIsEmpty(q)) {
        Edge e = QueueLeave(q);
        st[e.w] = e.v;
        Vertex v;
        for (v = 0; v < g->nV; v++) {
            if (g->edges[e.w][v] <= 0 || g->edges[e.w][v] >= max) continue;
            if (pre[v] == -1) {
                QueueJoin(q, mkEdge(g,e.w,v));
                pre[v] = order++;
            }
        }
    }

    Vertex curr = dest;
    int counter = 0;
    while (curr != src) {
        path[counter++] = curr;
        curr = st[curr];
    }
    path[counter++] = src;
    for (i = 0; i < counter / 2; i++) {
        int temp = path[i];
        path[i] = path[counter - i - 1];
        path[counter - i - 1] = temp;
    }
    return counter;  // dummy ... always claims there is no path
}
