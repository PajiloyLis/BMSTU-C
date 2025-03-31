#ifndef _ARGS_H_
#define _ARGS_H_

#include <stdlib.h>
#include <string.h>

#define ARGS_COUNT_ERROR 21
#define ARGS_NULL_POINTER 22

#define ARG_FILE_NUMBER 1
#define ARG_PREFIX_NUMBER 2

int take_args(int n, char *args[], char **prefix, char **file_name);

#endif
