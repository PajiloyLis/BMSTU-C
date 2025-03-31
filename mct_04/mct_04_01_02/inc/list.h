#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct node_t *node_t;

node_t list_create();

node_t list_create_from_array(int *array, size_t n);

void list_free(node_t list);

node_t find_third_min(const node_t list);

node_t delete_node_by_pointer(node_t list, node_t to_del);

void list_print(node_t list);

#endif