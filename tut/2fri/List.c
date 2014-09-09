// List.c - Implementation of doubly-linked list GADT
// Written by John Shepherd, March 2013
// Last modified, August 2014

#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "Item.h"
#include "List.h"

// data structures representing List

typedef struct ListNode {
	Item value;  // value of this list item
	struct ListNode *prev;
	             // pointer previous node in list
	struct ListNode *next;
	             // pointer to next node in list
} ListNode;

typedef struct ListRep {
	int  nitems;      // count of Items in list
	ListNode *first; // first node in list
	ListNode *last;  // last node in list
	ListNode *curr;  // current node in list
} ListRep;

// create a new ListNode (private function)
static ListNode *newListNode(Item it)
{
	ListNode *new;
	new = malloc(sizeof(ListNode));
	assert(new != NULL);
	new->value = ItemCopy(it);
	new->prev = new->next = NULL;
	return new;
}

// create a new empty List
List newList()
{
	struct ListRep *L;

	L = malloc(sizeof (struct ListRep));
	assert (L != NULL);
	L->nitems = 0;
	L->first = NULL;
	L->last = NULL;
	L->curr = NULL;
	return L;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

void freeListNodes(struct ListNode *n) {
    if (n == NULL) {
        return;
    }
    freeListNodes(n->next);
    free(n);
}

// free up all space associated with list
void freeList(List L)
{
	assert(L != NULL);
        freeListNodes(L->first);
/*	ListNode *curr, *prev;
	curr = L->first;
	while (curr != NULL) {
		prev = curr;
		curr = curr->next;
		free(prev);
	}*/
	free(L);
}

// trim off \n from strings (private function)
// this is needed for getList() because of fgets()
// alternatively, we could use the evil gets() function
static char *trim(char *s)
{
	int end = strlen(s)-1;
	if (s[end] == '\n') s[end] = '\0';
	return s;
}

// create an List by reading items from a file
// assume that the file is open for reading
// assume one item per line, line < 999 chars
List getList(FILE *in)
{
	List L;
	ListNode *new;
	char line[1000];

	L = newList();
	while (fgets(line,1000,in) != NULL) {
		Item value = ItemScan(trim(line));
		new = newListNode(value);
		if (L->last == NULL) {
			L->first = L->last = new;
		}
		else {
			L->last->next = new;
			new->prev = L->last;
			L->last = new;
		}
		L->nitems++;
	}	
	L->curr = L->first;
	return L;
}

// display items from a List, one per line
void showList(FILE *out, List L)
{
	assert(out != NULL); assert(L != NULL);
	ListNode *curr;
	for (curr = L->first; curr != NULL; curr = curr->next) {
		ItemShow(out,curr->value); fprintf(out,"\n");
	}
}

// check sanity of a List (for testing)
int validList(List L)
{
	if (L == NULL) {
		fprintf(stderr,"List is null\n");
		return 0;
	}
	if (L->first == NULL) {
		// list is empty; curr and last should be null
		if (L->last != NULL || L->curr != NULL) {
			fprintf(stderr,"Non-null pointers in empty list\n");
			return 0;
		}
	}
	else {
		// list is not empty; curr and last should be non-null
		if (L->last == NULL || L->curr == NULL) {
			fprintf(stderr,"Null pointers in non-empty list\n");
			return 0;
		}
	}
	int count;
	ListNode *curr;
	// check scanning forward through list
	count = 0;
	for (curr = L->first; curr != NULL; curr = curr->next) {
		if (curr->prev != NULL && curr->prev->next != curr) {
			fprintf(stderr, "Invalid forward link into node (");
			ItemShow(stderr,curr->value); fprintf(stderr,")\n");
			return 0;
		}
		if (curr->next != NULL && curr->next->prev != curr) {
			fprintf(stderr, "Invalid backward link into node (");
			ItemShow(stderr,curr->value); fprintf(stderr,")\n");
			return 0;
		}
		count++;
	}
	if (count != L->nitems) {
		fprintf(stderr, "Forward count mismatch; counted=%d, nitems=%d\n",
		        count, L->nitems);
		return 0;
	}
	// check scanning backward through list
	count = 0;
	for (curr = L->last; curr != NULL; curr = curr->prev) {
		count++;
	}
	if (count != L->nitems) {
		fprintf(stderr, "Backward count mismatch; counted=%d, nitems=%d\n",
		        count, L->nitems);
		return 0;
	}
	// nothing went wrong => must be ok
	return 1;
}

// return item at current position
Item ListCurrent(List L)
{
	assert(L != NULL); assert(L->curr != NULL);
	return L->curr->value;
}

// move current position (+ve forward, -ve backward)
// return 1 if reach end of list during move
// if current is currently null, return 1
int ListMove(List L, int n)
{
	assert(L != NULL);
	if (L->curr == NULL)
		return 1;
	else if (n > 0) {
		while (n > 0 && L->curr->next != NULL) {
			L->curr = L->curr->next;
			n--;
		}
	}
	else if (n < 0) {
		while (n < 0 && L->curr->prev != NULL) {
			L->curr = L->curr->prev;
			n++;
		}
	}
	return (L->curr == L->first || L->curr == L->last);
}

// move to specified position in list
// i'th node, assuming first node has i==1
int ListMoveTo(List L, int i)
{
	assert(L != NULL); assert(i > 0);
	L->curr = L->first;
	return ListMove(L, i-1);
}

// insert an item before current item
// new item becomes current item
void ListBefore(List L, Item it)
{
	assert(L != NULL); 
	// COMPLETE THIS FUNCTION
}

// insert an item after current item
// new item becomes current item
void ListAfter(List L, Item it)
{
	assert(L != NULL); 
	// COMPLETE THIS FUNCTION
}

// delete current item
// new item becomes item following current
// if current was last, current becomes new last
// if current was only item, current becomes null
void ListDelete(List L)
{
	assert (L != NULL);
	// COMPLETE THIS FUNCTION
}

// return number of elements in a list
int ListLength(List L)
{
	return (L->nitems);
}

// is the list empty?
int ListIsEmpty(List L)
{
	return (L->nitems == 0);
}

