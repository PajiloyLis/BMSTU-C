#include "vector.h"

struct sorted_vector_t
{
    void **array;
    size_t elems_cnt;
    size_t allocated_cnt;
    bool is_alocated;
};

static ssize_t find_pos_to_insert(sorted_vector_t vector, void *elem_to_insert, int (*elem_cmp)(void *, void *));

static ssize_t find_pos_to_delete(sorted_vector_t vector, void *elem_to_insert, int (*elem_cmp)(void *, void *));

int vector_allocate(sorted_vector_t vector, size_t n)
{
    if (!vector || !n)
    {
        return VECTOR_ALLOCATION_ERROR;
    }
    void *buf = calloc(n, sizeof(void *));
    if (!buf)
        return VECTOR_ALLOCATION_ERROR;
    vector->array = buf;
    vector->elems_cnt = 0;
    vector->allocated_cnt = n;
    vector->is_alocated = true;
    return EXIT_SUCCESS;
}

int vector_reallocate(sorted_vector_t vector)
{
    if (!vector)
        return VECTOR_REALLOCATION_ERROR;
    void *buf = realloc(vector->array, sizeof(void *) * vector->allocated_cnt * 2);
    if (!buf)
        return VECTOR_REALLOCATION_ERROR;
    vector->array = buf;
    vector->allocated_cnt *= 2;
    return EXIT_SUCCESS;
}

void vector_free(sorted_vector_t vector, void (*elem_free)(void *))
{
    if (vector)
    {
        for (size_t i = 0; i < vector->elems_cnt; ++i)
            elem_free(vector->array[i]);
        free(vector->array);
        vector->array = NULL;
        vector->allocated_cnt = vector->elems_cnt = 0;
        vector->is_alocated = false;
    }
}

int vector_insert(sorted_vector_t vector, void *elem_to_insert, int (*elem_cmp)(void *, void *))
{
    int rc = EXIT_SUCCESS;
    if (vector->elems_cnt + 1 >= vector->allocated_cnt)
    {
        rc = vector_reallocate(vector);
        if (rc != EXIT_SUCCESS)
            return rc;
    }
    ssize_t ind_to_insert = find_pos_to_insert(vector, elem_to_insert, elem_cmp);
    for (ssize_t i = vector->elems_cnt - 1; i >= ind_to_insert; --i)
    {
        vector->array[i + 1] = vector->array[i];
    }
    vector->array[ind_to_insert] = elem_to_insert;
    vector->elems_cnt++;
    return rc;
}

void vector_del_elem(sorted_vector_t vector, void *elem_to_del, int (*elem_cmp)(void *, void *), void (*elem_free)(void *))
{
    ssize_t ind_to_del = find_pos_to_delete(vector, elem_to_del, elem_cmp);
    if (ind_to_del == -1)
        return;
    elem_free(vector->array[ind_to_del]);
    for (ssize_t i = ind_to_del + 1; i < (ssize_t)vector->elems_cnt; ++i)
    {
        vector->array[i - 1] = vector->array[i];
    }
    vector->elems_cnt--;
}

void *vector_find(sorted_vector_t vector, void *elem_to_find, int (*elem_cmp)(void *, void *))
{
    ssize_t l = -1, r = vector->elems_cnt;
    while (r - l > 1)
    {
        ssize_t m = (r + l) / 2;
        if (elem_cmp(vector->array[m], elem_to_find) >= 0)
            r = m;
        else
            l = m;
    }
    if (r == (ssize_t)vector->elems_cnt || elem_cmp(vector->array[r], elem_to_find))
        return NULL;
    return vector->array[r];
}

size_t vector_get_cnt(sorted_vector_t vector)
{
    return vector->elems_cnt;
}

void *vector_get_elem_by_ind(sorted_vector_t vector, size_t i)
{
    if (!vector)
        return NULL;
    return vector->array[i];
}

static ssize_t find_pos_to_insert(sorted_vector_t vector, void *elem_to_insert, int (*elem_cmp)(void *, void *))
{
    ssize_t l = -1, r = vector->elems_cnt;
    while (r - l > 1)
    {
        ssize_t m = (r + l) / 2;
        if (elem_cmp(vector->array[m], elem_to_insert) > 0)
            r = m;
        else
            l = m;
    }
    return r;
}

static ssize_t find_pos_to_delete(sorted_vector_t vector, void *elem_to_del, int (*elem_cmp)(void *, void *))
{
    ssize_t l = -1, r = vector->elems_cnt;
    while (r - l > 1)
    {
        ssize_t m = (r + l) / 2;
        if (elem_cmp(vector->array[m], elem_to_del) > 0)
            r = m;
        else
            l = m;
    }
    return l;
}

size_t vector_get_size(void)
{
    return sizeof(struct sorted_vector_t);
}