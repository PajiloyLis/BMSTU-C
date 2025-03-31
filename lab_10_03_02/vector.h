#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>

#define VECTOR_DEFAULT_SIZE 20

#define VECTOR_ALLOCATION_ERROR 30
#define VECTOR_REALLOCATION_ERROR 31

typedef struct sorted_vector_t *sorted_vector_t;

int vector_allocate(sorted_vector_t vector, size_t n);

int vector_reallocate(sorted_vector_t vector);

void vector_free(sorted_vector_t vector, void (*elem_free)(void *));

int vector_insert(sorted_vector_t vector, void *elem_to_insert, int (*elem_cmp)(void *, void *));

void *vector_find(sorted_vector_t vector, void *elem_to_find, int (*elem_cmp)(void *, void *));

void vector_del_elem(sorted_vector_t vector, void *elem_to_del, int (*elem_cmp)(void *, void *), void (*elem_free)(void *));

size_t vector_get_cnt(sorted_vector_t vector);

void *vector_get_elem_by_ind(sorted_vector_t vector, size_t i);

size_t vector_get_size(void);

#endif