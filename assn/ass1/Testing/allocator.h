//
//  COMP1927 Assignment 1 - sal: A Memory Suballocator
//  allocator.h ... interface
//
//  Created by Liam O'Connor on 18/07/12.
//  Modified by John Shepherd in August 2014
//  Copyright (c) 2012-2014 UNSW. All rights reserved.
//

#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stdlib.h>

// Input: size - number of bytes to make available to the suballocator
// Output: none              
// Precondition: Size is a power of two.
// Postcondition: `size` bytes are now available to the suballocator
// 
// (If the suballocator is already initialised, this function does nothing, even 
// if it was initialised with different size)

void sal_init(u_int32_t size);

// Input: n - number of bytes requested
// Output: p - a pointer, or NULL
// Precondition: n is < size of memory available to the suballocator
// Postcondition: If a region of size n or greater cannot be found, p = NULL 
//                Else, p points to a location immediately after a header block
//                      for a newly-allocated region of some size >= 
//                      n + header size. 

void *sal_malloc(u_int32_t n);

// Input: object, a pointer.
// Output: none
// Precondition: object points to a location immediately after a header block
//               within the suballocator's memory.
// Postcondition: The region pointed to by object can be re-allocated by 
//                sal_malloc

void sal_free(void *object);

// Stop the allocator, so that it can be init'ed again:
// Precondition: suballocator memory was once allocated by sal_init()
// Postcondition: allocator is unusable until sal_int() executed again

void sal_end(void);

// Precondition: allocator has been sal_init()'d
// Postcondition: allocator stats displayed on stdout

void sal_stats(void);

#endif
