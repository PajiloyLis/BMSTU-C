#include "arrlib.h"

static void swap(void *a, void *b, size_t size);

int key(const int *pb_src, const int *pe_src, int *pb_dst, size_t *new_n)
{
    int return_code = EXIT_SUCCESS;
    if (pb_src == NULL || pe_src == NULL || (pb_dst == NULL && new_n != 0))
    {
        return_code = NULL_FILTER_POINTER_ERROR;
    }
    else if (pb_src > pe_src)
    {
        return_code = ARRAY_POINTERS_ERROR;
    }
    else
    {
        size_t n = 0;
        for (const int *cur = pb_src; cur != pe_src && *cur >= 0; ++cur, ++n)
            ;
        if (n == 0)
            return_code = EMPTY_ARRAY_ERROR;
        else if (n > *new_n)
        {
            *new_n = n;
            return_code = EXIT_SUCCESS;
        }
        else
            memcpy(pb_dst, pb_src, *new_n * sizeof(int));
    }
    return return_code;
}

void mysort(void *p_begin, size_t n, size_t size, cmp cmp)
{
    char *p_end = (char *)p_begin + n * size;
    for (size_t i = 0; i < n; ++i)
    {
        for (char *p_cur = p_begin; p_cur != p_end - size * (i + 1); p_cur += size * sizeof(char))
        {
            if (cmp(p_cur, p_cur + size) > 0)
            {
                swap(p_cur, p_cur + size, size);
            }
        }
    }
}

int compare_int(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

static void swap(void *a, void *b, size_t size)
{
    char p_buf[size];
    memcpy(p_buf, a, size);
    memcpy(a, b, size);
    memcpy(b, p_buf, size);
}