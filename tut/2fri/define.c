#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>
#include <string.h>

typedef struct _node *Node;
struct _node {
    int data;
    Node next;
};
typedef Node Item;

#define ItemCopy(s) (s)
#define ItemEQ(s,t) (abs(s-t) < 0.001)
#define ItemLT(s,t) (s<t)
#define ItemLE(s,t) (s<=t)
#define ItemGT(s,t) (s>t)
#define ItemGE(s,t) (s>=t)
#define ItemScan(s) (s)
#define ItemShow(f,s) fprintf((f),"%f",(s))

#endif

#define A 5
#define add(x,y) (x+y)
#define foreach(x) for(i = 0; i < x; i++)
int a = add(4,5);

int i;
foreach(5) {

}


float x = 0.000001;
float b = 0.00000001;
   b += 0.00000099;

if (x == b) {
    printf("balloon\n");
}

typedef struct _node {
    Item a;
    Node *next;
} node;
