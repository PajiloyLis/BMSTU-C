#ifndef ARRLIB_H
#define ARRLIB_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define NULL_FILTER_POINTER_ERROR 31
#define MEMORY_ALLOC_ERROR 32
#define ARRAY_POINTERS_ERROR 33
#define EMPTY_ARRAY_ERROR 34
#define POINTERS_ERROR 21

#define FILE_READING_ERROR 41
#define FILE_EMPTY_ERROR 42
#define FILE_OPEN_ERROR 43
#define ARRAY_POINTER_ERROR 44
#define COUNTER_POINTER_ERROR 45

typedef int (*cmp)(const void *, const void *);

void mysort(void *p_begin, size_t n, size_t size, cmp cmp);

int compare_int(const void *a, const void *b);

int key(const int *pb_src, const int *pe_src, int *pb_dst, size_t *new_n);

int count_records_cnt(char *file_name, size_t *n);

int read_numbers(char *file_name, int *p_b, int *p_e);

int output(char *file_name, int *p_b, int *p_e);

#endif
