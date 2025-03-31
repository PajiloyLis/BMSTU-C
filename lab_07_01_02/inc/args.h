#ifndef ARGS_H
#define ARGS_H

#include <stdlib.h>
#include <string.h>

#define AGRS_CNT_MIN 3
#define ARGS_CNT_MAX 4

#define FILE_IN_NUM 1
#define FILE_OUT_NUM 2
#define FILTER_ARG_NUM 3

#define ARGS_COUNT_ERROR 51
#define ARG_LETTER_ERROR 52
#define ARGS_POINTER_ERROR 53

int args_handler(int argc, char **argv, char **file_in, char **file_out, int *to_be_filtered);

#endif
