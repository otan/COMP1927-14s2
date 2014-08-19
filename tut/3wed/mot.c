void setMedianOfThree(Item a[], int lo, int hi) { 
    int mid = (lo + hi) / 2;
    if (a[lo] > a[mid]) {
        swap(&a[lo], &a[mid]);
    }
    if (a[mid] > a[hi]) {
        swap(&a[mid], &a[hi]);
    }
    if (a[lo] > a[mid]) {
        swap(&a[lo], &a[mid]);
    }
    // move middle number to where we want
    swap(&a[mid], &a[hi]);
}

Node minToFront(Node first) {
    Node prev = NULL, curr = first;
    Node min_prev = NULL, min_curr = first;

    while (curr != NULL) {
        if (curr->data < min_curr->data) {
            min_prev = prev;
            min_curr = curr;
        }
        prev = curr;
        curr = curr->next;
    }
    if (min_prev != NULL) {
        min_prev->next = min_curr->next;
        min_curr->next = first;
    }
    return min_curr;
}

Node selectionSort(Node curr) {
    if (curr == NULL) {
        return NULL;
    }
    curr = minToFront(curr);
    curr->next = selectionSort(curr->next);
    return curr;
}

Node selectionSort(Node first) {
    Node curr = first, prev = NULL;
    while (curr != NULL) {
        if (prev == NULL) {
            first = minToFront(first);
        } else {
            prev->next = minToFront(curr);
        }
        prev = curr;
        curr = curr->next;
    }
    return first;
}
