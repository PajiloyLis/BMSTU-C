#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct node_t *node_t;

node_t list_create_from_array(int *array, size_t n);

void list_free(node_t list);

node_t list_find_max(const node_t list);

void list_swap_values_by_pointers(node_t a, node_t b);

void list_print(node_t list);

node_t node_get_next(node_t node);

#endif