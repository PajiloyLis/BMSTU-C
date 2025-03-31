#include "args.h"
#include <check.h>

START_TEST(test_args_handler_less_argc)
{
    int argc = 2;
    char *argv[] = {"path/to/file", "./unit_tests/data/neg_01_in.txt", "./unit_tests/data/neg_01_output.txt"}, *file_in = NULL, *file_out = NULL;
    int to_be_filtered = 0;
    int rc = args_handler(argc, argv, &file_in, &file_out, &to_be_filtered);
    ck_assert_int_eq(rc, ARGS_COUNT_ERROR);
}
END_TEST

START_TEST(test_args_hander_more_argc)
{
    int argc = 5;
    char *argv[] = {"path/to/file", "./unit_tests/data/neg_01_in.txt", "./unit_tests/data/neg_01_output.txt"}, *file_in = NULL, *file_out = NULL;
    int to_be_filtered = 0;
    int rc = args_handler(argc, argv, &file_in, &file_out, &to_be_filtered);
    ck_assert_int_eq(rc, ARGS_COUNT_ERROR);
}
END_TEST

START_TEST(test_args_hander_null_argv)
{
    int argc = 3;
    int to_be_filtered = 0;
    char *file_in = NULL, *file_out = NULL;
    int rc = args_handler(argc, NULL, &file_in, &file_out, &to_be_filtered);
    ck_assert_int_eq(rc, ARGS_POINTER_ERROR);
}
END_TEST

START_TEST(test_args_hander_null_file_in)
{
    int argc = 4;
    char *argv[] = {"path/to/file", "./unit_tests/data/neg_01_in.txt", "./unit_tests/data/neg_01_output.txt", "f"}, *file_out = NULL;
    int to_be_filtered = 0;
    int rc = args_handler(argc, argv, NULL, &file_out, &to_be_filtered);
    ck_assert_int_eq(rc, ARGS_POINTER_ERROR);
}
END_TEST

START_TEST(test_args_hander_null_file_out)
{
    int argc = 4;
    char *argv[] = {"path/to/file", "./unit_tests/data/neg_01_in.txt", "./unit_tests/data/neg_01_output.txt", "f"}, *file_in = NULL;
    int to_be_filtered = 0;
    int rc = args_handler(argc, argv, &file_in, NULL, &to_be_filtered);
    ck_assert_int_eq(rc, ARGS_POINTER_ERROR);
}
END_TEST

START_TEST(test_args_hander_null_filter)
{
    int argc = 4;
    char *argv[] = {"path/to/file", "./unit_tests/data/neg_01_in.txt", "./unit_tests/data/neg_01_output.txt", "f"}, *file_in = NULL, *file_out = NULL;
    int rc = args_handler(argc, argv, &file_in, &file_out, NULL);
    ck_assert_int_eq(rc, ARGS_POINTER_ERROR);
}
END_TEST

START_TEST(test_args_hander_false_filter)
{
    int argc = 4;
    char *argv[] = {"path/to/file", "./unit_tests/data/neg_01_in.txt", "./unit_tests/data/neg_01_output.txt", "a"}, *file_in = NULL, *file_out = NULL;
    int to_be_filtered = 0;
    int rc = args_handler(argc, argv, &file_in, &file_out, &to_be_filtered);
    ck_assert_int_eq(rc, ARG_LETTER_ERROR);
}
END_TEST

START_TEST(test_args_handler_three_args)
{
    int argc = 3;
    char *argv[] = {"path/to/file", "./unit_tests/data/pos_01_in.txt", "./unit_tests/data/pos_01_output.txt"}, *file_in = NULL, *file_out = NULL;
    int to_be_filtered = 0;
    int rc = args_handler(argc, argv, &file_in, &file_out, &to_be_filtered);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(to_be_filtered, 0);
    ck_assert_str_eq(argv[1], file_in);
    ck_assert_str_eq(argv[2], file_out);
}
END_TEST

START_TEST(test_args_handler_four_args)
{
    int argc = 4;
    char *argv[] = {"path/to/file", "./unit_tests/data/pos_01_in.txt", "./unit_tests/data/pos_01_output.txt", "f"}, *file_in = NULL, *file_out = NULL;
    int to_be_filtered = 0;
    int rc = args_handler(argc, argv, &file_in, &file_out, &to_be_filtered);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(to_be_filtered, 1);
    ck_assert_str_eq(argv[1], file_in);
    ck_assert_str_eq(argv[2], file_out);
}
END_TEST

Suite *args_handler_suite(void)
{
    Suite *s;
    TCase *tc_neg, *tc_pos;

    s = suite_create("args_handler");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_args_handler_less_argc);
    tcase_add_test(tc_neg, test_args_hander_more_argc);
    tcase_add_test(tc_neg, test_args_hander_null_argv);
    tcase_add_test(tc_neg, test_args_hander_null_file_in);
    tcase_add_test(tc_neg, test_args_hander_null_file_out);
    tcase_add_test(tc_neg, test_args_hander_null_filter);
    tcase_add_test(tc_neg, test_args_hander_false_filter);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_args_handler_four_args);
    tcase_add_test(tc_pos, test_args_handler_three_args);

    suite_add_tcase(s, tc_neg);
    suite_add_tcase(s, tc_pos);
    return s;
}