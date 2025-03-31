#ifndef FILEIO_H
#define FILEIO_H

#include <stdio.h>
#include <stdlib.h>

#define FILE_READING_ERROR 41
#define FILE_EMPTY_ERROR 42
#define FILE_OPEN_ERROR 43
#define ARRAY_POINTER_ERROR 44
#define COUNTER_POINTER_ERROR 45

int count_records_cnt(char *file_name, size_t *n);

int read_numbers(char *file_name, int *p_b, int *p_e);

int output(char *file_name, int *p_b, int *p_e);

#endif
