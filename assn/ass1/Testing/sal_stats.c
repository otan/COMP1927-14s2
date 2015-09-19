// attempt to display info on memory regions
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
