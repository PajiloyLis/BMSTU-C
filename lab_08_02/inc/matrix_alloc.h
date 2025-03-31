#ifndef MATRIX_ALLOC_H
#define MATRIX_ALLOC_H

#include <stdlib.h>
#include "matrix_t.h"
#include <stdbool.h>

#define POINTERS_ARRAY_ALLOCATE_ERROR 32
#define MATRIX_STRING_ALLOCATE_ERROR 31
#define POINTERS_ARRAY_REALLOCATE_ERROR 33
#define MATRIX_STRING_REALLOCATE_ERROR 34

int allocate_matrix(matrix_t *matrix, size_t n, size_t m);

void free_matrix(matrix_t *matrix);

int reallocate_matrix(matrix_t *matrix, size_t n);

#endif
