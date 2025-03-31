#ifndef _FILE_PROC_H_
#define _FILE_PROC_H_

#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include "fileio.h"
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define FILE_GET_CNT_ERROR 11
#define EMPTY_STRING_ERROR 12
#define FILE_OPEN_ERROR 13
#define FILE_EMPTY_ERROR 14
#define PATTERN_ERROR 15
#define ERROR_IN_ARGS 16

int solution(char *mode, char *third_param, char *file_name, good *val, good *val_2);

#endif
