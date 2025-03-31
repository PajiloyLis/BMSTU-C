#include "args.h"
#include <check.h>

START_TEST(test_args_handler_less_argc)
{
    int argc = 1;
    char *argv[] = {"path/to/file", "./func_tests/data/pos_06_input.txt"}, *file_name = NULL, *prefix = NULL;
    int rc = take_args(argc, argv, &prefix, &file_name);
    ck_assert_int_eq(rc, ARGS_COUNT_ERROR);
}
END_TEST

START_TEST(test_args_handler_more_argc)
{
    int argc = 4;
    char *argv[] = {"path/to/file", "./func_tests/data/pos_06_input.txt", "abc"}, *file_name = NULL, *prefix = NULL;
    int rc = take_args(argc, argv, &prefix, &file_name);
    ck_assert_int_eq(rc, ARGS_COUNT_ERROR);
}
END_TEST

START_TEST(test_args_handler_null_argv)
{
    int argc = 2;
    char *file_name = NULL, *prefix = NULL;
    int rc = take_args(argc, NULL, &prefix, &file_name);
    ck_assert_int_eq(rc, ARGS_NULL_POINTER);
}
END_TEST

START_TEST(test_args_handler_no_prefix)
{
    char *argv[] = {"path/to/file", "./func_tests/data/pos_06_input.txt"}, *file_name = NULL, *prefix=NULL;
    int argc = sizeof(argv) / sizeof(char *);
    int rc = take_args(argc, argv, &prefix, &file_name);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_str_eq(file_name, "./func_tests/data/pos_06_input.txt");
}
END_TEST

START_TEST(test_args_handler_with_prefix)
{
    char *argv[] = {"path/to/file", "./func_tests/data/pos_06_input.txt", "f"}, *file_name = NULL, *prefix = NULL;
    int argc = sizeof(argv) / sizeof(char *);
    int rc = take_args(argc, argv, &prefix, &file_name);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_str_eq(file_name, "./func_tests/data/pos_06_input.txt");
    ck_assert_str_eq(prefix, "f");
}
END_TEST

Suite *take_args_suite(void)
{
    Suite *s;
    TCase *tc_neg, *tc_pos;

    s = suite_create("args_handler");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_args_handler_less_argc);
    tcase_add_test(tc_neg, test_args_handler_more_argc);
    tcase_add_test(tc_neg, test_args_handler_null_argv);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_args_handler_no_prefix);
    tcase_add_test(tc_pos, test_args_handler_with_prefix);

    suite_add_tcase(s, tc_neg);
    suite_add_tcase(s, tc_pos);
    return s;
}