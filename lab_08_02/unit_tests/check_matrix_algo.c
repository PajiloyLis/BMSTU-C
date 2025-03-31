#include <check.h>
#include "matrix_algo.h"

int read_matrix_from_file(char *filename, matrix_t *matrix);

START_TEST(test_calc_exapnded_size_null_matr_1)
{
    matrix_t matr_2;
    matr_2.n = matr_2.m = 2;
    matr_2.is_allocated = false;
    int rc = allocate_matrix(&matr_2, matr_2.n, matr_2.m);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    size_t n;
    rc = calc_expanded_size(NULL, &matr_2, &n);
    ck_assert_int_eq(rc, NULL_POINTER_ERROR);
    free_matrix(&matr_2);
}
END_TEST

START_TEST(test_calc_exapnded_size_null_matr_2)
{
    matrix_t matr_1;
    matr_1.n = matr_1.m = 2;
    matr_1.is_allocated = false;
    int rc = allocate_matrix(&matr_1, matr_1.n, matr_1.m);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    size_t n;
    rc = calc_expanded_size(&matr_1, NULL, &n);
    ck_assert_int_eq(rc, NULL_POINTER_ERROR);
    free_matrix(&matr_1);
}
END_TEST

START_TEST(test_calc_exapnded_size_null_n_matr_1)
{
    matrix_t matr_2, matr_1;
    matr_1.n = 0;
    matr_1.m = matr_2.n = matr_2.m = 2;
    matr_2.is_allocated = matr_1.is_allocated = false;
    size_t n;
    int rc = calc_expanded_size(&matr_1, &matr_2, &n);
    ck_assert_int_eq(rc, MATRIX_SIZE_ERROR);
}
END_TEST

START_TEST(test_calc_exapnded_size_null_m_matr_1)
{
    matrix_t matr_2, matr_1;
    matr_1.m = 0;
    matr_1.n = matr_2.n = matr_2.m = 2;
    matr_2.is_allocated = matr_1.is_allocated = false;
    size_t n;
    int rc = calc_expanded_size(&matr_1, &matr_2, &n);
    ck_assert_int_eq(rc, MATRIX_SIZE_ERROR);
}
END_TEST

START_TEST(test_calc_exapnded_size_null_n_matr_2)
{
    matrix_t matr_2, matr_1;
    matr_2.n = 0;
    matr_1.m = matr_1.n = matr_2.m = 2;
    matr_2.is_allocated = matr_1.is_allocated = false;
    size_t n;
    int rc = calc_expanded_size(&matr_1, &matr_2, &n);
    ck_assert_int_eq(rc, MATRIX_SIZE_ERROR);
}
END_TEST

START_TEST(test_calc_exapnded_size_null_m_matr_2)
{
    matrix_t matr_2, matr_1;
    matr_2.m = 0;
    matr_1.m = matr_1.n = matr_2.n = 2;
    matr_2.is_allocated = matr_1.is_allocated = false;
    size_t n;
    int rc = calc_expanded_size(&matr_1, &matr_2, &n);
    ck_assert_int_eq(rc, MATRIX_SIZE_ERROR);
}
END_TEST

START_TEST(test_calc_exapnded_size_matr_1_n)
{
    matrix_t matr_2, matr_1;
    matr_1.n = matr_1.m = 3;
    matr_2.n = matr_2.m = 2;
    matr_2.is_allocated = matr_1.is_allocated = false;
    int rc = allocate_matrix(&matr_2, matr_2.n, matr_2.m);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = allocate_matrix(&matr_1, matr_1.n, matr_1.m);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    size_t n;
    rc = calc_expanded_size(&matr_1, &matr_2, &n);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(n, matr_1.n);
    free_matrix(&matr_1);
    free_matrix(&matr_2);
}
END_TEST

START_TEST(test_calc_exapnded_size_matr_2_n)
{
    matrix_t matr_2, matr_1;
    matr_1.n = matr_1.m = 3;
    matr_2.n = matr_2.m = 4;
    matr_2.is_allocated = matr_1.is_allocated = false;
    int rc = allocate_matrix(&matr_2, matr_2.n, matr_2.m);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = allocate_matrix(&matr_1, matr_1.n, matr_1.m);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    size_t n;
    rc = calc_expanded_size(&matr_1, &matr_2, &n);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(n, matr_2.n);
    free_matrix(&matr_1);
    free_matrix(&matr_2);
}
END_TEST

