#include "record.h"

struct record_t
{
    int val;
    char *key;
};

void record_free(void *record)
{
    if (record)
    {
        free(((record_t)record)->key);
        free(record);
    }
}

record_t record_allocate(const char *key, int val)
{
    record_t record = calloc(1, sizeof(struct record_t));
    if (!record)
        return NULL;
    record->key = strdup(key);
    if (!record->key)
    {
        free(record);
        return NULL;
    }
    record->val = val;
    return record;
}

size_t record_get_size(void)
{
    return sizeof(struct record_t);
}

char *record_get_key(record_t record)
{
    return record->key;
}

int *record_get_val_ptr(record_t record)
{
    return &record->val;
}

int record_compare_keys(void *a, void *b)
{
    return strcmp(((record_t)a)->key, ((record_t)b)->key);
}

int record_set_key(record_t record, char *key)
{
    char *buf = strdup(key);
    if (!buf)
        return KEY_SET_ERROR;
    record->key = buf;
    return EXIT_SUCCESS;
}

void record_set_value(record_t record, int val)
{
    record->val = val;
}