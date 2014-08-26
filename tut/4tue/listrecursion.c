void dropListNodes(Node curr) {
    if (curr == NULL) {
        return;     
    }
    dropListNodes(curr->next);
    free(curr);
}

void dropList(List l) {
    //dropListNodes(l->first);
    if (l->first == NULL) {
        return;
    }
    Node temp = l->first;
    l->first = l->first->next;
    dropList(l);
    free(temp);
}

// [9] -> [14] -> [21] -> [X]
//
void printReverse(Node curr) {
    if (curr == NULL) {
        return;
    }

    printReverse(curr->next); // [9],[14],[21]
    printf("%d\n", curr->data);
}

void pr1(Node first) {
    Node prev = NULL, curr = first;
    while (first != NULL) {
        while (curr->next != NULL) {
            prev = curr;
            curr = curr->next;
        }
        if (prev == NULL) {
            first = NULL;
        } else {
            prev->next = NULL;
            printf("%d\n", curr->data);
        }
    }
}

void pr2(Node first) {
    first = reverse(first);
    <print list code here>
    first = reverse(first);
}

void pr3(Node first) {
    Stack s = newStack();
    Node curr = first;
    while (curr != NULL) {
        pushStack(s, curr->data);
        curr = curr->next;
    }
    while (!isEmpty(s)) {
        int i = popStack(s);
        printf("%d\n", i);
    }
}
