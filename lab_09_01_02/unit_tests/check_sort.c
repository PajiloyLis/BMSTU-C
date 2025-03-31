#include "array_algo.h"
#include <check.h>

START_TEST(test_sort_null_array)
{
    size_t n = 5;
    int rc = insert_sort(NULL, n);
    ck_assert_int_eq(rc, NULL_POINTER_ERROR);
}
END_TEST

START_TEST(test_sort)
{
    object_t array[] = {{.name = "cde", .mass = 45, .volume = 15, .name_len = 3},
                        {.name = "cdef", .mass = 45, .volume = 15, .name_len = 4},
                        {.name = "cdefg", .mass = 45, .volume = 15, .name_len = 5},
                        {.name = "bcde", .mass = 30, .volume = 15, .name_len = 4},
                        {.name = "ab", .mass = 15, .volume = 15, .name_len = 2},
                        {.name = "abc", .mass = 15, .volume = 15, .name_len = 3}};
    size_t n = sizeof(array) / sizeof(array[0]);
    object_t sorted[] = {
        {.name = "ab", .mass = 15, .volume = 15, .name_len = 2},
        {.name = "abc", .mass = 15, .volume = 15, .name_len = 3},
        {.name = "bcde", .mass = 30, .volume = 15, .name_len = 4},
        {.name = "cde", .mass = 45, .volume = 15, .name_len = 3},
        {.name = "cdef", .mass = 45, .volume = 15, .name_len = 4},
        {.name = "cdefg", .mass = 45, .volume = 15, .name_len = 5},
    };
    int rc = insert_sort(array, n);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    for (size_t i = 0; i < n; ++i)
    {
        ck_assert_str_eq(array[i].name, sorted[i].name);
        ck_assert_double_eq(array[i].mass, sorted[i].mass);
        ck_assert_double_eq(array[i].volume, sorted[i].volume);
        ck_assert_uint_eq(array[i].name_len, sorted[i].name_len);
    }
}
END_TEST

Suite *sort_suite(void)
{
    Suite *s;
    TCase *tc_neg, *tc_pos;

    s = suite_create("insert_sort");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_sort_null_array);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_sort);

    suite_add_tcase(s, tc_neg);
    suite_add_tcase(s, tc_pos);
    return s;
}