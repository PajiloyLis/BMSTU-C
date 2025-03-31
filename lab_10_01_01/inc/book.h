#ifndef BOOK_H
#define BOOK_H

#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "vector.h"

#define YEAR_READING_ERROR 40
#define EMPTY_STRING_ERROR 41
#define STRING_READING_ERROR 42
#define ZERO_YEAR_ERROR 43
#define BOOK_READING_ERROR 44
#define FILE_OPEN_ERROR 45
#define FILE_READING_ERROR 46
#define FILE_EMPTY_ERROR 47

typedef struct
{
    char *title;
    char *author;
    ssize_t title_len, author_len;
    short year;
} book_t;

int book_compare(const void *a, const void *b);

int books_read_from_file(vector_t *books, char *file_name);

void book_print(void *book);

#endif