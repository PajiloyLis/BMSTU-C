#ifndef _ARGS_H_
#define _ARGS_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Буква действия
#define ARG_LETTER_NUMBER 1
#define ARG_LETER_LENGTH 2

// Число элементов для генерации
#define ARG_NUMBERS_CNT_NUMBER 2

// Имя файла при действии c
#define ARG_FILE_NUMBER_C 3

// Имя файла в иных случаях
#define ARG_FILE_NUMBER 2

// Ошибки
#define ARGS_COUNT_ERROR -1
#define ARGS_NAME_ERROR -2
#define ARGS_NUMBERS_CNT_ERROR -3

// Основание системы счисления
#define BASE 10

int take_agrs(int n, char *args[], char **mode, size_t *cnt, char **file_name);

#endif
