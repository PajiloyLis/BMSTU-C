#include <check.h>
#include "list.h"

int compare_int(const void *, const void *);

START_TEST(test_sort_one_elem)
{
    int array[] = {3};
    int ans_array[] = {3};
    size_t n = sizeof(array) / sizeof(array[0]);
    size_t ans_n = sizeof(ans_array) / sizeof(ans_array[0]);
    node_t *list = list_create_from_data(array, sizeof(array[0]), n);
    node_t *list_ans = list_create_from_data(ans_array, sizeof(ans_array[0]), ans_n);
    ck_assert_ptr_nonnull(list_ans);
    ck_assert_ptr_nonnull(list);
    node_t *sorted = sort(list, compare_int), *sorted_copy = sorted, *ans_copy = list_ans;
    for (; sorted && list_ans; sorted = sorted->next, list_ans = list_ans->next)
    {
        ck_assert_int_eq(*(int *)sorted->data, *(int *)list_ans->data);
    }
    ck_assert_ptr_null(sorted);
    ck_assert_ptr_null(list_ans);
    list_free(sorted_copy);
    list_free(ans_copy);
}
END_TEST

START_TEST(test_sort_unsorted)
{
    int array[] = {3, 8, 5, 6, 4, 5, 6, 0, 99999};
    int ans_array[] = {0, 3, 4, 5, 5, 6, 6, 8, 99999};
    size_t n = sizeof(array) / sizeof(array[0]);
    size_t ans_n = sizeof(ans_array) / sizeof(ans_array[0]);
    node_t *list = list_create_from_data(array, sizeof(array[0]), n);
    node_t *list_ans = list_create_from_data(ans_array, sizeof(ans_array[0]), ans_n);
    ck_assert_ptr_nonnull(list_ans);
    ck_assert_ptr_nonnull(list);
    node_t *sorted = sort(list, compare_int), *sorted_copy = sorted, *ans_copy = list_ans;
    for (; sorted && list_ans; sorted = sorted->next, list_ans = list_ans->next)
    {
        ck_assert_int_eq(*(int *)sorted->data, *(int *)list_ans->data);
    }
    ck_assert_ptr_null(sorted);
    ck_assert_ptr_null(list_ans);
    list_free(sorted_copy);
    list_free(ans_copy);
}
END_TEST

START_TEST(test_sort_rsorted)
{
    int array[] = {99999, 8, 6, 6, 5, 5, 4, 3, 0};
    int ans_array[] = {0, 3, 4, 5, 5, 6, 6, 8, 99999};
    size_t n = sizeof(array) / sizeof(array[0]);
    size_t ans_n = sizeof(ans_array) / sizeof(ans_array[0]);
    node_t *list = list_create_from_data(array, sizeof(array[0]), n);
    node_t *list_ans = list_create_from_data(ans_array, sizeof(ans_array[0]), ans_n);
    ck_assert_ptr_nonnull(list_ans);
    ck_assert_ptr_nonnull(list);
    node_t *sorted = sort(list, compare_int), *sorted_copy = sorted, *ans_copy = list_ans;
    for (; sorted && list_ans; sorted = sorted->next, list_ans = list_ans->next)
    {
        ck_assert_int_eq(*(int *)sorted->data, *(int *)list_ans->data);
    }
    ck_assert_ptr_null(sorted);
    ck_assert_ptr_null(list_ans);
    list_free(sorted_copy);
    list_free(ans_copy);
}
END_TEST

START_TEST(test_sort_null)
{
    node_t *sorted = sort(NULL, compare_int);
    ck_assert_ptr_null(sorted);
}
END_TEST

Suite *sort_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("sorted_merge");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_sort_one_elem);
    tcase_add_test(tc_pos, test_sort_unsorted);
    tcase_add_test(tc_pos, test_sort_rsorted);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_sort_null);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}