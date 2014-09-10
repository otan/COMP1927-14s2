bool hasEulerTour(Graph g) { 
    int i, j;
    for (i = 0; i < g->nV; i++) {
        int count = 0;
        for (j = 0; j < g->nV; j++) {
            if (g->edges[i][j]) {
                count++;
            }
        }

        if (count % 2 == 1) {
            return 0;
        }
    }
    return 1;
}

bool hasEulerPath(Graph g) {
    int i, j, countOdd = 0;
    for (i = 0; i < g->nV; i++) {
        int count = 0;
        for (j = 0; j < g->nV; j++) {
            if (g->edges[i][j]) {
                count++;
            }
        }

        if (count % 2 == 1) {
            countOdd++;
            if (countOdd > 2) {
                return 0;
            }
        }
    }
    return (countOdd == 2);
}
