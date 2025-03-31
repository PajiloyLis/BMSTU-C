#include "algorithms.h"

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int return_code = EXIT_SUCCESS;
    if (pb_src == NULL || pe_src == NULL || pb_dst == NULL || pe_dst == NULL)
    {
        return_code = NULL_FILTER_POINTER_ERROR;
    }
    else if (pb_src > pe_src)
    {
        return_code = ARRAY_POINTERS_ERROR;
    }
    else
    {
        int finded = 0;
        size_t n = 0;
        for (int i = 0; i < (pe_src - pb_src) && !finded; ++i)
        {
            if (*(pb_src + i) < 0)
                finded = 1;
            else
                n++;
        }
        if (n == 0)
            return_code = EMPTY_ARRAY_ERROR;
        else
        {
            int *p_buf = (int *)malloc(n * sizeof(int));
            if (!p_buf)
            {
                return_code = MEMORY_ALLOC_ERROR;
            }
            else
            {
                *pb_dst = p_buf;
                *pe_dst = *pb_dst + n;
                memcpy(*pb_dst, pb_src, n * sizeof(int));
            }
        }
    }
    return return_code;
}

void swap(void *a, void *b, size_t size);

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

void swap(void *a, void *b, size_t size)
{
    char p_buf[size];
    memcpy(p_buf, a, size);
    memcpy(a, b, size);
    memcpy(b, p_buf, size);
}
