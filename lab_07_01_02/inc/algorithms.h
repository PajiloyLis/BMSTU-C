#ifndef FILTER_H
#define FILTER_H

#include <stdlib.h>
#include <string.h>

#define NULL_FILTER_POINTER_ERROR 31
#define MEMORY_ALLOC_ERROR 32
#define ARRAY_POINTERS_ERROR 33
#define EMPTY_ARRAY_ERROR 34
#define POINTERS_ERROR 21

typedef int (*cmp)(const void *, const void *);

void mysort(void *p_begin, size_t n, size_t size, cmp cmp);

int compare_int(const void *a, const void *b);

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif
