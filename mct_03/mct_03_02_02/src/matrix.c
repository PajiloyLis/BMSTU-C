#include "matrix.h"

int input_sizes(size_t *n, size_t *m)
{
    int return_code = EXIT_SUCCESS;
    long long buf;
    if (scanf("%lld", &buf) == 1 && buf > 0)
    {
        *n = buf;
        if (scanf("%lld", &buf) == 1 && buf > 0)
            *m = buf;
        else
            return_code = SIZE_INPUT_ERROR;
    }
    else
        return_code = SIZE_INPUT_ERROR;
    return return_code;
}

int allocate_matrix(matrix_t *matrix)
{
    int return_code = EXIT_SUCCESS;
    long long **buf, *buf_str;
    buf = calloc(matrix->n, sizeof(long long *));
    if (!buf)
    {
        return_code = ALLOCATION_ERRROR;
    }
    else
    {
        matrix->strs = buf;
        for (size_t i = 0; i < matrix->n && return_code == EXIT_SUCCESS; ++i)
        {
            buf_str = malloc(matrix->m * sizeof(long long));
            if (!buf_str)
            {
                free_matrix(matrix);
                return_code = ALLOCATION_ERRROR;
            }
            else
            {
                matrix->strs[i] = buf_str;
            }
        }
    }
    return return_code;
}

void free_matrix(matrix_t *matrix)
{
    for (size_t i = 0; i < matrix->n; ++i)
        free(matrix->strs[i]);
    free(matrix->strs);
}

int input_matrix(matrix_t *matrix)
{
    int return_code = EXIT_SUCCESS;
    for (size_t i = 0; i < matrix->n && return_code == EXIT_SUCCESS; ++i)
    {
        for (size_t j = 0; j < matrix->m && return_code == EXIT_SUCCESS; ++j)
        {
            if (scanf("%lld", &(matrix->strs[i][j])) != 1)
                return_code = ELEM_INPUT_ERROR;
        }
    }
    return return_code;
}