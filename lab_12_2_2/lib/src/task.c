#include "task.h"

void calc_fibs(size_t n, long long *array)
{
    array[0] = 0;
    if (n > 1)
        array[1] = 1;
    for (size_t i = 2; i < n; ++i)
    {
        array[i] = array[i - 1] + array[i - 2];
    }
}

int make_uniq(int *src, size_t src_n, int *dst, size_t *dst_n)
{
    size_t n = 0;
    int was;
    for (size_t i = 0; i < src_n; ++i)
    {
        was = 0;
        for (int j = i - 1; j >= 0 && !was; --j)
            if (src[i] == src[j])
                was = 1;
        if (!was)
            n++;
    }
    if (n > *dst_n)
    {
        *dst_n = n;
        return NOT_ENOUGH_SIZE;
    }
    n = 0;
    for (size_t i = 0; i < src_n; ++i)
    {
        was = 0;
        for (int j = i - 1; j >= 0 && !was; --j)
            if (src[i] == src[j])
                was = 1;
        if (!was)
        {
            dst[n] = src[i];
            n++;
        }
    }
    *dst_n = n;
    return EXIT_SUCCESS;
}