#ifndef _FILE_H_
#define _FILE_H_

#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include <string.h>
#include <ctype.h>

#define NULL_POINTER_ERROR 3
#define FILE_READING_ERROR 1
#define FILE_WRITING_ERROR 2
#define INPUT_ERROR 4

int get_from_pos(good *val, int pos, FILE *f);

int set_by_pos(good *val, int pos, FILE *f);

void output(good *val);

int input(good *val);

#endif
