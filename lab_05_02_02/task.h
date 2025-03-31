#ifndef _TASK_H_
#define _TASK_H_

#include <stdio.h>
#include <stdlib.h>

#define FILE_EMPTY_ERROR -1
#define FILE_READING_ERROR -2
#define FILE_OPEN_ERROR -3

int calc_variance(char *file_name, double *variance);

#endif
