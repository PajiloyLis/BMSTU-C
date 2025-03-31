#define _GNU_SOURCE

#include "associative_array.h"
#include "red_black_tree.h"
#include "record.h"

struct assoc_array_type
{
    node_t root;
};

assoc_array_t assoc_array_create(void)
{
    assoc_array_t assoc_array_object = calloc(1, sizeof(struct assoc_array_type));
    return assoc_array_object;
}

void assoc_array_destroy(assoc_array_t *arr)
{
    if (arr)
    {
        assoc_array_clear(*arr);
        free(*arr);
        *arr = NULL;
    }
}

assoc_array_error_t assoc_array_clear(assoc_array_t arr)
{
    if (!arr)
        return ASSOC_ARRAY_INVALID_PARAM;
    tree_clear(arr->root, record_free);
    arr->root = NULL;
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_remove(assoc_array_t arr, const char *key)
{
    if (!arr || !key || !strlen(key))
        return ASSOC_ARRAY_INVALID_PARAM;
    record_t record_to_find = record_allocate(key, 0);
    if (!record_to_find)
        return ASSOC_ARRAY_MEM;
    node_t node_to_delete = tree_search(arr->root, record_to_find, record_compare_keys);
    record_free(record_to_find);
    if (!node_to_delete)
        return ASSOC_ARRAY_NOT_FOUND;
    tree_delete(&arr->root, node_to_delete, record_free);
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_find(const assoc_array_t arr, const char *key, int **num)
{
    if (!arr || !key || !strlen(key) || !num)
        return ASSOC_ARRAY_INVALID_PARAM;

    record_t new_record = record_allocate(key, 0);
    if (!new_record)
        return ASSOC_ARRAY_MEM;

    node_t res = tree_search(arr->root, new_record, record_compare_keys);
    record_free(new_record);
    if (!res)
        return ASSOC_ARRAY_NOT_FOUND;
    *num = record_get_val_ptr(tree_get_data_by_node(res));
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_insert(assoc_array_t arr, const char *key, int num)
{
    if (!arr || !key || !strlen(key))
        return ASSOC_ARRAY_INVALID_PARAM;

    record_t new_record = record_allocate(key, num);
    if (!new_record)
        return ASSOC_ARRAY_MEM;

    if (tree_search(arr->root, new_record, record_compare_keys))
    {
        record_free(new_record);
        return ASSOC_ARRAY_KEY_EXISTS;
    }

    node_t node_to_insert = node_allocate(new_record);
    if (!node_to_insert)
        return ASSOC_ARRAY_MEM;

    tree_insert(&arr->root, node_to_insert, record_compare_keys);
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_each(const assoc_array_t tree, void (*action)(const char *key, int *num, void *param), void *param)
{
    if (!tree || !action)
        return ASSOC_ARRAY_INVALID_PARAM;
    tree_each(tree->root, action, param, record_get_key, record_get_val_ptr);
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_min(const assoc_array_t arr, int **num)
{
    if (!arr || !num)
        return ASSOC_ARRAY_INVALID_PARAM;
    if (!arr->root)
        return ASSOC_ARRAY_NOT_FOUND;
    node_t cur = tree_min(arr->root);
    *num = record_get_val_ptr(tree_get_data_by_node(cur));
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_max(const assoc_array_t arr, int **num)
{
    if (!arr || !num)
        return ASSOC_ARRAY_INVALID_PARAM;
    if (!arr->root)
        return ASSOC_ARRAY_NOT_FOUND;
    node_t cur = tree_max(arr->root);
    *num = record_get_val_ptr(tree_get_data_by_node(cur));
    return ASSOC_ARRAY_OK;
}
