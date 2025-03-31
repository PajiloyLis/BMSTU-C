#ifndef TASK_H
#define TASK_H

#include<stdlib.h>

#define NOT_ENOUGH_SIZE 10

void calc_fibs(size_t n, long long *array);

int make_uniq(int *src, size_t src_n, int *dst, size_t *dst_n);

#endif