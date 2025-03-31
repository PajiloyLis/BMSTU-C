#ifndef MATRIX_ALGO_H
#define MATRIX_ALGO_H

#include "matrix_t.h"
#include <stdbool.h>
#include <math.h>
#include "matrix_alloc.h"

#define NEGATIVE_POW_ERROR 50

int calc_expanded_size(matrix_t *matr_1, matrix_t *matr_2, size_t *n);

int make_quadratic(matrix_t *matrix);

int make_equal_size(matrix_t *matrix, size_t n);

int matrix_multiply(matrix_t *matr_1, matrix_t *matr_2, matrix_t *ans);

int matrix_pow(matrix_t *matrix, long long n, matrix_t *ans);

#endif