/* 
 * THIS WAS A COMP1927 14x1 prac exam question! 
 * And has been seen in 1917 prac exam questions
 * so you should be able to do it!
 * Test files by Oliver Tan (otan@cse.unsw.edu.au)
 *
 * Given two singly linked lists in order, merge them in order
 * e.g.: 
 * l1: [1]->[4]->[8]->[X]
 * l2: [2]->[5]->[8]->[10]->[X]
 * becomes
 * l1: [1]->[2]->[4]->[5]->[8]->[8]->[10]->[X]
 * l2: [X] (with size 0)
 * note: i do not care about the order of which [8] 
 * comes first from either list.
 *
 * This involves completing the merge prototype below.
 * NOTE: l1 & l2 will never be NULL, but l1->first and l2->first may.
 *
 * Hint: RECURSION makes it EASY.
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
    n->data = i;
    return n;
}

/* ... or this */
List createList(void) {
    List l = malloc(sizeof(*l));
    l->first = NULL;
    l->size = 0;
    return l;
}

/* but do change this! */
void mergeNodes(Node n1, Node n2) {
    if (n1->data < n2->data) {
        // node from first is smalller
        n1->next = mergeNodes(n1->next, n2);
        return n1;
    } else {
        n2->next = mergeNodes(n1, n2->next);
        return n2;
    }
}

void merge(List l1, List l2) {
    l1->first = mergeNodes(l1->first, l2->first);
    l1->size += l2->size;

    l2->first = NULL;
    l2->size = 0;
}


