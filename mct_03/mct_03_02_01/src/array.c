#include "array.h"

int input_size(size_t *n)
{
    int return_code = EXIT_SUCCESS;
    if (!n)
        return_code = NULL_POINTER_ERROR;
    else
    {
        long long buf;
        printf("Input array size\n");
        if (scanf("%lld", &buf) != 1 || buf <= 0)
            return_code = INPUT_SIZE_ERROR;
        else
            *n = buf;
    }
    return return_code;
}

int allocate_array(long long **array, size_t n)
{
    int return_code = EXIT_SUCCESS;
    long long *buf;
    buf = malloc(n * sizeof(long long));
    if (!buf)
        return_code = MEMORY_ALLOC_ERROR;
    else
        *array = buf;
    return return_code;
}

int input_array(long long *array, size_t n)
{
    int return_code = EXIT_SUCCESS;
    if (!array)
        return_code = NULL_POINTER_ERROR;
    else
    {
        for (size_t i = 0; i < n && return_code == EXIT_SUCCESS; ++i)
        {
            printf("Input %zu elem: ", i + 1);
            if (scanf("%lld", &array[i]) != 1)
                return_code = ELEM_INPUT_ERROR;
        }
    }
    return return_code;
}

int delete_elems(long long *array, size_t *n)
{
    int return_code = EXIT_SUCCESS;
    if (!array)
        return_code = NULL_POINTER_ERROR;
    else
    {
        size_t count = 0;
        for (size_t i = 0; i < *n; ++i)
        {
            if (array[i] % 3 == 0)
            {
                count++;
            }
            else
            {
                array[i - count] = array[i];
            }
        }
        (*n) -= count;
    }

    return return_code;
}

void print_array(long long *array, size_t n)
{
    printf("Array:\n");
    for (size_t i = 0; i < n; ++i)
    {
        printf("%lld ", array[i]);
    }
    printf("\n");
}