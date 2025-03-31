#ifndef ARGS_H
#define ARGS_H

#include "book.h"
#include <stdlib.h>
#include <errno.h>
#include <limits.h>


#define ARGS_NULL_POINTER_ERROR 20
#define ARGS_COUNT_ERROR 21
#define YEAR_CONVERTING_ERROR 22
#define OPERATION_KEY_ERROR 23

#define FIND_ARGS_COUNT 6
#define INSERT_ARGS_COUNT 9
#define UNIQUE_ARGS_COUNT 3
#define SORT_ARGS_COUNT 3

#define INPUT_FILE_NUMBER 1
#define MODE_NUMBER 2
#define AUTHOR_NUMBER 4
#define TITLE_NUMBER 3
#define YEAR_NUMBER 5
#define TITLE_2_NUMBER 6
#define AUTHOR_2_NUMBER 7
#define YEAR_2_NUMBER 8
#define INSERT_OUTPUT_FILE_NUMBER 9
#define ANOTHER_OUTPUT_FILE_NUMBER 3

#define BASE 10

#define FIND 'f'
#define INSERT 'i'
#define UNIQUE 'u'
#define SORT 's'

int args_hadler(int argc, char **argv, char **input_file, char *mode, book_t *buf_1, book_t *buf_2);

#endif