START_TEST(test_make_quadratic_null_pointer)
{
    int rc = make_quadratic(NULL);
    ck_assert_int_eq(rc, NULL_POINTER_ERROR);
}
END_TEST

START_TEST(test_make_quadratic_n_zero)
{
    matrix_t matrix;
    matrix.n = matrix.m = 2;
    matrix.is_allocated = false;
    int rc = allocate_matrix(&matrix, matrix.n, matrix.m);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    matrix.n = 0;
    rc = make_quadratic(&matrix);
    ck_assert_int_eq(rc, MATRIX_SIZE_ERROR);
    matrix.n = 2;
    free_matrix(&matrix);
}
END_TEST

START_TEST(test_make_quadratic_null_data_pointer)
{
    matrix_t matrix;
    matrix.n = matrix.m = 2;
    matrix.is_allocated = false;
    matrix.data = NULL;
    int rc = make_quadratic(&matrix);
    ck_assert_int_eq(rc, NULL_POINTER_ERROR);
}
END_TEST

START_TEST(test_make_quadratic_m_zero)
{
    matrix_t matrix;
    matrix.m = matrix.n = 2;
    matrix.is_allocated = false;
    int rc = allocate_matrix(&matrix, matrix.n, matrix.m);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    matrix.n = 0;
    rc = make_quadratic(&matrix);
    ck_assert_int_eq(rc, MATRIX_SIZE_ERROR);
    matrix.n = 2;
    free_matrix(&matrix);
}
END_TEST

int read_matrix_from_file(char *filename, matrix_t *matrix)
{
    FILE *f = fopen(filename, "r");
    if (!f)
    {
        return EXIT_FAILURE;
    }
    if (fscanf(f, "%zu%zu", &matrix->n, &matrix->m) != 2)
    {
        return EXIT_FAILURE;
    }
    if (allocate_matrix(matrix, matrix->n, matrix->m) != EXIT_SUCCESS)
    {
        return EXIT_FAILURE;
    }
    for (size_t i = 0; i < matrix->n; ++i)
    {
        for (size_t j = 0; j < matrix->m; ++j)
        {
            if (fscanf(f, "%lld", &matrix->data[i][j]) != 1)
            {
                return EXIT_FAILURE;
            }
        }
    }
    fclose(f);
    return EXIT_SUCCESS;
}

