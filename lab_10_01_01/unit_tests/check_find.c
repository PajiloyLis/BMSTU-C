#include <check.h>
#include "list.h"

int compare_int(const void *, const void *);

START_TEST(test_find)
{
    int array[] = {3, 4, 5, 3, 6, 4, 6};
    size_t n = sizeof(array) / sizeof(array[0]);
    int to_find = 3;
    node_t *list = list_create_from_data(array, sizeof(array[0]), n);
    ck_assert_ptr_nonnull(list);
    node_t *result = find(list, &to_find, compare_int);
    ck_assert_ptr_eq(result, list);
    list_free(list);
}
END_TEST

START_TEST(test_find_not_found)
{
    int array[] = {3, 8, 5, 6, 4, 5, 6, 0, 99999};
    size_t n = sizeof(array) / sizeof(array[0]);
    node_t *list = list_create_from_data(array, sizeof(array[0]), n);
    ck_assert_ptr_nonnull(list);
    int to_find = 12;
    node_t *result= find(list, &to_find, compare_int);
    ck_assert_ptr_null(result);
    list_free(list);
}
END_TEST

START_TEST(test_find_list_null)
{
    int to_find = 12;
    node_t *result= find(NULL, &to_find, compare_int);
    ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_find_data_null)
{
    int array[] = {3, 8, 5, 6, 4, 5, 6, 0, 99999};
    size_t n = sizeof(array) / sizeof(array[0]);
    node_t *list = list_create_from_data(array, sizeof(array[0]), n);
    ck_assert_ptr_nonnull(list);
    node_t *result= find(list, NULL, compare_int);
    ck_assert_ptr_null(result);
    list_free(list);
}
END_TEST

START_TEST(test_find_function_null)
{
    int array[] = {3, 8, 5, 6, 4, 5, 6, 0, 99999};
    size_t n = sizeof(array) / sizeof(array[0]);
    node_t *list = list_create_from_data(array, sizeof(array[0]), n);
    ck_assert_ptr_nonnull(list);
    int to_find = 12;
    node_t *result= find(list, &to_find, NULL);
    ck_assert_ptr_null(result);
    list_free(list);
}
END_TEST

Suite *find_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("find");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_find);
    tcase_add_test(tc_pos, test_find_not_found);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_find_list_null);
    tcase_add_test(tc_neg, test_find_data_null);
    tcase_add_test(tc_neg, test_find_function_null);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}