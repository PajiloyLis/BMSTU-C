#ifndef _FILE_PROC_H_
#define _FILE_PROC_H_

#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define NULL_POINTER_ERROR 11

#define EPS 1e-9

#define ALL "ALL"

void find(object_t *array, object_t *ans_array[], size_t *ans_n, size_t n, char *prefix);

int insert_sort(object_t *array, size_t n);

#endif
