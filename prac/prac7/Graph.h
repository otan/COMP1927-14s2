#ifndef _GRAPH_H_
#define _GRAPH_H_

typedef int Vertex;

typedef struct _graph *Graph;

typedef struct _graph {
    int **edges;
    int nV;
} graph;

Graph initGraph(int nV);
void destroyGraph(Graph g);
void printGraph(Graph g);
int insertEdge(Graph g, Vertex from, Vertex to);
int isEulerPath(Graph g);

#endif
