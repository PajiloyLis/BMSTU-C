#include <check.h>
#include "list.h"

void list_fill_with_values(node_t *list, int *array, size_t n)
{
    for (size_t i = 0; i < n && list; ++i, list = list->next)
        list->val = array[i];
}

void calc_x_pows(long long *array, size_t n, int x)
{
    array[0] = 1;
    for (size_t i = 1; i < n; ++i)
    {
        array[i] = x;
        if (i)
            array[i] *= array[i - 1];
    }
}

START_TEST(test_calc_calue_list_null)
{
    int x = 1;
    size_t n = 5;
    long long x_pows[n];
    calc_x_pows(x_pows, n, x);
    long long ans;
    int rc = calc_value_by_x(NULL, x_pows, n, &ans);
    ck_assert_int_eq(rc, CALC_VALUE_ARGS_ERROR);
}
END_TEST

START_TEST(test_calc_value_size_null)
{
    int array[] = {1, 2, 3, 4, 5};
    int x = 1;
    size_t n = sizeof(array) / sizeof(array[0]);
    long long x_pows[n];
    calc_x_pows(x_pows, n, x);
    long long ans;
    node_t *coefs = list_allocate(n);
    ck_assert_ptr_nonnull(coefs);
    list_fill_with_values(coefs, array, n);
    n = 0;
    int rc = calc_value_by_x(coefs, x_pows, n, &ans);
    ck_assert_int_eq(rc, CALC_VALUE_ARGS_ERROR);
    list_free(coefs);
}
END_TEST

START_TEST(test_calc_value_pows_null)
{
    int array[] = {1, 2, 3, 4, 5};
    size_t n = sizeof(array) / sizeof(array[0]);
    long long ans;
    node_t *coefs = list_allocate(n);
    ck_assert_ptr_nonnull(coefs);
    list_fill_with_values(coefs, array, n);
    int rc = calc_value_by_x(coefs, NULL, n, &ans);
    ck_assert_int_eq(rc, CALC_VALUE_ARGS_ERROR);
    list_free(coefs);
}
END_TEST

START_TEST(test_calc_value_ans_null)
{
    int array[] = {1, 2, 3, 4, 5};
    int x = 1;
    size_t n = sizeof(array) / sizeof(array[0]);
    long long x_pows[n];
    calc_x_pows(x_pows, n, x);
    node_t *coefs = list_allocate(n);
    ck_assert_ptr_nonnull(coefs);
    list_fill_with_values(coefs, array, n);
    int rc = calc_value_by_x(coefs, x_pows, n, NULL);
    ck_assert_int_eq(rc, CALC_VALUE_ARGS_ERROR);
    list_free(coefs);
}
END_TEST

START_TEST(test_calc_value_one_coef)
{
    int array[] = {1};
    int x = 1;
    size_t n = sizeof(array) / sizeof(array[0]);
    long long x_pows[n];
    calc_x_pows(x_pows, n, x);
    long long ans = 0;
    node_t *coefs = list_allocate(n);
    ck_assert_ptr_nonnull(coefs);
    list_fill_with_values(coefs, array, n);
    int rc = calc_value_by_x(coefs, x_pows, n, &ans);
    long long right_ans = 1;
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(ans, right_ans);
    list_free(coefs);
}
END_TEST

START_TEST(test_calc_value_one_nonnull_coef)
{
    int array[] = {0, 0, 0, 0, 1};
    int x = 15;
    size_t n = sizeof(array) / sizeof(array[0]);
    long long x_pows[n];
    calc_x_pows(x_pows, n, x);
    long long ans = 0;
    node_t *coefs = list_allocate(n);
    ck_assert_ptr_nonnull(coefs);
    list_fill_with_values(coefs, array, n);
    int rc = calc_value_by_x(coefs, x_pows, n, &ans);
    long long right_ans = 1;
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(ans, right_ans);
    list_free(coefs);
}
END_TEST

