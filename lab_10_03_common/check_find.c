#include "check_find.h"

START_TEST(test_assoc_array_find_right_subtree)
{
    assoc_array_t map = assoc_array_create();
    ck_assert_ptr_nonnull(map);
    assoc_array_error_t rc = assoc_array_insert(map, "some_key_1", 13);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_0", 14);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_00", 15);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_01", 16);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_2", 14);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_21", 14);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_20", 14);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    int *value;
    rc = assoc_array_find(map, "some_key_21", &value);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*value, 14);
    assoc_array_destroy(&map);
    ck_assert_ptr_null(map);
}
END_TEST

START_TEST(test_assoc_array_find_left_subtree)
{
    assoc_array_t map = assoc_array_create();
    ck_assert_ptr_nonnull(map);
    assoc_array_error_t rc = assoc_array_insert(map, "some_key_1", 13);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_0", 14);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_00", 15);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_01", 16);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_2", 14);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_21", 14);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_20", 14);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    int *value;
    rc = assoc_array_find(map, "some_key_0", &value);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*value, 14);
    assoc_array_destroy(&map);
    ck_assert_ptr_null(map);
}
END_TEST

START_TEST(test_assoc_array_find_not_found)
{
    assoc_array_t map = assoc_array_create();
    ck_assert_ptr_nonnull(map);
    assoc_array_error_t rc = assoc_array_insert(map, "some_key_1", 13);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_0", 14);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_00", 15);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_01", 16);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_2", 14);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_21", 14);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_20", 14);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    int *value;
    rc = assoc_array_find(map, "some_key_000", &value);
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);
    assoc_array_destroy(&map);
    ck_assert_ptr_null(map);
}
END_TEST

START_TEST(test_assoc_array_find_not_found_null_root)
{
    assoc_array_t map = assoc_array_create();
    ck_assert_ptr_nonnull(map);
    int *value;
    assoc_array_error_t rc = assoc_array_find(map, "some_key_0", &value);
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);
    assoc_array_destroy(&map);
    ck_assert_ptr_null(map);
}
END_TEST

START_TEST(test_assoc_array_find_zero_str_len)
{
    assoc_array_t map = assoc_array_create();
    ck_assert_ptr_nonnull(map);
    assoc_array_error_t rc = assoc_array_insert(map, "some_key_1", 13);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_0", 14);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_00", 15);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_01", 16);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_2", 14);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_21", 14);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_20", 14);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    int *value;
    rc = assoc_array_find(map, "", &value);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&map);
    ck_assert_ptr_null(map);
}
END_TEST

START_TEST(test_assoc_array_find_null_map)
{
    int *value;
    assoc_array_error_t rc = assoc_array_find(NULL, "some_key_20", &value);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
}
END_TEST

START_TEST(test_assoc_array_find_null_value_pointer)
{
    assoc_array_t map = assoc_array_create();
    ck_assert_ptr_nonnull(map);
    assoc_array_error_t rc = assoc_array_insert(map, "some_key_1", 13);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_0", 14);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_00", 15);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_01", 16);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_2", 14);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_21", 14);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_20", 14);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_find(map, "some_key_20", NULL);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&map);
    ck_assert_ptr_null(map);
}
END_TEST

Suite *assoc_array_find_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("assoc_array_find");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_assoc_array_find_left_subtree);
    tcase_add_test(tc_pos, test_assoc_array_find_right_subtree);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_assoc_array_find_not_found);
    tcase_add_test(tc_neg, test_assoc_array_find_not_found_null_root);
    tcase_add_test(tc_neg, test_assoc_array_find_null_map);
    tcase_add_test(tc_neg, test_assoc_array_find_null_value_pointer);
    tcase_add_test(tc_neg, test_assoc_array_find_zero_str_len);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}
