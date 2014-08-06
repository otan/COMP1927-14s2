// Interface to sorted list of integers ADT

typedef struct SortedListRep *SortedList;

// create a new empty list
SortedList newList();

// insert a value into the list
void ListInsert(SortedList,int);

// length of list
int ListLength(SortedList);

// number of distinct values
int ListDistinct(SortedList);

// display a sorted list as "(x,y,z,...)"
void showList(SortedList);

