#include <check.h>
#include "list.h"

int compare_int(const void *, const void *);

START_TEST(test_insert)
{
    int array[] = {3, 4, 5, 3, 6, 4, 6};
    int ans_array[] = {3, 4, 5, 3, 7, 6, 4, 6};
    size_t n = sizeof(array) / sizeof(array[0]);
    size_t ans_n = sizeof(ans_array) / sizeof(ans_array[0]);
    int to_find = 7;
    node_t *list = list_create_from_data(array, sizeof(array[0]), n);
    node_t *ans_list = list_create_from_data(ans_array, sizeof(ans_array[0]), ans_n);
    ck_assert_ptr_nonnull(list);
    ck_assert_ptr_nonnull(ans_list);
    node_t *before = list->next->next->next->next, *elem = malloc(sizeof(node_t));
    elem->next = NULL;
    elem->data = &to_find;
    insert(&list, elem, before);
    node_t *cur, *ans_cur;
    for (cur = list, ans_cur = ans_list; cur && ans_cur; cur = cur->next, ans_cur = ans_cur->next)
    {
        ck_assert_int_eq(*(int *)cur->data, *(int *)ans_cur->data);
    }
    ck_assert_ptr_null(cur);
    ck_assert_ptr_null(ans_cur);
    list_free(list);
    list_free(ans_list);
}
END_TEST

START_TEST(test_insert_begin)
{
    int array[] = {3, 4, 5, 3, 6, 4, 6};
    int ans_array[] = {7, 3, 4, 5, 3, 6, 4, 6};
    size_t n = sizeof(array) / sizeof(array[0]);
    size_t ans_n = sizeof(ans_array) / sizeof(ans_array[0]);
    int to_find = 7;
    node_t *list = list_create_from_data(array, sizeof(array[0]), n);
    node_t *ans_list = list_create_from_data(ans_array, sizeof(ans_array[0]), ans_n);
    ck_assert_ptr_nonnull(list);
    ck_assert_ptr_nonnull(ans_list);
    node_t *elem = malloc(sizeof(node_t));
    elem->next = NULL;
    elem->data = &to_find;
    insert(&list, elem, list);
    node_t *cur, *ans_cur;
    for (cur = list, ans_cur = ans_list; cur && ans_cur; cur = cur->next, ans_cur = ans_cur->next)
    {
        ck_assert_int_eq(*(int *)cur->data, *(int *)ans_cur->data);
    }
    ck_assert_ptr_null(cur);
    ck_assert_ptr_null(ans_cur);
    list_free(list);
    list_free(ans_list);
}
END_TEST

START_TEST(test_insert_end)
{
    int array[] = {3, 4, 5, 3, 6, 4, 6};
    int ans_array[] = {3, 4, 5, 3, 6, 4, 6, 7};
    size_t n = sizeof(array) / sizeof(array[0]);
    size_t ans_n = sizeof(ans_array) / sizeof(ans_array[0]);
    int to_find = 7;
    node_t *list = list_create_from_data(array, sizeof(array[0]), n);
    node_t *ans_list = list_create_from_data(ans_array, sizeof(ans_array[0]), ans_n);
    ck_assert_ptr_nonnull(list);
    ck_assert_ptr_nonnull(ans_list);
    node_t *elem = malloc(sizeof(node_t));
    elem->next = NULL;
    elem->data = &to_find;
    insert(&list, elem, NULL);
    node_t *cur, *ans_cur;
    for (cur = list, ans_cur = ans_list; cur && ans_cur; cur = cur->next, ans_cur = ans_cur->next)
    {
        ck_assert_int_eq(*(int *)cur->data, *(int *)ans_cur->data);
    }
    ck_assert_ptr_null(cur);
    ck_assert_ptr_null(ans_cur);
    list_free(list);
    list_free(ans_list);
}
END_TEST

Suite *insert_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("insert");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_insert);
    tcase_add_test(tc_pos, test_insert_begin);
    tcase_add_test(tc_pos, test_insert_end);

    suite_add_tcase(s, tc_pos);
    return s;
}