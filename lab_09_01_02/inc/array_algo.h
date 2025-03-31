#ifndef _FILE_PROC_H_
#define _FILE_PROC_H_

#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define NULL_POINTER_ERROR 11
#define MEMORY_ALLOCATION_ERROR 12
#define ARRAY_SIZE_ERROR 13

#define EPS 1e-9

#define ALL "ALL"

int find(object_t *array, object_t **ans_array[], size_t *ans_n, size_t n, size_t *total_ans_n, char *prefix);

int insert_sort(object_t *array, size_t n);

int array_reallocate(object_t **array, size_t *total_n);

int pointers_array_reallocate(object_t ***array, size_t *total_n);

void array_free(object_t *array, size_t n);

#endif
