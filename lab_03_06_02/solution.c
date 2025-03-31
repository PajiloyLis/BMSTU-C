#include "solution.h"

void gen_matrix(matrix_t arr, size_t n, size_t m)
{
    int cur_elem = 1;
    for (size_t i = 1; i <= m; ++i)
    {
        if (i % 2 == 1)
        {
            for (size_t j = 1; j <= n; ++j)
            {
                *(*(arr + n - j) + m - i) = cur_elem;
                cur_elem++;
            }
        }
        else
        {
            for (size_t j = 0; j < n; ++j)
            {
                *(*(arr + j) + m - i) = cur_elem;
                cur_elem++;
            }
        }
    }
}
