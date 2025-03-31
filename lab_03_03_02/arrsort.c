#include "arrsort.h"

void add_mull(matrix arr, size_t n, size_t m);

void swap(long long *a, long long *b, size_t m);

void copy(long long *a, long long *b, size_t m);

void isort(matrix arr, size_t n, size_t m)
{
    add_mull(arr, n, m);
    for (size_t i = 1; i < n; ++i)
    {
        long long(*cur)[SIZE + 1] = arr + i, (*prev)[SIZE + 1] = cur - 1;
        while (cur != arr && *(*cur + m) < *(*prev + m))
        {
            swap(*cur, *prev, m);
            --cur;
            --prev;
        }
    }
}

void add_mull(matrix arr, size_t n, size_t m)
{
    for (long long(*row)[SIZE + 1] = arr; row < arr + n; ++row)
    {
        long long mul = 1;
        for (size_t j = 0; j < m; ++j)
        {
            mul *= *(*row + j);
        }
        *(*row + m) = mul;
    }
}

void swap(long long *a, long long *b, size_t m)
{
    long long buf[SIZE + 1];
    copy(buf, a, m);
    copy(a, b, m);
    copy(b, buf, m);
}

void copy(long long *a, long long *b, size_t m)
{
    for (size_t i = 0; i <= m; ++i)
    {
        *(a + i) = *(b + i);
    }
}

