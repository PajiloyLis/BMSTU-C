#include "check_destroy.h"

START_TEST(test_assoc_array_destroy)
{
    assoc_array_t map = assoc_array_create();
    ck_assert_ptr_nonnull(map);
    assoc_array_destroy(&map);
    ck_assert_ptr_null(map);
}
END_TEST

START_TEST(test_assoc_array_destroy_tree)
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
    assoc_array_destroy(&map);
    ck_assert_ptr_null(map);
}
END_TEST

Suite *assoc_array_destroy_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("assoc_array_destroy");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_assoc_array_destroy);
    tcase_add_test(tc_pos, test_assoc_array_destroy_tree);

    suite_add_tcase(s, tc_pos);
    return s;
}