START_TEST(test_calc_value_many_coefs)
{
    int array[] = {1, 2, 3, 4, 1};
    int x = 2;
    size_t n = sizeof(array) / sizeof(array[0]);
    long long x_pows[n];
    calc_x_pows(x_pows, n, x);
    long long ans = 0;
    node_t *coefs = list_allocate(n);
    ck_assert_ptr_nonnull(coefs);
    list_fill_with_values(coefs, array, n);
    int rc = calc_value_by_x(coefs, x_pows, n, &ans);
    long long right_ans = 1 * 16 + 2 * 8 + 3 * 4 + 4 * 2 + 1;
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(ans, right_ans);
    list_free(coefs);
}
END_TEST

START_TEST(test_calc_derivative_coefs_null)
{
    int array[] = {1, 2, 3, 4, 1};
    size_t n = sizeof(array) / sizeof(array[0]);
    node_t *derivative = list_allocate(n - 1);
    ck_assert_ptr_nonnull(derivative);
    int rc = calc_derivative(NULL, derivative, n);
    ck_assert_int_eq(rc, CALC_DERIVATIVE_ARGS_ERROR);
    list_free(derivative);
}
END_TEST

START_TEST(test_calc_derivative_derivative_null)
{
    int array[] = {1, 2, 3, 4, 1};
    size_t n = sizeof(array) / sizeof(array[0]);
    node_t *coefs = list_allocate(n);
    ck_assert_ptr_nonnull(coefs);
    list_fill_with_values(coefs, array, n);
    int rc = calc_derivative(coefs, NULL, n);
    ck_assert_int_eq(rc, CALC_DERIVATIVE_ARGS_ERROR);
    list_free(coefs);
}
END_TEST

START_TEST(test_calc_derivative_null_n)
{
    int array[] = {1, 2, 3, 4, 1};
    size_t n = sizeof(array) / sizeof(array[0]);
    node_t *derivative = list_allocate(n - 1), *coefs = list_allocate(n);
    ck_assert_ptr_nonnull(derivative);
    ck_assert_ptr_nonnull(coefs);
    list_fill_with_values(coefs, array, n);
    n = 0;
    int rc = calc_derivative(coefs, derivative, n);
    ck_assert_int_eq(rc, CALC_DERIVATIVE_ARGS_ERROR);
    list_free(coefs);
    list_free(derivative);
}
END_TEST

START_TEST(test_calc_derivative_empty_derivative)
{
    int array[] = {123};
    size_t n = sizeof(array) / sizeof(array[0]);
    node_t *derivative = list_allocate(n - 1), *coefs = list_allocate(n);
    ck_assert_ptr_null(derivative);
    ck_assert_ptr_nonnull(coefs);
    list_fill_with_values(coefs, array, n);
    int rc = calc_derivative(coefs, derivative, n);
    ck_assert_int_eq(rc, EMPTY_DERIVATIVE_ERROR);
    list_free(coefs);
}
END_TEST

START_TEST(test_calc_derivative_min_elems)
{
    int array[] = {123, 321};
    int derivative_array[] = {123};
    size_t n = sizeof(array) / sizeof(array[0]);
    node_t *derivative = list_allocate(n - 1), *coefs = list_allocate(n), *true_derivative = list_allocate(n - 1);
    ck_assert_ptr_nonnull(derivative);
    ck_assert_ptr_nonnull(coefs);
    ck_assert_ptr_nonnull(true_derivative);
    list_fill_with_values(coefs, array, n);
    list_fill_with_values(true_derivative, derivative_array, sizeof(derivative_array) / sizeof(derivative_array[0]));
    int rc = calc_derivative(coefs, derivative, n);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    node_t *derivative_copy = derivative, *true_derivative_copy = true_derivative;
    for (; derivative && true_derivative; derivative = derivative->next, true_derivative = true_derivative->next)
    {
        ck_assert_int_eq(derivative->val, true_derivative->val);
    }
    ck_assert_ptr_null(derivative);
    ck_assert_ptr_null(true_derivative);
    list_free(derivative_copy);
    list_free(true_derivative_copy);
    list_free(coefs);
}
END_TEST

