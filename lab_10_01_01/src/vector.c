#include "vector.h"

int vector_allocate(vector_t *vector, size_t size, size_t n)
{
    if (!vector || !size || !n)
    {
        return VECTOR_ALLOCATION_ERROR;
    }
    void *buf = calloc(n, size);
    if (!buf)
        return VECTOR_ALLOCATION_ERROR;
    vector->array = buf;
    vector->elem_size = size;
    vector->elems_cnt = vector->allocated_cnt = n;
    vector->is_alocated = true;
    return EXIT_SUCCESS;
}

int vector_reallocate(vector_t *vector)
{
    if (!vector)
        return VECTOR_REALLOCATION_ERROR;
    void *buf = realloc(vector->array, vector->elem_size * vector->allocated_cnt * 2);
    if (!buf)
        return VECTOR_REALLOCATION_ERROR;
    vector->array = buf;
    vector->allocated_cnt *= 2;
    return EXIT_SUCCESS;
}

void vector_free(vector_t *vector)
{
    free(vector->array);
    vector->allocated_cnt = vector->elem_size = vector->elems_cnt = 0;
    vector->is_alocated = false;
}