#include "check_clear.h"

START_TEST(test_assoc_array_clear_root)
{
    assoc_array_t map = assoc_array_create();
    ck_assert_ptr_nonnull(map);
    assoc_array_error_t rc = assoc_array_insert(map, "some_key_1", 13);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_clear(map);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_ptr_nonnull(map);
    int *val = NULL;
    rc = assoc_array_find(map, "some_key_1", &val);
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);
    assoc_array_destroy(&map);
    ck_assert_ptr_null(map);
}
END_TEST

START_TEST(test_assoc_array_clear_tree)
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
    rc = assoc_array_clear(map);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_ptr_nonnull(map);
    int *val = NULL;
    rc = assoc_array_find(map, "some_key_1", &val);
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);
    rc = assoc_array_find(map, "some_key_0", &val);
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);
    rc = assoc_array_find(map, "some_key_00", &val);
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);
    rc = assoc_array_find(map, "some_key_01", &val);
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);
    rc = assoc_array_find(map, "some_key_2", &val);
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);
    rc = assoc_array_find(map, "some_key_21", &val);
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);
    rc = assoc_array_find(map, "some_key_20", &val);
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);
    assoc_array_destroy(&map);
    ck_assert_ptr_null(map);
}
END_TEST

START_TEST(test_assoc_array_clear_map_null)
{
    assoc_array_error_t rc = assoc_array_clear(NULL);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
}
END_TEST

START_TEST(test_assoc_array_clear_root_null)
{
    assoc_array_t map = assoc_array_create();
    ck_assert_ptr_nonnull(map);
    assoc_array_error_t rc = assoc_array_clear(map);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_ptr_nonnull(map);
    assoc_array_destroy(&map);
}
END_TEST

Suite *assoc_array_clear_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("assoc_array_clear");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_assoc_array_clear_root);
    tcase_add_test(tc_pos, test_assoc_array_clear_tree);
    tcase_add_test(tc_pos, test_assoc_array_clear_root_null);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_assoc_array_clear_map_null);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}