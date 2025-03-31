#ifndef MATRIX_T_H
#define MATRIX_T_H

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MATRIX_SIZE_ERROR 99
#define NULL_POINTER_ERROR 98

typedef struct
{
    size_t n, m;
    bool is_allocated;
    long long **data;
} matrix_t;

#endif