#include "list.h"

node_t *list_allocate(size_t n)
{
    node_t *head = NULL, *tail = NULL, *cur;
    for (size_t i = 0; i < n; ++i)
    {
        cur = calloc(1, sizeof(node_t));
        if (!cur)
        {
            list_free(head);
            head = NULL;
            break;
        }
        else
        {
            if (tail)
                tail->next = cur;
            if (!head)
                head = cur;
            tail = cur;
        }
    }
    return head;
}

int list_values_input(node_t *list)
{
    int rc = EXIT_SUCCESS;
    for (; list && rc == EXIT_SUCCESS; list = list->next)
    {
        if (scanf("%d", &(list->val)) != 1)
            rc = LIST_VALUE_INPUT_ERROR;
    }
    return rc;
}

int calc_value_by_x(node_t *coefs, long long *x_pows, size_t n, long long *ans)
{
    if (!coefs || n == 0 || !x_pows || !ans)
        return CALC_VALUE_ARGS_ERROR;
    *ans = 0;
    for (int i = n - 1; i >= 0; --i, coefs = coefs->next)
        *ans += x_pows[i] * coefs->val;
    return EXIT_SUCCESS;
}

int calc_derivative(node_t *coefs, node_t *derivative_list, size_t n)
{
    if (!coefs || n == 0 || (!derivative_list && n > 1))
        return CALC_DERIVATIVE_ARGS_ERROR;
    if (n == 1)
    {
        derivative_list = NULL;
        return EMPTY_DERIVATIVE_ERROR;
    }
    else
    {
        for (size_t i = n - 1; i > 0; --i, derivative_list = derivative_list->next, coefs = coefs->next)
            derivative_list->val = coefs->val * i;
    }
    return EXIT_SUCCESS;
}

int calc_coef_sum(node_t *coefs_1, size_t n_1, node_t *coefs_2, size_t n_2, node_t *ans)
{
    if (!coefs_1 || !coefs_2 || !ans || n_1 == 0 || n_2 == 0)
        return CALC_SUM_ARGS_ERROR;
    for (size_t i = (n_1 > n_2) ? n_1 : n_2; i > 0; --i, ans = ans->next)
    {
        ans->val = 0;
        if (i <= n_1)
        {
            ans->val += coefs_1->val;
            coefs_1 = coefs_1->next;
        }
        if (i <= n_2)
        {
            ans->val += coefs_2->val;
            coefs_2 = coefs_2->next;
        }
    }
    return EXIT_SUCCESS;
}

int split_coefs_by_parity(node_t *coefs, size_t n, node_t *even_coefs, node_t *odd_coefs)
{
    if (!coefs || !even_coefs || (!odd_coefs && n > 1) || n == 0)
        return SPLIT_POWS_ARGS_ERROR;
    for (int i = n - 1; i >= 0; --i, coefs = coefs->next)
    {
        if (i % 2)
        {
            odd_coefs->val = coefs->val;
            odd_coefs = odd_coefs->next;
        }
        else
        {
            even_coefs->val = coefs->val;
            even_coefs = even_coefs->next;
        }
    }
    return EXIT_SUCCESS;
}

void print_list(node_t *list)
{
    for (; list; list = list->next)
        printf("%d ", list->val);
}

void list_free(node_t *head)
{
    node_t *next;
    for (; head; head = next)
    {
        next = head->next;
        free(head);
    }
}