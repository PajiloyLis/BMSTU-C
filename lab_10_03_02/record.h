#ifndef RECORD_H
#define RECORD_H

#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>

#define KEY_SET_ERROR 20

typedef struct record_t *record_t;

record_t record_allocate(const char *key, int val);

void record_free(void *record);

size_t record_get_size(void);

char *record_get_key(record_t record);

int *record_get_val_ptr(record_t record);

int record_compare_keys(void *a, void *b);

void record_set_value(record_t record, int val);

int record_set_key(record_t record, char *key);

#endif