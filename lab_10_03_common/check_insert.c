#include "check_insert.h"

START_TEST(test_assoc_array_insert_root)
{
    assoc_array_t map = assoc_array_create();
    ck_assert_ptr_nonnull(map);
    assoc_array_error_t rc = assoc_array_insert(map, "some_key_1", 333);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    assoc_array_destroy(&map);
    ck_assert_ptr_null(map);
}
END_TEST

START_TEST(test_assoc_array_insert_root_child_left)
{
    assoc_array_t map = assoc_array_create();
    ck_assert_ptr_nonnull(map);
    assoc_array_error_t rc = assoc_array_insert(map, "some_key_1", 333);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_0", 123);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    assoc_array_destroy(&map);
    ck_assert_ptr_null(map);
}
END_TEST

START_TEST(test_assoc_array_insert_root_child_right)
{
    assoc_array_t map = assoc_array_create();
    ck_assert_ptr_nonnull(map);
    assoc_array_error_t rc = assoc_array_insert(map, "some_key_1", 333);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_2", 123);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    assoc_array_destroy(&map);
    ck_assert_ptr_null(map);
}
END_TEST

START_TEST(test_assoc_array_insert_null_map)
{
    assoc_array_t map = NULL;
    assoc_array_error_t rc = assoc_array_insert(map, "some_key_1", 333);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&map);
    ck_assert_ptr_null(map);
}
END_TEST

START_TEST(test_assoc_array_insert_null_len_key)
{
    assoc_array_t map = assoc_array_create();
    ck_assert_ptr_nonnull(map);
    assoc_array_error_t rc = assoc_array_insert(map, "", 333);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&map);
    ck_assert_ptr_null(map);
}
END_TEST

START_TEST(test_assoc_array_insert_null_key)
{
    assoc_array_t map = assoc_array_create();
    ck_assert_ptr_nonnull(map);
    assoc_array_error_t rc = assoc_array_insert(map, NULL, 333);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&map);
    ck_assert_ptr_null(map);
}
END_TEST

START_TEST(test_assoc_array_insert_key_exist)
{
    assoc_array_t map = assoc_array_create();
    ck_assert_ptr_nonnull(map);
    assoc_array_error_t rc = assoc_array_insert(map, "some_key", 333);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key", 222);
    ck_assert_int_eq(rc, ASSOC_ARRAY_KEY_EXISTS);
    assoc_array_destroy(&map);
    ck_assert_ptr_null(map);
}
END_TEST

START_TEST(test_assoc_array_insert)
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
    rc = assoc_array_insert(map, "some_key_2", 12);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_21", 11);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_20", 119);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_3", 17);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_30", 128);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_31", 10);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    assoc_array_destroy(&map);
    ck_assert_ptr_null(map);
}
END_TEST

START_TEST(test_assoc_array_insert_sorted)
{
    assoc_array_t map = assoc_array_create();
    ck_assert_ptr_nonnull(map);
    assoc_array_error_t rc = assoc_array_insert(map, "some_key_0", 14);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_00", 15);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_01", 16);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_1", 13);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_2", 12);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_20", 17);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_21", 11);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    assoc_array_destroy(&map);
    ck_assert_ptr_null(map);
}
END_TEST

Suite *assoc_array_insert_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("assoc_array_insert");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_assoc_array_insert_root);
    tcase_add_test(tc_pos, test_assoc_array_insert_root_child_left);
    tcase_add_test(tc_pos, test_assoc_array_insert_root_child_right);
    tcase_add_test(tc_pos, test_assoc_array_insert);
    tcase_add_test(tc_pos, test_assoc_array_insert_sorted);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_assoc_array_insert_key_exist);
    tcase_add_test(tc_neg, test_assoc_array_insert_null_key);
    tcase_add_test(tc_neg, test_assoc_array_insert_null_len_key);
    tcase_add_test(tc_neg, test_assoc_array_insert_null_map);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}
