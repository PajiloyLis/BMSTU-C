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
    else if (scanf("%zu", m) != 1 || *m < 1 || *m > 10 || *m != *n)
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

void output(long long val)
{
    printf("Max value: %lld\n", val);
}
