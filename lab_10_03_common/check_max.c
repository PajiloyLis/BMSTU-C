#include "check_max.h"

START_TEST(test_assoc_array_max)
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
    rc = assoc_array_insert(map, "some_key_2", 17);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_21", 12);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(map, "some_key_20", 13);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    int *max = NULL;
    rc = assoc_array_max(map, &max);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*max, 12);
    assoc_array_destroy(&map);
}
END_TEST

START_TEST(test_assoc_array_max_null_map)
{
    int *max = NULL;
    assoc_array_error_t rc = assoc_array_max(NULL, &max);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
}
END_TEST

START_TEST(test_assoc_array_max_null_root)
{
    assoc_array_t map = assoc_array_create();
    ck_assert_ptr_nonnull(map);
    int *max = NULL;
    assoc_array_error_t rc = assoc_array_max(map, &max);
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);
    assoc_array_destroy(&map);
}
END_TEST

START_TEST(test_assoc_array_max_null_val)
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
    rc = assoc_array_max(map, NULL);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&map);
}
END_TEST

Suite *assoc_array_max_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("assoc_array_max");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_assoc_array_max);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_assoc_array_max_null_map);
    tcase_add_test(tc_neg, test_assoc_array_max_null_root);
    tcase_add_test(tc_neg, test_assoc_array_max_null_val);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}