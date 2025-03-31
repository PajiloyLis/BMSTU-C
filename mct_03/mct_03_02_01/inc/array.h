#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <stdio.h>

#define INPUT_SIZE_ERROR 10
#define ELEM_INPUT_ERROR 11
#define NULL_POINTER_ERROR 12
#define MEMORY_ALLOC_ERROR 13

int input_size(size_t *n);

int input_array(long long *array, size_t n);

int allocate_array(long long **array, size_t n);

int delete_elems(long long *array, size_t *n);

void print_array(long long *array, size_t n);

#endif