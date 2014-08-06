// Interface to sorted list of integers ADT

typedef struct SortedListRep *SortedList;

typedef struct SortedListNode {
        int data;
        Node next;
} *Node;

struct SortedListRep {
        Node first;
        int size;
};

// create a new empty list
SortedList newList() {
        SortedList l = malloc(sizeof(*l));
        l->first = NULL;
        l->size = 0;
        return l;
}

// insert a value into the list
void ListInsert(SortedList l, int num) {
    Node curr = l->first, prev = NULL;
    while (curr != NULL && curr->data < num) {
        prev = curr;
        curr = curr->next;
    }
    Node newN = createNode(num);
    if (prev != NULL) {
        prev->next = newN;
    } else {
        l->first = newN;
    }
    newN->next = curr;
    l->size++;
}

// length of list
int ListLength(SortedList l) {
    /*int num = 0;
    Node curr;
    for (curr = l->first; curr != NULL; curr = curr->next) {
        num++;
    }
    return num;*/
    return l->size;
}

// number of distinct values
int ListDistinct(SortedList);

// display a sorted list as "(x,y,z,...)"
void showList(SortedList);

