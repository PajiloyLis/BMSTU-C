#ifndef _GOOD_H_
#define _GOOD_H_

#include <stdint.h>
#include <inttypes.h>
#include <unistd.h>

typedef struct
{
    double mass, volume;
    ssize_t name_len;
    char *name;
} object_t;

#endif
