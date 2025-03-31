#ifndef _FILE_H_
#define _FILE_H_

#include <stdlib.h>
#include <stdio.h>
#include "type.h"
#include "taskio.h"
#include <string.h>

#define FILE_OPEN_ERROR -4
#define FILE_WRITING_ERROR -5
#define FILE_EMPTY_ERROR -6
#define FILE_READING_ERROR -7
#define FILE_GET_SIZE_ERROR -8
#define FILE_INDEX_ERROR -9

int solution(char *mode, char *file_name, size_t cnt);

#endif
