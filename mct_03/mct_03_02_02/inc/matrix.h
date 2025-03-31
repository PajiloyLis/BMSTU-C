#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <stdio.h>

#define SIZE_INPUT_ERROR 10
#define ALLOCATION_ERRROR 11
#define ELEM_INPUT_ERROR 12

typedef struct matrix_t matrix_t;

struct matrix_t
{
    long long **strs;
    size_t n, m;
};

void free_matrix(matrix_t *matrix);

int input_sizes(size_t *n, size_t *m);

int allocate_matrix(matrix_t *matrix, size_t n, size_t m);

#endif