START_TEST(test_calc_derivative_many_elems)
{
    int array[] = {3, 4, 5, 4, 5};
    int derivative_array[] = {12, 12, 10, 4};
    size_t n = sizeof(array) / sizeof(array[0]);
    node_t *derivative = list_allocate(n - 1), *coefs = list_allocate(n), *true_derivative = list_allocate(n - 1);
    ck_assert_ptr_nonnull(derivative);
    ck_assert_ptr_nonnull(coefs);
    ck_assert_ptr_nonnull(true_derivative);
    list_fill_with_values(coefs, array, n);
    list_fill_with_values(true_derivative, derivative_array, sizeof(derivative_array) / sizeof(derivative_array[0]));
    int rc = calc_derivative(coefs, derivative, n);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    node_t *derivative_copy = derivative, *true_derivative_copy = true_derivative;
    for (; derivative && true_derivative; derivative = derivative->next, true_derivative = true_derivative->next)
    {
        ck_assert_int_eq(derivative->val, true_derivative->val);
    }
    ck_assert_ptr_null(derivative);
    ck_assert_ptr_null(true_derivative);
    list_free(derivative_copy);
    list_free(true_derivative_copy);
    list_free(coefs);
}
END_TEST

START_TEST(test_calc_coef_sum_coefs_1_null)
{
    int array_2[] = {3, 4, 5, 4, 5};
    size_t n_2 = sizeof(array_2) / sizeof(array_2[0]), n_1 = 5;
    node_t *coefs_2 = list_allocate(n_2), *ans = list_allocate(n_2 > n_1 ? n_2 : n_1);
    ck_assert_ptr_nonnull(coefs_2);
    ck_assert_ptr_nonnull(ans);
    list_fill_with_values(coefs_2, array_2, n_2);
    int rc = calc_coef_sum(NULL, n_1, coefs_2, n_2, ans);
    ck_assert_int_eq(rc, CALC_SUM_ARGS_ERROR);
    list_free(ans);
    list_free(coefs_2);
}
END_TEST

START_TEST(test_calc_coef_sum_coefs_2_null)
{
    int array_1[] = {3, 4, 5, 4, 5};
    size_t n_1 = sizeof(array_1) / sizeof(array_1[0]), n_2 = 5;
    node_t *coefs_1 = list_allocate(n_1), *ans = list_allocate(n_1 > n_2 ? n_1 : n_2);
    ck_assert_ptr_nonnull(coefs_1);
    ck_assert_ptr_nonnull(ans);
    list_fill_with_values(coefs_1, array_1, n_1);
    int rc = calc_coef_sum(coefs_1, n_1, NULL, n_2, ans);
    ck_assert_int_eq(rc, CALC_SUM_ARGS_ERROR);
    list_free(ans);
    list_free(coefs_1);
}
END_TEST

START_TEST(test_calc_coef_sum_n_1_null)
{
    int array_1[] = {3, 4, 5, 4, 5};
    int array_2[] = {5, 4, 3, 2, 1};
    size_t n_1 = sizeof(array_1) / sizeof(array_1[0]), n_2 = sizeof(array_2) / sizeof(array_2[0]);
    node_t *coefs_1 = list_allocate(n_1), *coefs_2 = list_allocate(n_2), *ans = list_allocate(n_1 > n_2 ? n_1 : n_2);
    ck_assert_ptr_nonnull(coefs_1);
    ck_assert_ptr_nonnull(coefs_2);
    ck_assert_ptr_nonnull(ans);
    list_fill_with_values(coefs_1, array_1, n_1);
    list_fill_with_values(coefs_2, array_2, n_2);
    n_1 = 0;
    int rc = calc_coef_sum(coefs_1, n_1, coefs_2, n_2, ans);
    ck_assert_int_eq(rc, CALC_SUM_ARGS_ERROR);
    list_free(ans);
    list_free(coefs_1);
    list_free(coefs_2);
}
END_TEST

