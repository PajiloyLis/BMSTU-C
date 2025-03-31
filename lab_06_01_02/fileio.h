#ifndef _FILE_H_
#define _FILE_H_

#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include <string.h>
#include <ctype.h>
#include "lab_06_01_02.h"

#define FILE_READING_ERROR 1
#define FILE_VALUE_ERROR 2
#define FILE_OPEN_ERROR 3
#define NEGATIVE_NUMBERS_ERROR 4
#define ARRAY_SIZE_ERROR 5

int input(object_t *array, size_t *n, char *file_name);

void output(object_t *array, size_t n);

void output_by_pointers(object_t *array[], size_t n);

#endif
