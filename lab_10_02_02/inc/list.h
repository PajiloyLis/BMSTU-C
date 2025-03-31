#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>

#define LIST_ALLOCATION_ERROR 20
#define LIST_VALUE_INPUT_ERROR 21
#define CALC_VALUE_ARGS_ERROR 22
#define CALC_DERIVATIVE_ARGS_ERROR 23
#define CALC_SUM_ARGS_ERROR 24
#define SPLIT_POWS_ARGS_ERROR 25
#define EMPTY_DERIVATIVE_ERROR 26

typedef struct node_t node_t;

struct node_t
{
    int val;
    node_t *next;
};

node_t *list_allocate(size_t n);

int list_values_input(node_t *list);

int calc_value_by_x(node_t *coefs, long long *x_pows, size_t n, long long *ans);

int calc_derivative(node_t *coefs, node_t *derivative_coefs, size_t n);

int calc_coef_sum(node_t *coefs_1, size_t n_1, node_t *coefs_2, size_t n_2, node_t *ans);

int split_coefs_by_parity(node_t *coefs, size_t n, node_t *even_coefs, node_t *odd_coefs);

void print_list(node_t *list);

void list_free(node_t *head);

#endif