START_TEST(test_make_quadratic)
{
    matrix_t matrix;
    matrix.is_allocated = false;
    int rc = read_matrix_from_file("./unit_tests/data/test_make_quadratic_in.txt", &matrix);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    matrix_t ans;
    matrix.is_allocated = false;
    rc = read_matrix_from_file("./unit_tests/data/test_make_quadratic_ans.txt", &ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = make_quadratic(&matrix);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_uint_eq(matrix.n, ans.n);
    ck_assert_uint_eq(matrix.m, ans.m);
    for (size_t i = 0; i < matrix.n; ++i)
    {
        for (size_t j = 0; j < matrix.m; ++j)
        {
            ck_assert_int_eq(matrix.data[i][j], ans.data[i][j]);
        }
    }
    free_matrix(&matrix);
    free_matrix(&ans);
}
END_TEST

START_TEST(test_make_equal_size_null_matrix_pointer)
{
    size_t n = 5;
    int rc = make_equal_size(NULL, n);
    ck_assert_int_eq(rc, NULL_POINTER_ERROR);
}
END_TEST

START_TEST(test_make_equal_size_null_data_pointer)
{
    size_t n = 5;
    matrix_t matrix;
    matrix.n = matrix.m = 5;
    matrix.is_allocated = false;
    matrix.data = NULL;
    int rc = make_equal_size(&matrix, n);
    ck_assert_int_eq(rc, NULL_POINTER_ERROR);
}
END_TEST

START_TEST(test_make_equal_size_zero_n)
{
    size_t n = 0;
    matrix_t matrix;
    matrix.n = matrix.m = 5;
    matrix.is_allocated = false;
    allocate_matrix(&matrix, matrix.n, matrix.m);
    int rc = make_equal_size(&matrix, n);
    ck_assert_int_eq(rc, MATRIX_SIZE_ERROR);
    free_matrix(&matrix);
}
END_TEST

START_TEST(test_make_equal_size)
{
    size_t n = 5;
    matrix_t matrix, ans;
    matrix.is_allocated = ans.is_allocated = false;
    int rc = read_matrix_from_file("./unit_tests/data/test_make_equal_size_in.txt", &matrix);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/test_make_equal_size_ans.txt", &ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = reallocate_matrix(&matrix, n);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = make_equal_size(&matrix, n);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_uint_eq(matrix.n, ans.n);
    ck_assert_uint_eq(matrix.m, ans.m);
    for (size_t i = 0; i < matrix.n; ++i)
    {
        for (size_t j = 0; j < matrix.m; ++j)
        {
            ck_assert_int_eq(matrix.data[i][j], ans.data[i][j]);
        }
    }
    free_matrix(&matrix);
    free_matrix(&ans);
}
END_TEST

START_TEST(test_matrix_multiply_null_matr_1_pointer)
{
    matrix_t matr_2, ans;
    int rc = matrix_multiply(NULL, &matr_2, &ans);
    ck_assert_int_eq(rc, NULL_POINTER_ERROR);
}
END_TEST

START_TEST(test_matrix_multiply_null_matr_2_pointer)
{
    matrix_t matr_1, ans;
    int rc = matrix_multiply(&matr_1, NULL, &ans);
    ck_assert_int_eq(rc, NULL_POINTER_ERROR);
}
END_TEST

START_TEST(test_matrix_multiply_null_ans_pointer)
{
    matrix_t matr_1, matr_2;
    int rc = matrix_multiply(&matr_1, &matr_2, NULL);
    ck_assert_int_eq(rc, NULL_POINTER_ERROR);
}
END_TEST

START_TEST(test_matrix_multiply_null_data_matr_1_pointer)
{
    matrix_t matr_1, matr_2, ans;
    matr_1.n = matr_1.m = 3;
    matr_1.data = NULL;
    int rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_2.txt", &matr_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_ans.txt", &ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = matrix_multiply(&matr_1, &matr_2, &ans);
    ck_assert_int_eq(rc, NULL_POINTER_ERROR);
    free_matrix(&matr_2);
    free_matrix(&ans);
}
END_TEST

START_TEST(test_matrix_multiply_null_data_matr_2_pointer)
{
    matrix_t matr_1, matr_2, ans;
    matr_2.n = matr_2.m = 3;
    matr_2.data = NULL;
    int rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_1.txt", &matr_1);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_ans.txt", &ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = matrix_multiply(&matr_1, &matr_2, &ans);
    ck_assert_int_eq(rc, NULL_POINTER_ERROR);
    free_matrix(&matr_1);
    free_matrix(&ans);
}
END_TEST

START_TEST(test_matrix_multiply_null_data_ans_pointer)
{
    matrix_t matr_1, matr_2, ans;
    ans.n = ans.m = 3;
    ans.data = NULL;
    int rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_1.txt", &matr_1);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_2.txt", &matr_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = matrix_multiply(&matr_1, &matr_2, &ans);
    ck_assert_int_eq(rc, NULL_POINTER_ERROR);
    free_matrix(&matr_1);
    free_matrix(&matr_2);
}
END_TEST

START_TEST(test_matrix_multiply_matr_1_zero_n)
{
    matrix_t matr_1, matr_2, ans;
    int rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_1.txt", &matr_1);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_ans.txt", &ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_2.txt", &matr_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    matr_1.n = 0;
    rc = matrix_multiply(&matr_1, &matr_2, &ans);
    ck_assert_int_eq(rc, MATRIX_SIZE_ERROR);
    matr_1.n = matr_1.m;
    free_matrix(&matr_1);
    free_matrix(&matr_2);
    free_matrix(&ans);
}
END_TEST

START_TEST(test_matrix_multiply_matr_1_zero_m)
{
    matrix_t matr_1, matr_2, ans;
    int rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_1.txt", &matr_1);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_ans.txt", &ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_2.txt", &matr_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    matr_1.m = 0;
    rc = matrix_multiply(&matr_1, &matr_2, &ans);
    ck_assert_int_eq(rc, MATRIX_SIZE_ERROR);
    free_matrix(&matr_1);
    free_matrix(&matr_2);
    free_matrix(&ans);
}
END_TEST

START_TEST(test_matrix_multiply_matr_2_zero_n)
{
    matrix_t matr_1, matr_2, ans;
    int rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_1.txt", &matr_1);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_ans.txt", &ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_2.txt", &matr_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    matr_2.n = 0;
    rc = matrix_multiply(&matr_1, &matr_2, &ans);
    ck_assert_int_eq(rc, MATRIX_SIZE_ERROR);
    matr_2.n = matr_2.m;
    free_matrix(&matr_1);
    free_matrix(&matr_2);
    free_matrix(&ans);
}
END_TEST

START_TEST(test_matrix_multiply_matr_2_zero_m)
{
    matrix_t matr_1, matr_2, ans;
    int rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_1.txt", &matr_1);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_ans.txt", &ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_2.txt", &matr_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    matr_2.m = 0;
    rc = matrix_multiply(&matr_1, &matr_2, &ans);
    ck_assert_int_eq(rc, MATRIX_SIZE_ERROR);
    free_matrix(&matr_1);
    free_matrix(&matr_2);
    free_matrix(&ans);
}
END_TEST

START_TEST(test_matrix_multiply_ans_zero_n)
{
    matrix_t matr_1, matr_2, ans;
    int rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_1.txt", &matr_1);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_ans.txt", &ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_2.txt", &matr_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ans.n = 0;
    rc = matrix_multiply(&matr_1, &matr_2, &ans);
    ck_assert_int_eq(rc, MATRIX_SIZE_ERROR);
    ans.n = ans.m;
    free_matrix(&matr_1);
    free_matrix(&matr_2);
    free_matrix(&ans);
}
END_TEST

START_TEST(test_matrix_multiply_ans_zero_m)
{
    matrix_t matr_1, matr_2, ans;
    int rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_1.txt", &matr_1);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_ans.txt", &ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_2.txt", &matr_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ans.m = 0;
    rc = matrix_multiply(&matr_1, &matr_2, &ans);
    ck_assert_int_eq(rc, MATRIX_SIZE_ERROR);
    free_matrix(&matr_1);
    free_matrix(&matr_2);
    free_matrix(&ans);
}
END_TEST

START_TEST(test_matrix_multiply)
{
    matrix_t matr_1, matr_2, real_ans, ans;
    int rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_1.txt", &matr_1);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_ans.txt", &real_ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_2.txt", &matr_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ans.n = ans.m = matr_1.n;
    ans.is_allocated = false;
    rc = allocate_matrix(&ans, ans.n, ans.m);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = matrix_multiply(&matr_1, &matr_2, &ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(ans.n, real_ans.n);
    ck_assert_uint_eq(ans.m, real_ans.n);
    for (size_t i = 0; i < ans.n; ++i)
    {
        for (size_t j = 0; j < ans.m; ++j)
        {
            ck_assert_int_eq(ans.data[i][j], real_ans.data[i][j]);
        }
    }
    free_matrix(&matr_1);
    free_matrix(&matr_2);
    free_matrix(&real_ans);
    free_matrix(&ans);
}
END_TEST

START_TEST(test_matrix_pow_null_matrix_pointer)
{
    matrix_t ans;
    long long n = 1;
    int rc = matrix_pow(NULL, n, &ans);
    ck_assert_int_eq(rc, NULL_POINTER_ERROR);
}
END_TEST

START_TEST(test_matrix_pow_null_ans_pointer)
{
    matrix_t matrix;
    long long n = 1;
    int rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_1.txt", &matrix);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = matrix_pow(&matrix, n, NULL);
    ck_assert_int_eq(rc, NULL_POINTER_ERROR);
    free_matrix(&matrix);
}
END_TEST

START_TEST(test_matrix_pow_null_data_matrix_pointer)
{
    matrix_t matrix, ans;
    long long n = 1;
    matrix.n = matrix.m = 3;
    matrix.is_allocated = false;
    matrix.data = NULL;
    int rc = matrix_pow(&matrix, n, &ans);
    ck_assert_int_eq(rc, NULL_POINTER_ERROR);
}
END_TEST

START_TEST(test_matrix_pow_null_data_ans_pointer)
{
    matrix_t matrix, ans;
    long long n = 1;
    ans.n = ans.m = 3;
    ans.is_allocated = false;
    ans.data = NULL;
    int rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_1.txt", &matrix);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = matrix_pow(&matrix, n, &ans);
    ck_assert_int_eq(rc, NULL_POINTER_ERROR);
    free_matrix(&matrix);
}
END_TEST

START_TEST(test_matrix_pow_matrix_n_zero)
{
    matrix_t matrix, ans;
    long long n = 1;
    int rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_1.txt", &matrix);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/test_matrix_pow_ans.txt", &ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    matrix.n = 0;
    rc = matrix_pow(&matrix, n, &ans);
    ck_assert_int_eq(rc, MATRIX_SIZE_ERROR);
    matrix.n = matrix.m;
    free_matrix(&matrix);
    free_matrix(&ans);
}
END_TEST

START_TEST(test_matrix_pow_matrix_m_zero)
{
    matrix_t matrix, ans;
    long long n = 1;
    int rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_1.txt", &matrix);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/test_matrix_pow_ans.txt", &ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    matrix.m = 0;
    rc = matrix_pow(&matrix, n, &ans);
    ck_assert_int_eq(rc, MATRIX_SIZE_ERROR);
    free_matrix(&matrix);
    free_matrix(&ans);
}
END_TEST

START_TEST(test_matrix_pow_ans_n_zero)
{
    matrix_t matrix, ans;
    long long n = 1;
    int rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_1.txt", &matrix);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/test_matrix_pow_ans.txt", &ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ans.n = 0;
    rc = matrix_pow(&matrix, n, &ans);
    ck_assert_int_eq(rc, MATRIX_SIZE_ERROR);
    ans.n = ans.m;
    free_matrix(&matrix);
    free_matrix(&ans);
}
END_TEST

START_TEST(test_matrix_pow_ans_m_zero)
{
    matrix_t matrix, ans;
    long long n = 1;
    int rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_1.txt", &matrix);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/test_matrix_pow_ans.txt", &ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ans.m = 0;
    rc = matrix_pow(&matrix, n, &ans);
    ck_assert_int_eq(rc, MATRIX_SIZE_ERROR);
    free_matrix(&matrix);
    free_matrix(&ans);
}
END_TEST

START_TEST(test_matrix_pow_matrix_negative_pow)
{
    matrix_t matrix, ans;
    long long n = -1;
    int rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_1.txt", &matrix);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/test_matrix_pow_ans.txt", &ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = matrix_pow(&matrix, n, &ans);
    ck_assert_int_eq(rc, NEGATIVE_POW_ERROR);
    free_matrix(&matrix);
    free_matrix(&ans);
}
END_TEST

START_TEST(test_matrix_pow_cube)
{
    matrix_t matrix, real_ans, ans;
    long long n = 3;
    int rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_1.txt", &matrix);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/test_matrix_pow_ans.txt", &real_ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ans.n = ans.m = matrix.n;
    rc = allocate_matrix(&ans, ans.n, ans.m);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = matrix_pow(&matrix, n, &ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_uint_eq(ans.n, real_ans.n);
    ck_assert_uint_eq(ans.m, real_ans.m);
    for (size_t i = 0; i < ans.n; ++i)
    {
        for (size_t j = 0; j < ans.m; ++j)
        {
            ck_assert_int_eq(ans.data[i][j], real_ans.data[i][j]);
        }
    }
    free_matrix(&matrix);
    free_matrix(&ans);
    free_matrix(&real_ans);
}
END_TEST

START_TEST(test_matrix_pow_first)
{
    matrix_t matrix, real_ans, ans;
    long long n = 1;
    int rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_1.txt", &matrix);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_1.txt", &real_ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ans.n = ans.m = matrix.n;
    rc = allocate_matrix(&ans, ans.n, ans.m);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = matrix_pow(&matrix, n, &ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_uint_eq(ans.n, real_ans.n);
    ck_assert_uint_eq(ans.m, real_ans.m);
    for (size_t i = 0; i < ans.n; ++i)
    {
        for (size_t j = 0; j < ans.m; ++j)
        {
            ck_assert_int_eq(ans.data[i][j], real_ans.data[i][j]);
        }
    }
    free_matrix(&matrix);
    free_matrix(&ans);
    free_matrix(&real_ans);
}
END_TEST

START_TEST(test_matrix_pow_zero)
{
    matrix_t matrix, real_ans, ans;
    long long n = 0;
    int rc = read_matrix_from_file("./unit_tests/data/test_matrix_multiply_in_1.txt", &matrix);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = read_matrix_from_file("./unit_tests/data/identity_matrix.txt", &real_ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ans.n = ans.m = matrix.n;
    rc = allocate_matrix(&ans, ans.n, ans.m);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    rc = matrix_pow(&matrix, n, &ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_uint_eq(ans.n, real_ans.n);
    ck_assert_uint_eq(ans.m, real_ans.m);
    for (size_t i = 0; i < ans.n; ++i)
    {
        for (size_t j = 0; j < ans.m; ++j)
        {
            ck_assert_int_eq(ans.data[i][j], real_ans.data[i][j]);
        }
    }
    free_matrix(&matrix);
    free_matrix(&ans);
    free_matrix(&real_ans);
}
END_TEST

Suite *matrix_algo_suite(void)
{
    Suite *s;
    TCase *tc_neg, *tc_pos;

    s = suite_create("matrix_algo");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_calc_exapnded_size_null_matr_1);
    tcase_add_test(tc_neg, test_calc_exapnded_size_null_matr_2);
    tcase_add_test(tc_neg, test_calc_exapnded_size_null_n_matr_1);
    tcase_add_test(tc_neg, test_calc_exapnded_size_null_m_matr_1);
    tcase_add_test(tc_neg, test_calc_exapnded_size_null_n_matr_2);
    tcase_add_test(tc_neg, test_calc_exapnded_size_null_m_matr_2);
    tcase_add_test(tc_neg, test_make_quadratic_null_pointer);
    tcase_add_test(tc_neg, test_make_quadratic_n_zero);
    tcase_add_test(tc_neg, test_make_quadratic_m_zero);
    tcase_add_test(tc_neg, test_make_quadratic_null_data_pointer);
    tcase_add_test(tc_neg, test_make_equal_size_null_matrix_pointer);
    tcase_add_test(tc_neg, test_make_equal_size_null_data_pointer);
    tcase_add_test(tc_neg, test_make_equal_size_zero_n);
    tcase_add_test(tc_neg, test_matrix_multiply_null_matr_1_pointer);
    tcase_add_test(tc_neg, test_matrix_multiply_null_matr_2_pointer);
    tcase_add_test(tc_neg, test_matrix_multiply_null_ans_pointer);
    tcase_add_test(tc_neg, test_matrix_multiply_null_data_matr_1_pointer);
    tcase_add_test(tc_neg, test_matrix_multiply_null_data_matr_2_pointer);
    tcase_add_test(tc_neg, test_matrix_multiply_null_data_ans_pointer);
    tcase_add_test(tc_neg, test_matrix_multiply_matr_1_zero_n);
    tcase_add_test(tc_neg, test_matrix_multiply_matr_1_zero_m);
    tcase_add_test(tc_neg, test_matrix_multiply_matr_2_zero_n);
    tcase_add_test(tc_neg, test_matrix_multiply_matr_2_zero_m);
    tcase_add_test(tc_neg, test_matrix_multiply_ans_zero_n);
    tcase_add_test(tc_neg, test_matrix_multiply_ans_zero_m);
    tcase_add_test(tc_neg, test_matrix_multiply);
    tcase_add_test(tc_neg, test_matrix_pow_null_matrix_pointer);
    tcase_add_test(tc_neg, test_matrix_pow_null_ans_pointer);
    tcase_add_test(tc_neg, test_matrix_pow_null_data_matrix_pointer);
    tcase_add_test(tc_neg, test_matrix_pow_null_data_ans_pointer);
    tcase_add_test(tc_neg, test_matrix_pow_matrix_n_zero);
    tcase_add_test(tc_neg, test_matrix_pow_matrix_m_zero);
    tcase_add_test(tc_neg, test_matrix_pow_ans_n_zero);
    tcase_add_test(tc_neg, test_matrix_pow_ans_m_zero);
    tcase_add_test(tc_neg, test_matrix_pow_matrix_negative_pow);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_calc_exapnded_size_matr_1_n);
    tcase_add_test(tc_pos, test_calc_exapnded_size_matr_2_n);
    tcase_add_test(tc_pos, test_make_quadratic);
    tcase_add_test(tc_pos, test_make_equal_size);
    tcase_add_test(tc_pos, test_matrix_pow_cube);
    tcase_add_test(tc_pos, test_matrix_pow_first);
    tcase_add_test(tc_pos, test_matrix_pow_zero);

    suite_add_tcase(s, tc_neg);
    suite_add_tcase(s, tc_pos);
    return s;
}