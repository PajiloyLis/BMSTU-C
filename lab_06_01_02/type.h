#ifndef _GOOD_H_
#define _GOOD_H_

#include <stdint.h>
#include <inttypes.h>

#define NAME_SIZE 25

typedef struct
{
    char name[NAME_SIZE + 1];
    double mass, volume;
} object_t;

#endif
