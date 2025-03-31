#include <check.h>
#include "array_algo.h"

START_TEST(test_find_null_array)
{
    object_t **ans_array;
    object_t **buf = malloc(15 * sizeof(object_t *));
    if (!buf)
        ck_assert_int_eq(1, 0);
    ans_array = buf;
    size_t ans_n = 5, total_ans_n = 5, n = 5;
    char *prefix = "A";
    int rc = find(NULL, &ans_array, &ans_n, n, &total_ans_n, prefix);
    ck_assert_int_eq(rc, NULL_POINTER_ERROR);
    free(ans_array);
}
END_TEST

START_TEST(test_find_null_ans_array)
{
    object_t array[15];
    size_t ans_n = 5, total_ans_n = 5, n = 5;
    char *prefix = "A";
    int rc = find(array, NULL, &ans_n, n, &total_ans_n, prefix);
    ck_assert_int_eq(rc, NULL_POINTER_ERROR);
}
END_TEST

START_TEST(test_find_null_prefix)
{
    object_t array[15], **ans_array;
    object_t **buf = malloc(15 * sizeof(object_t *));
    if (!buf)
        ck_assert_int_eq(1, 0);
    ans_array = buf;
    size_t ans_n = 5, total_ans_n = 5, n = 5;
    int rc = find(array, &ans_array, &ans_n, n, &total_ans_n, NULL);
    ck_assert_int_eq(rc, NULL_POINTER_ERROR);
    free(ans_array);
}
END_TEST

START_TEST(test_find_found)
{
    object_t array[] = {{.name = "Elephant", .mass = 5000, .volume = 3.15, .name_len = 8},
                        {.name = "Dumbbells", .mass = 6, .volume = 0.0007, .name_len = 9},
                        {.name = "Teapot", .mass = 0.7, .volume = 0.00028, .name_len = 6}};
    object_t **ans_array;
    object_t **buf = malloc(15 * sizeof(object_t *));
    if (!buf)
        ck_assert_int_eq(1, 0);
    ans_array = buf;
    size_t ans_n = 0, total_ans_n = 15, n = sizeof(array) / sizeof(array[0]);
    char prefix[] = "E";
    int rc = find(array, &ans_array, &ans_n, n, &total_ans_n, prefix);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(ans_n, 1);
    ck_assert_str_eq(ans_array[0]->name, "Elephant");
    free(ans_array);
}
END_TEST

START_TEST(test_find_not_found)
{
    object_t array[] = {{.name = "Elephant", .mass = 5000, .volume = 3.15, .name_len = 8},
                        {.name = "Dumbbells", .mass = 6, .volume = 0.0007, .name_len = 9},
                        {.name = "Teapot", .mass = 0.7, .volume = 0.00028, .name_len = 6}};
    object_t **ans_array;
    object_t **buf = malloc(15 * sizeof(object_t *));
    if (!buf)
        ck_assert_int_eq(1, 0);
    ans_array = buf;
    size_t ans_n = 0, total_ans_n = 15, n = sizeof(array) / sizeof(array[0]);
    char prefix[] = "A";
    int rc = find(array, &ans_array, &ans_n, n, &total_ans_n, prefix);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(ans_n, 0);
    free(ans_array);
}
END_TEST

START_TEST(test_find_realloc)
{
    object_t array[] = {{.name = "abceywaw", .mass = 4.4, .volume = 4.461538461538462, .name_len = 8},
                        {.name = "abcizoaoqzm", .mass = 5.6923076923076925, .volume = 2.1052631578947367, .name_len = 11},
                        {.name = "abcuymjkeqbk", .mass = 6.4, .volume = 0.8235294117647058, .name_len = 12},
                        {.name = "abceudod", .mass = 1.3076923076923077, .volume = 5.0, .name_len = 8},
                        {.name = "abcpvouqgb", .mass = 1.6, .volume = 2.3636363636363638, .name_len = 10},
                        {.name = "abcclktdtsvjf", .mass = 4.625, .volume = 5.466666666666667, .name_len = 13},
                        {.name = "abcfvwaxkec", .mass = 3.7777777777777777, .volume = 4.571428571428571, .name_len = 11},
                        {.name = "abcjsagyoyorf", .mass = 7.615384615384615, .volume = 2.1818181818181817, .name_len = 13},
                        {.name = "abcayfnr", .mass = 8.6, .volume = 0.8571428571428571, .name_len = 8},
                        {.name = "abciztvvq", .mass = 2.5, .volume = 4.428571428571429, .name_len = 9},
                        {.name = "abcgurhozkdfo", .mass = 2.7, .volume = 2.3636363636363638, .name_len = 13},
                        {.name = "abcozazluhbd", .mass = 1.3333333333333333, .volume = 3.375, .name_len = 12},
                        {.name = "abcvffxelc", .mass = 5.0588235294117645, .volume = 1.1875, .name_len = 10},
                        {.name = "abcsucmvgmxlh", .mass = 0.55, .volume = 3.3076923076923075, .name_len = 13},
                        {.name = "abclfjyn", .mass = 7.0, .volume = 6.2727272727272725, .name_len = 8},
                        {.name = "abcbefcoprqh", .mass = 1.8125, .volume = 7.090909090909091, .name_len = 12},
                        {.name = "abcqopdxh", .mass = 2.0, .volume = 3.5, .name_len = 9},
                        {.name = "abctemrlwi", .mass = 4.0, .volume = 3.55, .name_len = 10},
                        {.name = "abcdauufc", .mass = 2.2777777777777777, .volume = 3.533333333333333, .name_len = 9},
                        {.name = "abccxotacsdou", .mass = 2.8947368421052633, .volume = 1.45, .name_len = 13}};
    object_t **ans_array, **buf;
    buf = malloc(15 * sizeof(object_t *));
    if (!buf)
        ck_assert_int_eq(1, 0);
    ans_array = buf;
    size_t ans_n = 0, total_ans_n = 15, n = sizeof(array) / sizeof(array[0]);
    char prefix[] = "abc";
    int rc = find(array, &ans_array, &ans_n, n, &total_ans_n, prefix);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_uint_eq(ans_n, 20);
    ck_assert_uint_eq(total_ans_n, 30);
    for (size_t i = 0; i < ans_n; ++i)
    {
        ck_assert_str_eq(ans_array[i]->name, array[i].name);
    }
    free(ans_array);
}
END_TEST

Suite *find_suite(void)
{
    Suite *s;
    TCase *tc_neg, *tc_pos;

    s = suite_create("find");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_find_null_array);
    tcase_add_test(tc_neg, test_find_null_ans_array);
    tcase_add_test(tc_neg, test_find_null_prefix);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_find_found);
    tcase_add_test(tc_pos, test_find_not_found);
    tcase_add_test(tc_pos, test_find_realloc);

    suite_add_tcase(s, tc_neg);
    suite_add_tcase(s, tc_pos);
    return s;
}