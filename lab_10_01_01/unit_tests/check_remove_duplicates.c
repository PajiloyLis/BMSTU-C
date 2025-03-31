#include <check.h>
#include "list.h"

int compare_int(const void *, const void *);

START_TEST(test_remove_duplicates_no_duplicates)
{
    int array[] = {3, 4, 5, 6};
    int ans_array[] = {3, 4, 5, 6};
    size_t n = sizeof(array) / sizeof(array[0]);
    size_t ans_n = sizeof(ans_array) / sizeof(ans_array[0]);
    node_t *list = list_create_from_data(array, sizeof(array[0]), n);
    node_t *ans_list = list_create_from_data(ans_array, sizeof(ans_array[0]), ans_n);
    ck_assert_ptr_nonnull(list);
    ck_assert_ptr_nonnull(ans_list);
    remove_duplicates(&list, compare_int);
    node_t *cur_1 = list, *cur_2 = ans_list;
    for (; cur_1 && cur_2; cur_1 = cur_1->next, cur_2 = cur_2->next)
    {
        ck_assert_int_eq(*(int *)cur_1->data, *(int *)cur_2->data);
    }
    ck_assert_ptr_null(cur_1);
    ck_assert_ptr_null(cur_2);
    list_free(list);
    list_free(ans_list);
}
END_TEST

START_TEST(test_remove_duplicates)
{
    int array[] = {3, 3, 3, 4, 4, 4, 4, 5, 5, 6, 7, 7};
    int ans_array[] = {3, 4, 5, 6, 7};
    size_t n = sizeof(array) / sizeof(array[0]);
    size_t ans_n = sizeof(ans_array) / sizeof(ans_array[0]);
    node_t *list = list_create_from_data(array, sizeof(array[0]), n);
    node_t *ans_list = list_create_from_data(ans_array, sizeof(ans_array[0]), ans_n);
    ck_assert_ptr_nonnull(list);
    ck_assert_ptr_nonnull(ans_list);
    remove_duplicates(&list, compare_int);
    node_t *cur_1 = list, *cur_2 = ans_list;
    for (; cur_1 && cur_2; cur_1 = cur_1->next, cur_2 = cur_2->next)
    {
        ck_assert_int_eq(*(int *)cur_1->data, *(int *)cur_2->data);
    }
    ck_assert_ptr_null(cur_1);
    ck_assert_ptr_null(cur_2);
    list_free(list);
    list_free(ans_list);
}
END_TEST

Suite *remove_duplicates_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("remove_duplicates");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_remove_duplicates_no_duplicates);
    tcase_add_test(tc_pos, test_remove_duplicates);

    suite_add_tcase(s, tc_pos);
    return s;
}