START_TEST(test_calc_coef_sum_n_2_null)
{
    int array_1[] = {3, 4, 5, 4, 5};
    int array_2[] = {5, 4, 3, 2, 1};
    size_t n_1 = sizeof(array_1) / sizeof(array_1[0]), n_2 = sizeof(array_2) / sizeof(array_2[0]);
    node_t *coefs_1 = list_allocate(n_1), *coefs_2 = list_allocate(n_2), *ans = list_allocate(n_1 > n_2 ? n_1 : n_2);
    ck_assert_ptr_nonnull(coefs_1);
    ck_assert_ptr_nonnull(coefs_2);
    ck_assert_ptr_nonnull(ans);
    list_fill_with_values(coefs_1, array_1, n_1);
    list_fill_with_values(coefs_2, array_2, n_2);
    n_2 = 0;
    int rc = calc_coef_sum(coefs_1, n_1, coefs_2, n_2, ans);
    ck_assert_int_eq(rc, CALC_SUM_ARGS_ERROR);
    list_free(ans);
    list_free(coefs_1);
    list_free(coefs_2);
}
END_TEST

START_TEST(test_calc_coef_sum_ans_null)
{
    int array_1[] = {3, 4, 5, 4, 5};
    int array_2[] = {5, 4, 3, 2, 1};
    size_t n_1 = sizeof(array_1) / sizeof(array_1[0]), n_2 = sizeof(array_2) / sizeof(array_2[0]);
    node_t *coefs_1 = list_allocate(n_1), *coefs_2 = list_allocate(n_2);
    ck_assert_ptr_nonnull(coefs_1);
    ck_assert_ptr_nonnull(coefs_2);
    list_fill_with_values(coefs_1, array_1, n_1);
    list_fill_with_values(coefs_2, array_2, n_2);
    int rc = calc_coef_sum(coefs_1, n_1, coefs_2, n_2, NULL);
    ck_assert_int_eq(rc, CALC_SUM_ARGS_ERROR);
    list_free(coefs_1);
    list_free(coefs_2);
}
END_TEST

