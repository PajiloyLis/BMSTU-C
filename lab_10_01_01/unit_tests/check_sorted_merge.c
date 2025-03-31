#include <check.h>
#include "list.h"

int compare_int(const void *, const void *);

START_TEST(test_sorted_merge_one_elems)
{
    int array_1[] = {3};
    int array_2[] = {4};
    int ans_array[] = {3, 4};
    size_t n_1 = sizeof(array_1) / sizeof(array_1[0]);
    size_t n_2 = sizeof(array_2) / sizeof(array_2[0]);
    size_t ans_n = sizeof(ans_array) / sizeof(ans_array[0]);
    node_t *list_1 = list_create_from_data(array_1, sizeof(array_1[0]), n_1);
    node_t *list_2 = list_create_from_data(array_2, sizeof(array_2[0]), n_2);
    node_t *list_ans = list_create_from_data(ans_array, sizeof(ans_array[0]), ans_n);
    ck_assert_ptr_nonnull(list_ans);
    ck_assert_ptr_nonnull(list_1);
    ck_assert_ptr_nonnull(list_2);
    node_t *merged = sorted_merge(&list_1, &list_2, compare_int), *merged_copy = merged, *ans_copy = list_ans;
    for (; merged && list_ans; merged = merged->next, list_ans = list_ans->next)
    {
        ck_assert_int_eq(*(int *)merged->data, *(int *)list_ans->data);
    }
    ck_assert_ptr_null(merged);
    ck_assert_ptr_null(list_ans);
    list_free(merged_copy);
    list_free(ans_copy);
}
END_TEST

START_TEST(test_sorted_merge_consistently)
{
    int array_1[] = {3, 4, 6};
    int array_2[] = {7, 8, 9, 10, 11};
    int ans_array[] = {3, 4, 6, 7, 8, 9, 10, 11};
    size_t n_1 = sizeof(array_1) / sizeof(array_1[0]);
    size_t n_2 = sizeof(array_2) / sizeof(array_2[0]);
    size_t ans_n = sizeof(ans_array) / sizeof(ans_array[0]);
    node_t *list_1 = list_create_from_data(array_1, sizeof(array_1[0]), n_1);
    node_t *list_2 = list_create_from_data(array_2, sizeof(array_2[0]), n_2);
    node_t *list_ans = list_create_from_data(ans_array, sizeof(ans_array[0]), ans_n);
    ck_assert_ptr_nonnull(list_ans);
    ck_assert_ptr_nonnull(list_1);
    ck_assert_ptr_nonnull(list_2);
    node_t *merged = sorted_merge(&list_1, &list_2, compare_int), *merged_copy = merged, *ans_copy = list_ans;
    for (; merged && list_ans; merged = merged->next, list_ans = list_ans->next)
    {
        ck_assert_int_eq(*(int *)merged->data, *(int *)list_ans->data);
    }
    ck_assert_ptr_null(merged);
    ck_assert_ptr_null(list_ans);
    list_free(merged_copy);
    list_free(ans_copy);
}
END_TEST

START_TEST(test_sorted_merge_alternately)
{
    int array_1[] = {3, 5, 7, 10};
    int array_2[] = {2, 4, 6, 8, 9, 11};
    int ans_array[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    size_t n_1 = sizeof(array_1) / sizeof(array_1[0]);
    size_t n_2 = sizeof(array_2) / sizeof(array_2[0]);
    size_t ans_n = sizeof(ans_array) / sizeof(ans_array[0]);
    node_t *list_1 = list_create_from_data(array_1, sizeof(array_1[0]), n_1);
    node_t *list_2 = list_create_from_data(array_2, sizeof(array_2[0]), n_2);
    node_t *list_ans = list_create_from_data(ans_array, sizeof(ans_array[0]), ans_n);
    ck_assert_ptr_nonnull(list_ans);
    ck_assert_ptr_nonnull(list_1);
    ck_assert_ptr_nonnull(list_2);
    node_t *merged = sorted_merge(&list_1, &list_2, compare_int), *merged_copy = merged, *ans_copy = list_ans;
    for (; merged && list_ans; merged = merged->next, list_ans = list_ans->next)
    {
        ck_assert_int_eq(*(int *)merged->data, *(int *)list_ans->data);
    }
    ck_assert_ptr_null(merged);
    ck_assert_ptr_null(list_ans);
    list_free(merged_copy);
    list_free(ans_copy);
}
END_TEST

START_TEST(test_sorted_merge_empty_2)
{
    int array_1[] = {3, 5, 7, 10};
    int ans_array[] = {3, 5, 7, 10};
    size_t n_1 = sizeof(array_1) / sizeof(array_1[0]);
    size_t ans_n = sizeof(ans_array) / sizeof(ans_array[0]);
    node_t *list_1 = list_create_from_data(array_1, sizeof(array_1[0]), n_1), *list_2 = NULL;
    node_t *list_ans = list_create_from_data(ans_array, sizeof(ans_array[0]), ans_n);
    ck_assert_ptr_nonnull(list_ans);
    ck_assert_ptr_nonnull(list_1);
    node_t *merged = sorted_merge(&list_1, &list_2, compare_int), *merged_copy = merged, *ans_copy = list_ans;
    for (; merged && list_ans; merged = merged->next, list_ans = list_ans->next)
    {
        ck_assert_int_eq(*(int *)merged->data, *(int *)list_ans->data);
    }
    ck_assert_ptr_null(merged);
    ck_assert_ptr_null(list_ans);
    list_free(merged_copy);
    list_free(ans_copy);
}
END_TEST

START_TEST(test_sorted_merge_empty_1)
{
    int array_2[] = {3, 5, 7, 10};
    int ans_array[] = {3, 5, 7, 10};
    size_t n_2 = sizeof(array_2) / sizeof(array_2[0]);
    size_t ans_n = sizeof(ans_array) / sizeof(ans_array[0]);
    node_t *list_2 = list_create_from_data(array_2, sizeof(array_2[0]), n_2), *list_1 = NULL;
    node_t *list_ans = list_create_from_data(ans_array, sizeof(ans_array[0]), ans_n);
    ck_assert_ptr_nonnull(list_ans);
    ck_assert_ptr_nonnull(list_2);
    node_t *merged = sorted_merge(&list_1, &list_2, compare_int), *merged_copy = merged, *ans_copy = list_ans;
    for (; merged && list_ans; merged = merged->next, list_ans = list_ans->next)
    {
        ck_assert_int_eq(*(int *)merged->data, *(int *)list_ans->data);
    }
    ck_assert_ptr_null(merged);
    ck_assert_ptr_null(list_ans);
    list_free(merged_copy);
    list_free(ans_copy);
}
END_TEST

Suite *sorted_merge_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("sorted_merge");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_sorted_merge_one_elems);
    tcase_add_test(tc_pos, test_sorted_merge_consistently);
    tcase_add_test(tc_pos, test_sorted_merge_alternately);
    tcase_add_test(tc_pos, test_sorted_merge_empty_2);
    tcase_add_test(tc_pos, test_sorted_merge_empty_1);

    suite_add_tcase(s, tc_pos);
    return s;
}