    //
    // COMP1927 Assignment 1 - Memory Suballocator
    // allocator.c ... implementation
    //
    // Created by Liam O'Connor on 18/07/12.
    // Modified by John Shepherd in August 2014
    // Copyright (c) 2012-2014 UNSW. All rights reserved.
    // Modified by Fraser Hemphill in August 2014 as an Assign for COMP1927
     
    #include "allocator.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <assert.h>
     
    #define HEADER_SIZE sizeof(struct free_list_header)
    #define MAGIC_FREE 0xDEADBEEF
    #define MAGIC_ALLOC 0xBEEFDEAD
     
    typedef unsigned char byte;
    typedef u_int32_t vlink_t;
    typedef u_int32_t vsize_t;
    typedef u_int32_t vaddr_t;
     
    typedef struct free_list_header {
    u_int32_t magic; // ought to contain MAGIC_FREE
    vsize_t size; // # bytes in this block (including header)
    vlink_t next; // memory[] index of next free block
    vlink_t prev; // memory[] index of previous free block
    } free_header_t;
     
    // Global data
     
    static byte *memory = NULL; // pointer to start of suballocator memory
    static vaddr_t free_list_ptr; // index in memory[] of first block in free list
    static vsize_t memory_size; // number of bytes malloc'd in memory[]
     
    u_int32_t checkSize(u_int32_t index); //check size of region
    u_int32_t scanForBest(u_int32_t index,u_int32_t size);
    u_int32_t halveRegion(u_int32_t index);
    long scanForLow(u_int32_t index);
    long sal_merge(long index);
    void removeAlloc(u_int32_t index);
     
     
    void sal_init(u_int32_t size)
    {
    long power;
    for (power = 2; power < (long) size; power=power*2);
    if ((long) size!= power){ //check size is a power of 2, if not
    size = power; //set as next largest power of 2
    }
    memory = malloc(size); //malloc the memory
    //give error if not enough memory
    if (memory==NULL){
    fprintf(stderr, "sal_init: insufficient memory");
    abort();
    }
    memory_size = size; //setting up variables
    free_list_ptr = 0;
    free_header_t *header = (void *) (memory);
    header->magic = MAGIC_FREE; //define block as free memory
    header->size = size;
    header->next = 0; //link node to itself
    header->prev = 0;
    }
     
    void *sal_malloc(u_int32_t n)
    {
    //case for trying to assign 0 to sal_malloc
    if (!n){
    fprintf(stderr,"Attempting to assign 0 bytes: Illegal\n");
    return NULL;
    }
    free_header_t *curr = (free_header_t *) (memory + free_list_ptr);
    int bestFit = -1;
    //scan for index of best region (smallest that fits)
    bestFit = scanForBest(free_list_ptr,n+HEADER_SIZE);
    //return NULL if no good region exists, and give error message
    if (bestFit==-1) {
    fprintf(stderr,"Not enough memory for size %d\n",n+HEADER_SIZE);
    return NULL;
    }
    //if only one region in list which is big enough to write to
    //but not big enough to halve, then return NULL
    if (bestFit==free_list_ptr && curr->next == free_list_ptr
    && checkSize(bestFit) >= n+HEADER_SIZE
    && checkSize(bestFit)/2 <= n+HEADER_SIZE)
    {
    fprintf(stderr,"Attempting to write last free block in list\n");
    return NULL;
    }
    //try to halve, if possible
    while (checkSize(bestFit)/2 >= n+HEADER_SIZE) {
    bestFit = halveRegion(bestFit);
    }
    //update ptr if ptr is allocated
    if (bestFit==free_list_ptr){
    free_list_ptr = curr->next;
    }
    //reassigned to alloc'd and relink headers surrounding it
    removeAlloc(bestFit);
    //return new avaliable memory to user
    return ((void *)(bestFit + HEADER_SIZE));
    }
     
    void removeAlloc(u_int32_t index) {
    free_header_t *curr = (free_header_t *)(memory + index);
    curr->magic = MAGIC_ALLOC; //define as alloc'd
    //next 6 lines relink nodes around alloc'd node
    index = curr->next;
    curr = (free_header_t *)(memory + curr->prev);
    curr->next = index;
    index = (long) curr - (long) memory;
    curr = (free_header_t *)(memory + curr->next);
    curr->prev = index;
    }
     
    u_int32_t halveRegion(u_int32_t index) {
    free_header_t *curr = (free_header_t *)(memory + index);
    //insert new header halfway through current node
    free_header_t *newNode=(free_header_t *)(memory+index+curr->size/2);
    newNode->magic = MAGIC_FREE; //define as free memory
    newNode->next = curr->next; //new header's next as currents next
    //if only one region in list, change free_list_ptr's prev accordingly
    if (curr->prev == free_list_ptr
    && curr == (free_header_t *)(memory + free_list_ptr))
    {
    curr->prev = index + curr->size/2;
    }
    //next 6 lines changes sizes/links new node with rest of list
    newNode->prev = (int) curr - (int) memory;
    newNode->size = curr->size/2;
    curr->next = index + (curr->size/2);
    curr->size = curr->size/2;
    curr = (free_header_t *)(memory + newNode->next);
    curr->prev = index + newNode->size;
    return index;
    }
     
    u_int32_t checkSize(u_int32_t index){
    //simply returns size of a given node
    free_header_t *tmp = (free_header_t *)(memory + index);
    return tmp->size;
    }
     
    u_int32_t scanForBest(u_int32_t index,u_int32_t size){
    free_header_t *tmp = (free_header_t *)(memory + index);
    free_header_t *perf = (free_header_t *)(memory + free_list_ptr);
    int perfect=-1,flag=0; //perfect remains -1 if no good region exists
    //if only one region, perfect region = the only region
    if (tmp->next == index){
    if (tmp->size > size){
    perfect = (long) tmp - (long) memory;
    }
    } else {
    //loop through list, checking for the best region
    while ((long) tmp - (long) memory!=index || !flag){
    //if better region found, replace perfect,
    //or perf==-1 for case where no region yet
    if (tmp->size >= size &&
    (perf->size > tmp->size || perfect==-1)){
    perfect = (long) tmp - (long) memory;
    perf = (free_header_t *)(memory + perfect);
    }
    //test integrity of list
    if (tmp->magic!=MAGIC_FREE){
    fprintf(stderr, "Memory corruption");
    abort();
    }
    flag = 1; //at least one loop
    tmp = (free_header_t *)(memory + tmp->next); //increment list
    }
    }
    return perfect; //return best region for size
    }
     
    void sal_free(void *object)
    {
    long index = (long) object - HEADER_SIZE;
    long prevInd=-1;
    long merged=0; //unchanged if no merging occurs
    free_header_t *curr = (free_header_t *)(memory + index);
    if (curr->magic==MAGIC_ALLOC){
    prevInd = scanForLow(index); //scan for lowest
    curr->magic = MAGIC_FREE;
    //if merging node is 1st in list, link accordingly (next 7 lines)
    if (prevInd==-1){
    free_header_t *nex = (free_header_t *)(memory + free_list_ptr);
    curr->prev = nex->prev;
    nex->prev = index;
    curr->next = (long) nex - (long) memory;
    nex = (free_header_t *)(memory + curr->prev);
    nex->next = index;
    free_list_ptr = index;
    } else {
    //if not 1st, link accordingly (next 6 lines);
    curr->prev = prevInd;
    free_header_t *before = (free_header_t *) (memory + prevInd);
    curr->next = before->next;
    before->next = index;
    before = (free_header_t *) (memory + curr->next);
    before->prev = index;
    }
    while (merged!=-1){ //while a merging occured
    merged = sal_merge(index); //attempt to merge index header
    if (merged!=-1 && merged!=1) {
    index = merged; //if merged below, change index
    }
    }
    //if not alloc'd memory, send error message
    } else {
    fprintf(stderr, "Attempt to free non-allocated memory");
    abort();
    }
    }
     
    long sal_merge (long index){
    int merged = -1; //if unchanged, no merging occured
    free_header_t *curr = (free_header_t *)(memory + index);
    free_header_t *merge = (free_header_t *)(memory + curr->next);
    long size = curr->next - index;
    long power;
    if (curr->size==merge->size &&
    (long)merge - (long) memory == index + curr->size){
    //next line checks if space before nodes about to be merged
    //to see if a mutiple of 2 worth of curr->size is available
    //this prevents fragrementation
    long iterations = (index + curr->size*2)/(curr->size) % 2;
    for (power = 2; power < size; power=power*2); //check position
    if (power==size && !iterations){ //is a power of 2
    curr->next = merge->next; //relink headers
    merge = (free_header_t *) (memory + merge->next);
    merge->prev = index;
    curr->size = 2*curr->size; //correct size of merged header
    merged=1; //merging occured flag
    }
    }
    if (free_list_ptr!=index) {
    merge = (free_header_t *) (memory + curr->prev);
    //next line checks fragramentation as above
    long iterations = (((long)merge-(long)memory)+
    (curr->size*2))/(curr->size) % 2;
    if (merge->size == curr->size &&
    (long)merge - (long) memory == index - curr->size &&
    !iterations)
    {
    size = index - curr->prev; //check position
    for (power = 2; power < size; power=power*2);//via power of 2
    if (power==size){
    merge->next = curr->next;
    merge->size = 2 * merge->size;
    curr = (free_header_t *) (memory + curr->next);
    curr->prev = (long) merge - (long) memory;
    merged = (long) merge - (long) memory; //change index
    } //to suit new header
    }
    }
    return merged;
    }
     
    long scanForLow(u_int32_t index){
    long low = -1,flag=0;
    free_header_t *curr = (free_header_t *)(memory + free_list_ptr);
    while ((long) curr - (long) memory != free_list_ptr || !flag){
    if ((long) curr - (long) memory < index) {
    low = (long) curr - (long) memory; //if lower index is linkable
    } //put as new low
    flag = 1;
    curr = (free_header_t *)(memory + curr->next);
    }
    return low; //returns -1 if node being free'd is the earliest
    } //node in the list (free_list_ptr)
     
     
    void sal_end(void)
    {
    free(memory); //free's allocated memory
    }
     
    void sal_stats2(void)
    {
    // Optional, but useful
    printf("sal_stats\n");
    free_header_t *tmp = (free_header_t *)(memory + free_list_ptr);
    //print visual representation of memory, with stats next to each node
    printf("-----h---- %d next:%d prev: %d size:%d\n",
    free_list_ptr,tmp->next,tmp->prev,tmp->size);
    tmp = (free_header_t *)(memory + tmp->next);
    while (tmp!=(free_header_t *)(memory + free_list_ptr)){
    printf("---------- %d next:%d prev: %d size:%d\n",
    (int) tmp - (int) memory,tmp->next,tmp->prev,tmp->size);
    tmp = (free_header_t *)(memory + tmp->next);
    }
    // we "use" the global variables here
    // just to keep the compiler quiet
    memory = memory;
    free_list_ptr = free_list_ptr;
    memory_size = memory_size;
    }// attempt to display info on memory regions
