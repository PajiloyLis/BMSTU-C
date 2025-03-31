#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdbool.h>

#define VECTOR_DEFAULT_SIZE 20

#define VECTOR_ALLOCATION_ERROR 30
#define VECTOR_REALLOCATION_ERROR 31

typedef struct
{
    void *array;
    size_t elem_size;
    size_t elems_cnt;
    size_t allocated_cnt;
    bool is_alocated;
} vector_t;

int vector_allocate(vector_t *vector, size_t size, size_t n);

int vector_reallocate(vector_t *vector);

void vector_free(vector_t *vector);

#endif