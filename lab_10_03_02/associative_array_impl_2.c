#include "associative_array.h"
#include "vector.h"
#include "record.h"

struct assoc_array_type
{
    sorted_vector_t root;
};

assoc_array_t assoc_array_create(void)
{
    assoc_array_t map = calloc(1, sizeof(struct assoc_array_type));
    if (!map)
        return NULL;
    map->root = calloc(1, vector_get_size());
    if (!map->root)
    {
        free(map);
        return NULL;
    }
    return map;
}

assoc_array_error_t assoc_array_clear(assoc_array_t arr)
{
    if (!arr)
        return ASSOC_ARRAY_INVALID_PARAM;
    vector_free(arr->root, record_free);
    return ASSOC_ARRAY_OK;
}

void assoc_array_destroy(assoc_array_t *arr)
{
    if (arr && *arr)
    {
        assoc_array_clear(*arr);
        free((*arr)->root);
        free(*arr);
    }
    *arr = NULL;
}

assoc_array_error_t assoc_array_insert(assoc_array_t arr, const char *key, int num)
{
    if (!arr || !key || !strlen(key))
        return ASSOC_ARRAY_INVALID_PARAM;

    if (!vector_get_cnt(arr->root))
        if (vector_allocate(arr->root, VECTOR_DEFAULT_SIZE) != EXIT_SUCCESS)
            return ASSOC_ARRAY_MEM;

    record_t record_to_insert = record_allocate(key, num);
    if (!record_to_insert)
        return ASSOC_ARRAY_MEM;
    if (vector_find(arr->root, record_to_insert, record_compare_keys))
    {
        record_free(record_to_insert);
        return ASSOC_ARRAY_KEY_EXISTS;
    }

    if (vector_insert(arr->root, record_to_insert, record_compare_keys) != EXIT_SUCCESS)
    {
        record_free(record_to_insert);
        return ASSOC_ARRAY_MEM;
    }
    return EXIT_SUCCESS;
}

assoc_array_error_t assoc_array_find(const assoc_array_t arr, const char *key, int **num)
{
    if (!arr || !key || !strlen(key) || !num)
        return ASSOC_ARRAY_INVALID_PARAM;

    record_t record_to_find = record_allocate(key, 0);
    if (!record_to_find)
        return ASSOC_ARRAY_MEM;
    record_t finded = vector_find(arr->root, record_to_find, record_compare_keys);
    record_free(record_to_find);

    if (!finded)
        return ASSOC_ARRAY_NOT_FOUND;
    *num = record_get_val_ptr(finded);

    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_remove(assoc_array_t arr, const char *key)
{
    if (!arr || !key || !strlen(key))
        return ASSOC_ARRAY_INVALID_PARAM;
    record_t record_to_del = record_allocate(key, 0);
    if (!record_to_del)
        return ASSOC_ARRAY_MEM;
    if (!vector_find(arr->root, record_to_del, record_compare_keys))
    {
        record_free(record_to_del);
        return ASSOC_ARRAY_NOT_FOUND;
    }

    vector_del_elem(arr->root, record_to_del, record_compare_keys, record_free);
    record_free(record_to_del);
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_each(const assoc_array_t arr, void (*action)(const char *key, int *num, void *param), void *param)
{
    if (!arr || !action)
        return ASSOC_ARRAY_INVALID_PARAM;

    size_t cnt = vector_get_cnt(arr->root);
    for (size_t i = 0; i < cnt; ++i)
    {
        void *elem = vector_get_elem_by_ind(arr->root, i);
        action(record_get_key(elem), record_get_val_ptr(elem), param);
    }
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_min(const assoc_array_t arr, int **num)
{
    if (!arr || !num)
        return ASSOC_ARRAY_INVALID_PARAM;

    size_t cnt = vector_get_cnt(arr->root);
    if (!cnt)
        return ASSOC_ARRAY_NOT_FOUND;
    *num = record_get_val_ptr(vector_get_elem_by_ind(arr->root, 0));
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_max(const assoc_array_t arr, int **num)
{
    if (!arr || !num)
        return ASSOC_ARRAY_INVALID_PARAM;

    size_t cnt = vector_get_cnt(arr->root);
    if (!cnt)
        return ASSOC_ARRAY_NOT_FOUND;
    *num = record_get_val_ptr(vector_get_elem_by_ind(arr->root, cnt - 1));
    return ASSOC_ARRAY_OK;
}