// 
// typedef struct free_list_header {
//    u_int32_t magic;           // ought to contain MAGIC_FREE
//    vsize_t size;              // # bytes in this block (including header)
//    vlink_t next;              // memory[] index of next free block
//    vlink_t prev;              // memory[] index of previous free block
// } free_header_t;
// 
// // Global data
// static byte *memory = NULL;   // pointer to start of suballocator memory
// static vaddr_t free_list_ptr; // index in memory[] of first block in free list
// static vsize_t memory_size;   // number of bytes malloc'd in memory[]

void sal_stats()
{
	vaddr_t cur;  
	// global stats
	//printf("Mem: %d@%p, ", memory_size, memory);
	// navigate free list
	cur = free_list_ptr;
	int i = 0;
	printf("Free: ");
	do {
		// should always be at least one
		free_header_t *curh = (free_header_t *)(memory + cur);
		switch (curh->magic) {
		case MAGIC_FREE:
			printf("%d@%d ",curh->size,cur);
			break;
		case MAGIC_ALLOC:
			printf("A%d@%d ",curh->size,cur);
			break;
		default:
			printf("*** Memory corruption @ mem[%d]\n",cur);
			break;
		}
		cur = curh->next;
		if (++i > 30) { printf("LOOP"); break; }
	} while (cur != free_list_ptr);
	printf("\n");
}

int off(void *ptr) { return ((byte *)ptr) - memory - HEADER_SIZE; }
void *mem() { return (void *)memory; }
int msz() { return memory_size; }
