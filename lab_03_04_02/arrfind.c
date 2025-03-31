#include <limits.h>
#include "arrfind.h"

int solve(matrix_t arr, size_t n, long long *max)
{
    int return_code = EXIT_FAILURE;
    *max = LLONG_MIN;
    for (size_t i = 1; i < n; ++i)
    {
        for (size_t j = n - i; j < n; ++j)
        {
            long long cur = *(*(arr + i) + j);
            if (llabs(cur) % BASE == ENDING && cur > *max)
            {
                *max = cur;
                return_code = EXIT_SUCCESS;
            }
        }
    }
    return return_code;
}
