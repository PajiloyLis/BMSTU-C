#ifndef _ARGS_H_
#define _ARGS_H_

#include <stdlib.h>
#include <string.h>

#define FAIL 53

// Буква действия
#define ARG_LETTER_NUMBER 1
#define ARG_LETER_LENGTH 3

// Имя входного файла
#define ARG_FILE_NUMBER 2

// Третий параметр
#define ARG_THIRD_NUMBER 3

int take_agrs(int n, char *args[], char **mode, char **third_param, char **file_name);

#endif
