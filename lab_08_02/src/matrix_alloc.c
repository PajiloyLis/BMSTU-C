#include "matrix_alloc.h"

int allocate_matrix(matrix_t *matrix, size_t n, size_t m)
{
    if (!matrix)
        return NULL_POINTER_ERROR;
    if (n == 0 || m == 0)
        return MATRIX_SIZE_ERROR;
    matrix->n = n;
    matrix->m = m;
    long long **buf, *buf_str;
    buf = calloc(matrix->n, sizeof(long long *));
    if (!buf)
    {
        matrix->is_allocated = false;
        return POINTERS_ARRAY_ALLOCATE_ERROR;
    }
    matrix->data = buf;
    for (size_t i = 0; i < matrix->n; ++i)
    {
        buf_str = malloc(matrix->m * sizeof(long long));
        if (!buf_str)
        {
            matrix->is_allocated = false;
            free_matrix(matrix);
            return MATRIX_STRING_ALLOCATE_ERROR;
        }
        matrix->data[i] = buf_str;
    }
    matrix->is_allocated = true;
    return EXIT_SUCCESS;
}

int reallocate_matrix(matrix_t *matrix, size_t n)
{
    if (!matrix)
        return NULL_POINTER_ERROR;
    if (n == 0)
        return MATRIX_SIZE_ERROR;
    long long *buf_str, **buf;
    buf = realloc(matrix->data, n * sizeof(long long *));
    if (!buf)
    {
        free_matrix(matrix);
        matrix->is_allocated = false;
        return POINTERS_ARRAY_REALLOCATE_ERROR;
    }
    matrix->data = buf;
    for (size_t i = matrix->n; i < n; ++i)
        matrix->data[i] = NULL;
    bool skip = false;
    for (size_t i = 0; i < n && !skip; ++i)
    {
        buf_str = realloc(matrix->data[i], n * sizeof(long long));
        if (!buf_str)
            skip = true;
        else
            matrix->data[i] = buf_str;
    }
    if (skip)
    {
        matrix->n = n;
        free_matrix(matrix);
        matrix->is_allocated = false;
        return MATRIX_STRING_REALLOCATE_ERROR;
    }
    matrix->is_allocated = true;
    return EXIT_SUCCESS;
}

void free_matrix(matrix_t *matrix)
{
    for (size_t i = 0; i < matrix->n; ++i)
    {
        free(matrix->data[i]);
    }
    free(matrix->data);
    matrix->n = matrix->m = 0;
}
