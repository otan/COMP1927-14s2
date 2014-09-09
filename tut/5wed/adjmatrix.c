typedef struct GraphRep *Graph;
typedef struct GraphRep {
        int   nV;    // #vertices
        int **edges; // matrix of 0/1 values
};

Graph initGraph(int nV) {
    Graph g = malloc(sizeof(*g));
    g->edges = calloc(sizeof(int), nV);

    int i;
    for (i = 0; i < nV; i++) {
        g->edges[i] = calloc(sizeof(int), nV);    
    }

    g->nV = nV;
    return g;
}

int numEdges(Graph g) {
    int num = 0;
    int i, j;
    for (i = 0; i < g->nV; i++) {
        for (j = 0; j <= i; j++) {
            num += g->edges[i][j];
        }
    }
    return num;
}


// Adjacency list graph representation

typedef struct vNode *VList;
struct vNode { 
    Vertex v; 
    VList next; 
}; 

struct graphRep { 
    int nV;       // #vertices 
    int nE;       // #edges
    VList *edges; // array of Vertex lists 
};


int numEdges(Graph g) {
    int edges = 0;
    int i;
    for (i = 0; i < g->nV; i++) {
        VList curr = g->edges[i];
        while (curr != NULL) {
            curr = curr->next;
            edges++;
        }
    }
    return edges / 2;
}