START_TEST(test_calc_coef_sum_min_elems)
{
    int array_1[] = {1};
    int array_2[] = {1};
    int array_ans[] = {2};
    size_t n_1 = sizeof(array_1) / sizeof(array_1[0]), n_2 = sizeof(array_2) / sizeof(array_2[0]), n_ans = sizeof(array_ans) / sizeof(array_ans[0]);
    node_t *coefs_1 = list_allocate(n_1), *coefs_2 = list_allocate(n_2), *ans = list_allocate(n_1 > n_2 ? n_1 : n_2), *true_ans = list_allocate(n_ans);
    ck_assert_ptr_nonnull(coefs_1);
    ck_assert_ptr_nonnull(coefs_2);
    ck_assert_ptr_nonnull(ans);
    ck_assert_ptr_nonnull(true_ans);
    list_fill_with_values(coefs_1, array_1, n_1);
    list_fill_with_values(coefs_2, array_2, n_2);
    list_fill_with_values(true_ans, array_ans, n_ans);
    int rc = calc_coef_sum(coefs_1, n_1, coefs_2, n_2, ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    node_t *copy_ans = ans, *copy_true_ans = true_ans;
    for (; ans && true_ans; ans = ans->next, true_ans = true_ans->next)
        ck_assert_int_eq(ans->val, true_ans->val);
    ck_assert_ptr_null(ans);
    ck_assert_ptr_null(true_ans);
    list_free(copy_ans);
    list_free(coefs_1);
    list_free(coefs_2);
    list_free(copy_true_ans);
}
END_TEST

START_TEST(test_calc_coef_sum_many_elems)
{
    int array_1[] = {1, 2, 3, 4, 5, 6, 6, 5, 4, 3, 2, 1};
    int array_2[] = {6, 5, 4, 3, 2, 1, 1, 2, 3, 4, 5, 6};
    int array_ans[] = {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7};
    size_t n_1 = sizeof(array_1) / sizeof(array_1[0]), n_2 = sizeof(array_2) / sizeof(array_2[0]), n_ans = sizeof(array_ans) / sizeof(array_ans[0]);
    node_t *coefs_1 = list_allocate(n_1), *coefs_2 = list_allocate(n_2), *ans = list_allocate(n_1 > n_2 ? n_1 : n_2), *true_ans = list_allocate(n_ans);
    ck_assert_ptr_nonnull(coefs_1);
    ck_assert_ptr_nonnull(coefs_2);
    ck_assert_ptr_nonnull(ans);
    ck_assert_ptr_nonnull(true_ans);
    list_fill_with_values(coefs_1, array_1, n_1);
    list_fill_with_values(coefs_2, array_2, n_2);
    list_fill_with_values(true_ans, array_ans, n_ans);
    int rc = calc_coef_sum(coefs_1, n_1, coefs_2, n_2, ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    node_t *copy_ans = ans, *copy_true_ans = true_ans;
    for (; ans && true_ans; ans = ans->next, true_ans = true_ans->next)
        ck_assert_int_eq(ans->val, true_ans->val);
    ck_assert_ptr_null(ans);
    ck_assert_ptr_null(true_ans);
    list_free(copy_ans);
    list_free(coefs_1);
    list_free(coefs_2);
    list_free(copy_true_ans);
}
END_TEST

START_TEST(test_calc_coef_sum_different_elems_cnt_1)
{
    int array_1[] = {1};
    int array_2[] = {6, 5, 4, 3, 2, 1, 1, 2, 3, 4, 5, 6};
    int array_ans[] = {6, 5, 4, 3, 2, 1, 1, 2, 3, 4, 5, 7};
    size_t n_1 = sizeof(array_1) / sizeof(array_1[0]), n_2 = sizeof(array_2) / sizeof(array_2[0]), n_ans = sizeof(array_ans) / sizeof(array_ans[0]);
    node_t *coefs_1 = list_allocate(n_1), *coefs_2 = list_allocate(n_2), *ans = list_allocate(n_1 > n_2 ? n_1 : n_2), *true_ans = list_allocate(n_ans);
    ck_assert_ptr_nonnull(coefs_1);
    ck_assert_ptr_nonnull(coefs_2);
    ck_assert_ptr_nonnull(ans);
    ck_assert_ptr_nonnull(true_ans);
    list_fill_with_values(coefs_1, array_1, n_1);
    list_fill_with_values(coefs_2, array_2, n_2);
    list_fill_with_values(true_ans, array_ans, n_ans);
    int rc = calc_coef_sum(coefs_1, n_1, coefs_2, n_2, ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    node_t *copy_ans = ans, *copy_true_ans = true_ans;
    for (; ans && true_ans; ans = ans->next, true_ans = true_ans->next)
        ck_assert_int_eq(ans->val, true_ans->val);
    ck_assert_ptr_null(ans);
    ck_assert_ptr_null(true_ans);
    list_free(copy_ans);
    list_free(coefs_1);
    list_free(coefs_2);
    list_free(copy_true_ans);
}
END_TEST

START_TEST(test_calc_coef_sum_different_elems_cnt_2)
{
    int array_1[] = {1, 9, 2, 8, 3, 7, 4, 6, 5};
    int array_2[] = {123};
    int array_ans[] = {1, 9, 2, 8, 3, 7, 4, 6, 128};
    size_t n_1 = sizeof(array_1) / sizeof(array_1[0]), n_2 = sizeof(array_2) / sizeof(array_2[0]), n_ans = sizeof(array_ans) / sizeof(array_ans[0]);
    node_t *coefs_1 = list_allocate(n_1), *coefs_2 = list_allocate(n_2), *ans = list_allocate(n_1 > n_2 ? n_1 : n_2), *true_ans = list_allocate(n_ans);
    ck_assert_ptr_nonnull(coefs_1);
    ck_assert_ptr_nonnull(coefs_2);
    ck_assert_ptr_nonnull(ans);
    ck_assert_ptr_nonnull(true_ans);
    list_fill_with_values(coefs_1, array_1, n_1);
    list_fill_with_values(coefs_2, array_2, n_2);
    list_fill_with_values(true_ans, array_ans, n_ans);
    int rc = calc_coef_sum(coefs_1, n_1, coefs_2, n_2, ans);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    node_t *copy_ans = ans, *copy_true_ans = true_ans;
    for (; ans && true_ans; ans = ans->next, true_ans = true_ans->next)
        ck_assert_int_eq(ans->val, true_ans->val);
    ck_assert_ptr_null(ans);
    ck_assert_ptr_null(true_ans);
    list_free(copy_ans);
    list_free(coefs_1);
    list_free(coefs_2);
    list_free(copy_true_ans);
}
END_TEST

START_TEST(test_split_coefs_by_partity_null_coefs)
{
    size_t n = 6;
    node_t *even_coefs = list_allocate(n / 2 + n % 2), *odd_coefs = list_allocate(n / 2);
    ck_assert_ptr_nonnull(even_coefs);
    ck_assert_ptr_nonnull(odd_coefs);
    int rc = split_coefs_by_parity(NULL, n, even_coefs, odd_coefs);
    ck_assert_int_eq(rc, SPLIT_POWS_ARGS_ERROR);
    list_free(odd_coefs);
    list_free(even_coefs);
}
END_TEST

START_TEST(test_split_coefs_by_partity_null_even_coefs)
{
    int array[] = {1, 9, 2, 8, 3, 7, 4, 6, 5};
    size_t n = sizeof(array) / sizeof(array[0]);
    node_t *coefs = list_allocate(n), *odd_coefs = list_allocate(n / 2);
    ck_assert_ptr_nonnull(coefs);
    ck_assert_ptr_nonnull(odd_coefs);
    list_fill_with_values(coefs, array, n);
    int rc = split_coefs_by_parity(coefs, n, NULL, odd_coefs);
    ck_assert_int_eq(rc, SPLIT_POWS_ARGS_ERROR);
    list_free(odd_coefs);
    list_free(coefs);
}
END_TEST

START_TEST(test_split_coefs_by_partity_null_odd_coefs)
{
    int array[] = {1, 9, 2, 8, 3, 7, 4, 6, 5};
    size_t n = sizeof(array) / sizeof(array[0]);
    node_t *coefs = list_allocate(n), *even_coefs = list_allocate(n / 2 + n % 2);
    ck_assert_ptr_nonnull(coefs);
    ck_assert_ptr_nonnull(even_coefs);
    list_fill_with_values(coefs, array, n);
    int rc = split_coefs_by_parity(coefs, n, even_coefs, NULL);
    ck_assert_int_eq(rc, SPLIT_POWS_ARGS_ERROR);
    list_free(even_coefs);
    list_free(coefs);
}
END_TEST

START_TEST(test_split_coefs_by_partity_null_n)
{
    int array[] = {1, 9, 2, 8, 3, 7, 4, 6, 5};
    size_t n = sizeof(array) / sizeof(array[0]);
    node_t *coefs = list_allocate(n), *even_coefs = list_allocate(n / 2 + n % 2), *odd_coefs = list_allocate(n / 2);
    ck_assert_ptr_nonnull(coefs);
    ck_assert_ptr_nonnull(even_coefs);
    ck_assert_ptr_nonnull(odd_coefs);
    list_fill_with_values(coefs, array, n);
    n = 0;
    int rc = split_coefs_by_parity(coefs, n, even_coefs, odd_coefs);
    ck_assert_int_eq(rc, SPLIT_POWS_ARGS_ERROR);
    list_free(even_coefs);
    list_free(odd_coefs);
    list_free(coefs);
}
END_TEST

START_TEST(test_split_coefs_by_partity_one_coef)
{
    int array[] = {123};
    int even_array[] = {123};
    size_t n = sizeof(array) / sizeof(array[0]), even_n = sizeof(even_array) / sizeof(even_array[0]);
    node_t *coefs = list_allocate(n), *even_coefs = list_allocate(n / 2 + n % 2), *odd_coefs = list_allocate(n / 2), *true_even_coefs = list_allocate(n / 2 + n % 2), *true_odd_coefs = list_allocate(n / 2);
    ck_assert_ptr_nonnull(coefs);
    ck_assert_ptr_nonnull(even_coefs);
    ck_assert_ptr_null(odd_coefs);
    ck_assert_ptr_nonnull(true_even_coefs);
    ck_assert_ptr_null(true_odd_coefs);
    list_fill_with_values(coefs, array, n);
    list_fill_with_values(true_even_coefs, even_array, even_n);
    int rc = split_coefs_by_parity(coefs, n, even_coefs, odd_coefs);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    node_t *copy_even_coefs = even_coefs, *copy_true_even_coefs = true_even_coefs;
    for (; even_coefs && true_even_coefs; even_coefs = even_coefs->next, true_even_coefs = true_even_coefs->next)
        ck_assert_int_eq(even_coefs->val, true_even_coefs->val);
    ck_assert_ptr_null(even_coefs);
    ck_assert_ptr_null(true_even_coefs);
    ck_assert_ptr_eq(odd_coefs, true_odd_coefs);
    list_free(copy_even_coefs);
    list_free(copy_true_even_coefs);
    list_free(coefs);
}
END_TEST

START_TEST(test_split_coefs_by_partity_many_coefs)
{
    int array[] = {123, 321, 12, 42, 34, 65, 876, 564};
    int even_array[] = {321, 42, 65, 564};
    int odd_array[] = {123, 12, 34, 876};
    size_t n = sizeof(array) / sizeof(array[0]), even_n = sizeof(even_array) / sizeof(even_array[0]), odd_n = sizeof(odd_array) / sizeof(odd_array[0]);
    node_t *coefs = list_allocate(n), *even_coefs = list_allocate(n / 2 + n % 2), *odd_coefs = list_allocate(n / 2), *true_even_coefs = list_allocate(n / 2 + n % 2), *true_odd_coefs = list_allocate(n / 2);
    ck_assert_ptr_nonnull(coefs);
    ck_assert_ptr_nonnull(even_coefs);
    ck_assert_ptr_nonnull(odd_coefs);
    ck_assert_ptr_nonnull(true_even_coefs);
    ck_assert_ptr_nonnull(true_odd_coefs);
    list_fill_with_values(coefs, array, n);
    list_fill_with_values(true_even_coefs, even_array, even_n);
    list_fill_with_values(true_odd_coefs, odd_array, odd_n);
    int rc = split_coefs_by_parity(coefs, n, even_coefs, odd_coefs);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    node_t *copy_even_coefs = even_coefs, *copy_true_even_coefs = true_even_coefs, *copy_odd_coefs = odd_coefs, *copy_true_odd_coefs = true_odd_coefs;
    for (; even_coefs && true_even_coefs; even_coefs = even_coefs->next, true_even_coefs = true_even_coefs->next)
        ck_assert_int_eq(even_coefs->val, true_even_coefs->val);
    ck_assert_ptr_null(even_coefs);
    ck_assert_ptr_null(true_even_coefs);
    for (; odd_coefs && true_odd_coefs; odd_coefs = odd_coefs->next, true_odd_coefs = true_odd_coefs->next)
        ck_assert_int_eq(odd_coefs->val, true_odd_coefs->val);
    list_free(copy_even_coefs);
    list_free(copy_true_even_coefs);
    list_free(copy_odd_coefs);
    list_free(copy_true_odd_coefs);
    list_free(coefs);
}
END_TEST

START_TEST(test_split_coefs_by_partity_many_coefs_defferent_cnt)
{
    int array[] = {8, 123, 321, 12, 42, 34, 65, 876, 564};
    int even_array[] = {8, 321, 42, 65, 564};
    int odd_array[] = {123, 12, 34, 876};
    size_t n = sizeof(array) / sizeof(array[0]), even_n = sizeof(even_array) / sizeof(even_array[0]), odd_n = sizeof(odd_array) / sizeof(odd_array[0]);
    node_t *coefs = list_allocate(n), *even_coefs = list_allocate(n / 2 + n % 2), *odd_coefs = list_allocate(n / 2), *true_even_coefs = list_allocate(n / 2 + n % 2), *true_odd_coefs = list_allocate(n / 2);
    ck_assert_ptr_nonnull(coefs);
    ck_assert_ptr_nonnull(even_coefs);
    ck_assert_ptr_nonnull(odd_coefs);
    ck_assert_ptr_nonnull(true_even_coefs);
    ck_assert_ptr_nonnull(true_odd_coefs);
    list_fill_with_values(coefs, array, n);
    list_fill_with_values(true_even_coefs, even_array, even_n);
    list_fill_with_values(true_odd_coefs, odd_array, odd_n);
    int rc = split_coefs_by_parity(coefs, n, even_coefs, odd_coefs);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    node_t *copy_even_coefs = even_coefs, *copy_true_even_coefs = true_even_coefs, *copy_odd_coefs = odd_coefs, *copy_true_odd_coefs = true_odd_coefs;
    for (; even_coefs && true_even_coefs; even_coefs = even_coefs->next, true_even_coefs = true_even_coefs->next)
        ck_assert_int_eq(even_coefs->val, true_even_coefs->val);
    ck_assert_ptr_null(even_coefs);
    ck_assert_ptr_null(true_even_coefs);
    for (; odd_coefs && true_odd_coefs; odd_coefs = odd_coefs->next, true_odd_coefs = true_odd_coefs->next)
        ck_assert_int_eq(odd_coefs->val, true_odd_coefs->val);
    list_free(copy_even_coefs);
    list_free(copy_true_even_coefs);
    list_free(copy_odd_coefs);
    list_free(copy_true_odd_coefs);
    list_free(coefs);
}
END_TEST

Suite *calc_value_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("calc_value");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_calc_value_one_coef);
    tcase_add_test(tc_pos, test_calc_value_one_nonnull_coef);
    tcase_add_test(tc_pos, test_calc_value_many_coefs);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_calc_calue_list_null);
    tcase_add_test(tc_neg, test_calc_value_size_null);
    tcase_add_test(tc_neg, test_calc_value_pows_null);
    tcase_add_test(tc_neg, test_calc_value_ans_null);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}

