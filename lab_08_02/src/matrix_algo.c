#include "matrix_algo.h"

static size_t find_axis_index(matrix_t *matrix, bool axis);

int delete_column(matrix_t *matrix);

int delete_string(matrix_t *matrix);

int append_string(matrix_t *matrix);

int append_columns(matrix_t *matrix);

int matrix_transpose(matrix_t *matrix, matrix_t *transposed_matrix);

void matrix_copy(matrix_t *src, matrix_t *dst);

void make_identity_matrix(matrix_t *matrix);

int matrix_pow(matrix_t *matrix, long long n, matrix_t *ans)
{
    if (!matrix || !matrix->data || !ans || !ans->data)
        return NULL_POINTER_ERROR;
    if (matrix->n == 0 || matrix->m == 0 || ans->n == 0 || ans->m == 0)
        return MATRIX_SIZE_ERROR;
    if (n < 0)
        return NEGATIVE_POW_ERROR;
    if (n == 0)
    {
        make_identity_matrix(ans);
        return EXIT_SUCCESS;
    }
    matrix_t buf, buf_2;
    buf.n = buf.m = buf_2.n = buf_2.m = matrix->n;
    int return_code = EXIT_SUCCESS;
    return_code = allocate_matrix(&buf, buf.n, buf.m);
    if (return_code != EXIT_SUCCESS)
        return return_code;
    matrix_copy(matrix, &buf);
    make_identity_matrix(ans);
    return_code = allocate_matrix(&buf_2, buf.n, buf.m);
    if (return_code != EXIT_SUCCESS)
        return return_code;
    while (n && return_code == EXIT_SUCCESS)
    {
        if (n & 1)
        {
            return_code = matrix_multiply(ans, &buf, &buf_2);
            matrix_copy(&buf_2, ans);
        }
        return_code = return_code == EXIT_SUCCESS ? matrix_multiply(&buf, &buf, &buf_2) : return_code;
        if (return_code == EXIT_SUCCESS)
            matrix_copy(&buf_2, &buf);
        n >>= 1;
    }
    free_matrix(&buf);
    free_matrix(&buf_2);
    return return_code;
}

void make_identity_matrix(matrix_t *matrix)
{
    for (size_t i = 0; i < matrix->n; ++i)
    {
        for (size_t j = 0; j < matrix->m; ++j)
        {
            if (i == j)
                matrix->data[i][j] = 1;
            else
                matrix->data[i][j] = 0;
        }
    }
}

void matrix_copy(matrix_t *src, matrix_t *dst)
{
    for (size_t i = 0; i < src->n; ++i)
    {
        for (size_t j = 0; j < src->m; ++j)
        {
            dst->data[i][j] = src->data[i][j];
        }
    }
}

int matrix_multiply(matrix_t *matr_1, matrix_t *matr_2, matrix_t *ans)
{
    int return_code = EXIT_SUCCESS;
    if (!matr_1 || !matr_2 || !ans || !matr_1->data || !matr_2->data || !ans->data)
        return NULL_POINTER_ERROR;
    if (matr_1->n == 0 || matr_1->m == 0 || matr_2->n == 0 || matr_2->m == 0 || ans->n == 0 || ans->m == 0)
        return MATRIX_SIZE_ERROR;
    int sum;
    matrix_t transposed;
    transposed.n = transposed.m = matr_1->n;
    return_code = allocate_matrix(&transposed, matr_1->n, matr_1->m);
    if (return_code != EXIT_SUCCESS)
        return return_code;
    return_code = matrix_transpose(matr_2, &transposed);
    if (return_code != EXIT_SUCCESS)
    {
        free_matrix(&transposed);
        return return_code;
    }
    for (size_t i = 0; i < matr_1->n; ++i)
    {
        for (size_t k = 0; k < matr_1->n; ++k)
        {
            sum = 0;
            for (size_t j = 0; j < matr_1->n; ++j)
            {
                sum += matr_1->data[i][j] * transposed.data[k][j];
            }
            ans->data[i][k] = sum;
        }
    }
    free_matrix(&transposed);
    return EXIT_SUCCESS;
}

int matrix_transpose(matrix_t *matrix, matrix_t *transposed_matrix)
{
    if (!matrix || !transposed_matrix || !matrix->data || !transposed_matrix->data)
        return NULL_POINTER_ERROR;
    if (matrix->n == 0 || matrix->m == 0 || transposed_matrix->n == 0 || transposed_matrix->m == 0)
        return MATRIX_SIZE_ERROR;
    for (size_t i = 0; i < matrix->n; ++i)
    {
        for (size_t j = i; j < matrix->n; ++j)
        {
            transposed_matrix->data[i][j] = matrix->data[j][i];
            transposed_matrix->data[j][i] = matrix->data[i][j];
        }
    }
    return EXIT_SUCCESS;
}

