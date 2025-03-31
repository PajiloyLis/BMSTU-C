#ifndef _STRLIB_H_
#define _STRLIB_H_

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "size.h"

#define TRUE 1
#define FALSE 0

int solution(char *str_1, char *str_2, char ans[][WORD_SIZE * 2], size_t *ans_n);

#endif
