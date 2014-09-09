void freeListNodes(Node n) {
    if (n == NULL) {
        return;
    }
    freeListNodes(n->next);
    free(n);
}

void freeList(List l) {
    // freeListNodes(l->first);
    if (l->first == NULL) {
        return;
    }
    Node temp = l->first;
    l->first = l->first->next;
    freeList(l);
    free(temp);
}

void printListReverse(Node n) {
    if (n == NULL) {
        return;
    }
    printListReverse(n->next);
    printf("%d\n", n->data);
}
