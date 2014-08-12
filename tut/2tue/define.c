#define A 2

#define add(x) (x+1)
#define forloop(x) for(i=0;i<x;i++)
#define 

#include <stdio.h>
#ifndef STDIO_H

#endif

#ifdef A
#define B 2
#else
#define B 4
#endif

forloop(y) {

}




// Item.h - String Items for use in GADTs
// Written by John Shepherd, March 2013

#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>
#include <string.h>

typedef struct _node {
        int data;
        struct _node *next;
} node;
typedef node *Item;

#define ItemCopy(s) (Item n = malloc(sizeof(*n)); n->data = s; n->next = s->next;)
#define ItemEQ(s,t) (s->data == t->data;)
#define ItemLT(s,t) (s->data<t->data)
#define ItemLE(s,t) (s->data<=t->data)
#define ItemGT(s,t) (s->data>t->data)
#define ItemGE(s,t) (s->data>=t->data)
#define ItemScan(s) (s->data);
#define ItemShow(f,s) (fprintf(f,"[%d]->",s->data))

#endif

float a = 0.1;
//float b = 0.00000000000000000000000000000000000000000000000000000000000000000000000001;
float b = 0.0005;
b += 0.0995;
if (abs(a - b) < 0.0001) {

}
typedef struct _node {
        Item data;
        struct _node *next;
}
