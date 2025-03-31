#include "check_each.h"

static void add_to_keys_with_zero(const char *key, int *num, void *param)
{
    size_t index = strrchr(key, '_') - key + 1;
    size_t len = strlen(key);
    bool was_zero = false;
    for (size_t i = index; i < len && !was_zero; ++i)
        if (key[i] == '0')
            was_zero = true;
    if (was_zero)
        *num += *(int *)param;
}

START_TEST(test_assoc_array_each)
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
    int add = 8;
    rc = assoc_array_each(map, add_to_keys_with_zero, &add);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    int *value;
    rc = assoc_array_find(map, "some_key_0", &value);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*value, 22);
    rc = assoc_array_find(map, "some_key_00", &value);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*value, 23);
    rc = assoc_array_find(map, "some_key_01", &value);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*value, 24);
    rc = assoc_array_find(map, "some_key_20", &value);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*value, 22);
    assoc_array_destroy(&map);
}
END_TEST

START_TEST(test_assoc_array_each_null_function)
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
    int add = 8;
    rc = assoc_array_each(map, NULL, &add);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&map);
}
END_TEST

START_TEST(test_assoc_array_each_null_map)
{
    int add = 8;
    assoc_array_error_t rc = assoc_array_each(NULL, add_to_keys_with_zero, &add);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
}
END_TEST

Suite *assoc_array_each_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("assoc_array_each");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_assoc_array_each);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_assoc_array_each_null_function);
    tcase_add_test(tc_neg, test_assoc_array_each_null_map);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}