bool hasEulerTour(Graph g) { 
    int i, j, degrees;
    for (i = 0; i < g->nV; i++) {
        degrees = 0;
        for (j = 0; j < g->nV; j++) {
            // check whether 1 or 0
            if (g->matrix[i][j]) {
                degrees++;
            }
        }
        if (degrees % 2 == 1) {
            return 0;
        }
    }
    return 1;
}

bool hasEulerPath(Graph g) { 
    int i, j, degrees, counter = 0;
    for (i = 0; i < g->nV; i++) {
        degrees = 0;
        for (j = 0; j < g->nV; j++) {
            // check whether 1 or 0
            if (g->matrix[i][j]) {
                degrees++;
            }
        }
        if (degrees % 2 == 1) {
            counter++;
            if (counter > 2) {
                return 0;
            }
        }
    }
    return (counter == 2);
}
