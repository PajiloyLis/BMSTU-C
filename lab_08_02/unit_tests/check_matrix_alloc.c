#include "matrix_alloc.h"
#include <limits.h>
#include <check.h>

START_TEST(test_allocate_matrix_null_pointer)
{
    int rc = allocate_matrix(NULL, 5, 5);
    ck_assert_int_eq(rc, NULL_POINTER_ERROR);
}
END_TEST

START_TEST(test_allocate_matrix_null_str_cnt)
{
    matrix_t matrix;
    matrix.n = 0;
    matrix.m = 1;
    matrix.is_allocated = false;
    int rc = allocate_matrix(&matrix, matrix.n, matrix.m);
    ck_assert_int_eq(rc, MATRIX_SIZE_ERROR);
}
END_TEST

START_TEST(test_allocate_matrix_null_col_cnt)
{
    matrix_t matrix;
    matrix.n = 1;
    matrix.m = 0;
    matrix.is_allocated = false;
    int rc = allocate_matrix(&matrix, matrix.n, matrix.m);
    ck_assert_int_eq(rc, MATRIX_SIZE_ERROR);
}
END_TEST

START_TEST(test_allocate_matrix_minimal)
{
    matrix_t matrix;
    matrix.m = 1;
    matrix.n = 1;
    matrix.is_allocated = false;
    int rc = allocate_matrix(&matrix, matrix.n, matrix.m);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    free_matrix(&matrix);
}
END_TEST

START_TEST(test_allocate_matrix)
{
    matrix_t matrix;
    matrix.m = 10000;
    matrix.n = 10000;
    matrix.is_allocated = false;
    int rc = allocate_matrix(&matrix, matrix.n, matrix.m);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    free_matrix(&matrix);
}
END_TEST

START_TEST(test_reallocate_matrix_null_pointer)
{
    size_t n = 10;
    int rc = reallocate_matrix(NULL, n);
    ck_assert_int_eq(rc, NULL_POINTER_ERROR);
}
END_TEST

START_TEST(test_reallocate_matrix_null_new_cnt)
{
    matrix_t matrix;
    size_t n = 0;
    int rc = reallocate_matrix(&matrix, n);
    ck_assert_int_eq(rc, MATRIX_SIZE_ERROR);
}
END_TEST

START_TEST(test_reallocate_matrix)
{
    matrix_t matrix;
    matrix.n = matrix.m = 1;
    int rc = allocate_matrix(&matrix, matrix.n, matrix.m);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    size_t n = 5;
    rc = reallocate_matrix(&matrix, n);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    matrix.n = n;
    free_matrix(&matrix);
}
END_TEST

Suite *matrix_alloc_suite(void)
{
    Suite *s;
    TCase *tc_neg, *tc_pos;

    s = suite_create("matrix_algo");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_allocate_matrix_null_pointer);
    tcase_add_test(tc_neg, test_allocate_matrix_null_str_cnt);
    tcase_add_test(tc_neg, test_allocate_matrix_null_col_cnt);
    tcase_add_test(tc_neg, test_reallocate_matrix_null_pointer);
    tcase_add_test(tc_neg, test_reallocate_matrix_null_new_cnt);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_allocate_matrix);
    tcase_add_test(tc_pos, test_allocate_matrix_minimal);
    tcase_add_test(tc_pos, test_reallocate_matrix);

    suite_add_tcase(s, tc_neg);
    suite_add_tcase(s, tc_pos);
    return s;
}