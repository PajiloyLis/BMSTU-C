#include <stdio.h>
#include "arrio.h"

int input(size_t *n, size_t *m, matrix_t arr)
{
    int return_code = EXIT_SUCCESS;
    printf("Input row and column count: ");
    if (scanf("%zu", n) != 1 || *n < 1 || *n > 10)
    {
        return_code = EXIT_FAILURE;
    }
    else if (scanf("%zu", m) != 1 || *m < 1 || *m > 10)
    {
        return_code = EXIT_FAILURE;
    }
    else
    {
        printf("Input matrix elements\n");
        for (size_t i = 0; i < *n && !return_code; ++i)
        {
            for (size_t j = 0; j < *m && !return_code; ++j)
            {
                if (scanf("%lld", *(arr + i) + j) != 1)
                {
                    return_code = EXIT_FAILURE;
                }
            }
        }
    }
    return return_code;
}

void output(matrix_ans_t arr, size_t n, size_t m)
{
    printf("New array\n");
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
        {
            printf("%lld ", arr[i][j]);
        }
        printf("\n");
    }
}