Suite *calc_derivative_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("calc_derivative");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_calc_derivative_min_elems);
    tcase_add_test(tc_pos, test_calc_derivative_many_elems);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_calc_derivative_coefs_null);
    tcase_add_test(tc_neg, test_calc_derivative_derivative_null);
    tcase_add_test(tc_neg, test_calc_derivative_null_n);
    tcase_add_test(tc_neg, test_calc_derivative_empty_derivative);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}

Suite *calc_sum_coef_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("calc_sum_coef");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_calc_coef_sum_min_elems);
    tcase_add_test(tc_pos, test_calc_coef_sum_many_elems);
    tcase_add_test(tc_pos, test_calc_coef_sum_different_elems_cnt_1);
    tcase_add_test(tc_pos, test_calc_coef_sum_different_elems_cnt_2);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_calc_coef_sum_coefs_1_null);
    tcase_add_test(tc_neg, test_calc_coef_sum_coefs_2_null);
    tcase_add_test(tc_neg, test_calc_coef_sum_n_1_null);
    tcase_add_test(tc_neg, test_calc_coef_sum_n_2_null);
    tcase_add_test(tc_neg, test_calc_coef_sum_ans_null);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}

Suite *split_coefs_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("split_coefs");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_split_coefs_by_partity_one_coef);
    tcase_add_test(tc_pos, test_split_coefs_by_partity_many_coefs);
    tcase_add_test(tc_pos, test_split_coefs_by_partity_many_coefs_defferent_cnt);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_calc_coef_sum_coefs_1_null);
    tcase_add_test(tc_neg, test_calc_coef_sum_coefs_2_null);
    tcase_add_test(tc_neg, test_split_coefs_by_partity_null_odd_coefs);
    tcase_add_test(tc_neg, test_split_coefs_by_partity_null_even_coefs);
    tcase_add_test(tc_neg, test_split_coefs_by_partity_null_coefs);
    tcase_add_test(tc_neg, test_split_coefs_by_partity_null_n);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}