#ifndef SNPRINTF_H
#define SNPRINTF_H

#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>

int my_snprintf(char *restrict s, size_t n, const char *restrict format, ...);

#endif