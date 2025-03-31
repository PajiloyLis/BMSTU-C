#include <check.h>
#include "list.h"

START_TEST(test_front_back_split_two_elems)
{
    int array[] = {3, 4};
    size_t n = sizeof(array) / sizeof(array[0]);
    node_t *list = list_create_from_data(array, sizeof(array[0]), n);
    ck_assert_ptr_nonnull(list);
    node_t *true_back = list->next;
    node_t *back = NULL;
    front_back_split(list, &back);
    ck_assert_ptr_eq(back, true_back);
    list_free(back);
    list_free(list);
}
END_TEST

START_TEST(test_front_back_split_one_elem)
{
    int array[] = {3};
    size_t n = sizeof(array) / sizeof(array[0]);
    node_t *list = list_create_from_data(array, sizeof(array[0]), n);
    ck_assert_ptr_nonnull(list);
    node_t *back = NULL;
    front_back_split(list, &back);
    ck_assert_ptr_null(back);
    list_free(back);
    list_free(list);
}
END_TEST

START_TEST(test_front_back_split_three_elems)
{
    int array[] = {4, 3, 4};
    size_t n = sizeof(array) / sizeof(array[0]);
    node_t *list = list_create_from_data(array, sizeof(array[0]), n);
    ck_assert_ptr_nonnull(list);
    node_t *true_back = list->next->next;
    node_t *back = NULL;
    front_back_split(list, &back);
    ck_assert_ptr_eq(back, true_back);
    list_free(back);
    list_free(list);
}
END_TEST

Suite *front_back_split_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("front_back_split");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_front_back_split_two_elems);
    tcase_add_test(tc_pos, test_front_back_split_one_elem);
    tcase_add_test(tc_pos, test_front_back_split_three_elems);

    suite_add_tcase(s, tc_pos);
    return s;
}