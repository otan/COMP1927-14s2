typedef struct _node *Node;

typedef struct _node {
    int data;
    Node next;
} node;

Node createSequentialList(int n);
