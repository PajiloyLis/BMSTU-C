#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include "book.h"

#define LIST_CREATION_ERROR 50

typedef struct node_t node_t;

struct node_t
{
    void *data;
    node_t *next;
};

node_t *list_create_from_data(void *array, size_t size, size_t n);

void insert(node_t **head, node_t *elem, node_t *before);

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *));

void remove_duplicates(node_t **head, int (*comparator)(const void *, const void *));

node_t *sort(node_t *list, int (*comparator)(const void *, const void *));

void list_data_print(node_t *head, void (*printer)(void *));

void front_back_split(node_t *head, node_t **back);

node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *));

void list_free(node_t *head);

#endif