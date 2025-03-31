#include "arr_make.h"

void make_array(size_t n, size_t m, matrix_t arr, int *result)
{
    for (size_t i = 0; i < m; ++i)
    {
        if (n == 1)
        {
            result[i] = 0;
        }
        else
        {
            result[i] = 1;
            for (long long(*p)[SIZE] = arr + 1; p < arr + n; p++)
            {
                if ((*(p - 1))[i] * (*p)[i] >= 0ll)
                {
                    result[i] = 0;
                }
            }
        }
    }
}
