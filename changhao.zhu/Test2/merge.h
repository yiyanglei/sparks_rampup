#ifndef MERGE
#define MERGE

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define NUM1_SIZE   (6u)
#define NUM2_SIZE   (3u)
#define MAX_ARRAY_SIZE (NUM1_SIZE+NUM2_SIZE)

__uint32_t merSort();
__uint32_t copyHandle();
void merge(__uint32_t * nums1, __uint32_t  m, __uint32_t * nums2, __uint32_t n);

#endif