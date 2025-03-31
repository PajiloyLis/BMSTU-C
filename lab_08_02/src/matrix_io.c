#include "matrix_io.h"

int input_matrix(matrix_t *matrix)
{
    if (!matrix || !(matrix->data))
        return NULL_POINTER_ERROR;
    if (matrix->n == 0 || matrix->m == 0)
        return MATRIX_SIZE_ERROR;
    for (size_t i = 0; i < matrix->n; ++i)
    {
        for (size_t j = 0; j < matrix->m; ++j)
        {
            if (scanf("%lld", &(matrix->data[i][j])) != 1)
            {
                return READING_NUMBER_ERROR;
            }
        }
    }
    return EXIT_SUCCESS;
}

void output_matrix(matrix_t *matrix)
{
    for (size_t i = 0; i < matrix->n; ++i)
    {
        for (size_t j = 0; j < matrix->m; ++j)
        {
            printf("%lld ", matrix->data[i][j]);
        }
        printf("\n");
    }
}