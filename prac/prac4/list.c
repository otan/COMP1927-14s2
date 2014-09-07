/* 
 * Test files by Oliver Tan (otan@cse.unsw.edu.au)
 *
 * Back to basics
 * Insert the node n in order in the doubly linked list.
 *
 * Compile: gcc -Wall -Werror -O -o testList testList.c list.c
 * Run: ./testList
*     
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* do you want the program to work? if so, don't change this */
Node createNode(int i) {
    Node n = malloc(sizeof(struct _node));
    n->next = NULL;
    n->prev = NULL;
    n->data = i;
    return n;
}

/* ... or this */
List createList(void) {
    List l = malloc(sizeof(*l));
    l->first = NULL;
    l->last = NULL;
    l->size = 0;
    return l;
}

/* but do change this! */
void insertInOrder(List l, Node n) {

}
