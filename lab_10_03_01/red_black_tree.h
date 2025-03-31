#ifndef RB_TREE_H
#define RB_TREE_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t *node_t;

node_t node_allocate(void *data);

void tree_insert(node_t *root, node_t node_to_insert, int (*data_cmp)(void *, void *));

node_t tree_search(node_t subtree_root, void *data_to_find, int (*data_cmp)(void *, void *));

void tree_delete(node_t *root, node_t node_to_delete, void (*data_delete)(void *));

void *tree_get_data_by_node(node_t node);

void tree_clear(node_t subtree_root, void (*data_delete)(void *));

node_t tree_min(node_t subtree_root);

node_t tree_max(node_t subtree_root);

void tree_each(node_t subtree_root, void (*action)(const char *key, int *num, void *param), void *param, char *(*get_key)(void *), int *(get_val)(void *));

#endif