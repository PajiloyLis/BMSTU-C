#ifndef _STRIO_H_
#define _STRIO_H_

#include <stdlib.h>
#include <stdio.h>
#include "size.h"
#include <string.h>

int input(char *str);

void output(char str[][WORD_SIZE * 2], size_t n);

#endif
