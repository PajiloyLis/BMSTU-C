#include "list.h"
#include <stdlib.h>
#include <stdio.h>

#define ARRAY_SIZE_ERROR 10
#define ARRAY_INPUT_PARAMS_ERROR 11
#define ARRAY_INPUT_VALUES_ERROR 12
#define LIST_ALLOCATION_ERROR 13
#define MAX_NOT_FOUND 14
#define ARRAY_ALLOCATION_ERROR 15

int array_input(int *array, size_t n)
{
    if (n < 2 || !array)
        return ARRAY_INPUT_PARAMS_ERROR;
    for (size_t i = 0; i < n; ++i)
    {
        if (scanf("%d", array + i) != 1)
        {
            return ARRAY_INPUT_VALUES_ERROR;
        }
    }
    return EXIT_SUCCESS;
}

int main(void)
{
    size_t n = 0;
    long long n_buf;
    int rc = EXIT_SUCCESS;
    int *arr = NULL;
    node_t list = NULL;
    if (scanf("%lld", &n_buf) != 1 || n_buf < 2)
    {
        printf("Must be integer more then 1\n");
        rc = ARRAY_SIZE_ERROR;
    }
    else
    {
        n = n_buf;
        arr = malloc(n * sizeof(int));
        if (!arr)
            rc = ARRAY_ALLOCATION_ERROR;
    }
    rc = rc == EXIT_SUCCESS ? array_input(arr, n) : rc;
    if (rc == EXIT_SUCCESS)
    {
        list = list_create_from_array(arr, n);
        if (!list)
            rc = LIST_ALLOCATION_ERROR;
        node_t max = rc == EXIT_SUCCESS ? list_find_max(list) : NULL;
        if (!max)
            rc = MAX_NOT_FOUND;
        if (rc == EXIT_SUCCESS)
        {
            list_swap_values_by_pointers(node_get_next(list), max);
            list_print(list);
        }
        if (list)
            list_free(list);
    }
    if (arr)
        free(arr);
}