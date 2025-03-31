#ifndef _GOOD_H_
#define _GOOD_H_

#include <stdint.h>
#include <inttypes.h>

#define NAME_SIZE 30
#define MAKER_SIZE 15
#define TOTAL_SIZE 65

struct good_t
{
    char name[NAME_SIZE + 1], maker[MAKER_SIZE + 1];
    uint32_t cost, count;
};

typedef struct good_t good;

#endif