int make_quadratic(matrix_t *matrix)
{
    if (!matrix || !(matrix->data))
        return NULL_POINTER_ERROR;
    if (matrix->m == 0 || matrix->n == 0)
        return MATRIX_SIZE_ERROR;
    int return_code = EXIT_SUCCESS;
    while (matrix->m > matrix->n && return_code == EXIT_SUCCESS)
        return_code = delete_column(matrix);
    if (return_code != EXIT_SUCCESS)
        return return_code;
    while (matrix->n > matrix->m && return_code == EXIT_SUCCESS)
        return_code = delete_string(matrix);
    return return_code;
}

int calc_expanded_size(matrix_t *matr_1, matrix_t *matr_2, size_t *n)
{
    if (!matr_1 || !matr_2 || !n)
        return NULL_POINTER_ERROR;
    if (matr_1->m == 0 || matr_1->n == 0 || matr_2->n == 0 || matr_2->m == 0)
        return MATRIX_SIZE_ERROR;
    if (matr_1->n > matr_2->n)
        *n = matr_1->n;
    else
        *n = matr_2->n;
    return EXIT_SUCCESS;
}

int make_equal_size(matrix_t *matrix, size_t n)
{
    if (!matrix || !matrix->data)
        return NULL_POINTER_ERROR;
    if (n == 0)
        return MATRIX_SIZE_ERROR;
    int return_code = EXIT_SUCCESS;
    while (matrix->n < n && return_code == EXIT_SUCCESS)
    {
        return_code = append_string(matrix);
    }
    if (return_code != EXIT_SUCCESS)
        return return_code;
    if (return_code == EXIT_SUCCESS)
        return_code = append_columns(matrix);
    return return_code;
}

int append_columns(matrix_t *matrix)
{
    if (!matrix || !matrix->data)
        return NULL_POINTER_ERROR;
    if (matrix->m == 0 || matrix->n == 0)
        return MATRIX_SIZE_ERROR;
    int min_ind;
    for (size_t i = 0; i < matrix->n; ++i)
    {
        min_ind = 0;
        for (size_t j = 1; j < matrix->m; ++j)
            if (matrix->data[i][j] < matrix->data[i][min_ind])
                min_ind = j;
        for (size_t j = matrix->m; j < matrix->n; ++j)
            matrix->data[i][j] = matrix->data[i][min_ind];
    }
    matrix->m = matrix->n;
    return EXIT_SUCCESS;
}

int append_string(matrix_t *matrix)
{
    if (!matrix || !matrix->data)
        return NULL_POINTER_ERROR;
    if (matrix->m == 0 || matrix->n == 0)
        return MATRIX_SIZE_ERROR;
    int sum;
    for (size_t j = 0; j < matrix->m; ++j)
    {
        sum = 0;
        for (size_t i = 0; i < matrix->n; ++i)
        {
            sum += matrix->data[i][j];
        }
        matrix->data[matrix->n][j] = (int)floor((double)sum / matrix->n);
    }
    matrix->n++;
    return EXIT_SUCCESS;
}

int delete_column(matrix_t *matrix)
{
    if (!matrix || !matrix->data)
        return NULL_POINTER_ERROR;
    if (matrix->m == 0 || matrix->n == 0)
        return MATRIX_SIZE_ERROR;
    size_t ind = find_axis_index(matrix, 1);
    for (size_t i = 0; i < matrix->n; ++i)
    {
        for (size_t j = ind + 1; j < matrix->m; ++j)
        {
            matrix->data[i][j - 1] = matrix->data[i][j];
        }
    }
    matrix->m--;
    return EXIT_SUCCESS;
}

int delete_string(matrix_t *matrix)
{
    if (!matrix || !matrix->data)
        return NULL_POINTER_ERROR;
    if (matrix->m == 0 || matrix->n == 0)
        return MATRIX_SIZE_ERROR;
    size_t ind = find_axis_index(matrix, 0);
    free(matrix->data[ind]);
    for (size_t i = ind + 1; i < matrix->n; ++i)
    {
        matrix->data[i - 1] = matrix->data[i];
    }
    matrix->n--;
    return EXIT_SUCCESS;
}

// 0 - str; 1 - col
static size_t find_axis_index(matrix_t *matrix, bool axis)
{
    size_t col_ind = 0, str_ind = 0;
    for (size_t i = 0; i < matrix->n; ++i)
    {
        for (size_t j = 0; j < matrix->m; ++j)
        {
            if (matrix->data[i][j] >= matrix->data[str_ind][col_ind])
            {
                str_ind = i;
                col_ind = j;
            }
        }
    }
    if (axis)
        return col_ind;
    else
        return str_ind;
}