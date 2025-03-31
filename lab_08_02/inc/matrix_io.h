#ifndef MATRIX_INPUT_H
#define MATRIX_INPUT_H

#include <stdlib.h>
#include <stdio.h>
#include "matrix_t.h"

#define READING_NUMBER_ERROR 21
#define EXCESS_SYMBOL_ERROR 22

int input_matrix(matrix_t *matrix);

void output_matrix(matrix_t *matrix);

#endif