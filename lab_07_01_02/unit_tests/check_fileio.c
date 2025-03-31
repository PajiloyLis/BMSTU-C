#include "fileio.h"
#include <check.h>

START_TEST(test_read_numbers_file_name_error)
{
    char *file_name = "abracadabra";
    int p_b[] = {1, 2, 3, 4, 5};
    int *p_e = p_b + sizeof(p_b)/sizeof(p_b[0]);
    int rc = read_numbers(file_name, p_b, p_e);
    ck_assert_int_eq(rc, FILE_OPEN_ERROR);
}
END_TEST

START_TEST(test_read_numbers_null_p_e)
{
    char *file_name = NULL;
    int p_b[] = {1, 2, 3, 4, 5};
    int rc = read_numbers(file_name, p_b, NULL);
    ck_assert_int_eq(rc, ARRAY_POINTER_ERROR);
}
END_TEST

START_TEST(test_read_numbers_null_p_b)
{
    char *file_name = NULL;
    int p_b[] = {1, 2, 3, 4, 5};
    int *p_e = p_b + sizeof(p_b)/sizeof(p_b[0]);
    int rc = read_numbers(file_name, NULL, p_e);
    ck_assert_int_eq(rc, ARRAY_POINTER_ERROR);
}
END_TEST

START_TEST(test_read_numbers_file_read_error)
{
    char *file_name = "./unit_tests/data/neg_02_in.txt";
    int p_b[] = {1, 2, 3, 4, 5};
    int *p_e = p_b + sizeof(p_b)/sizeof(p_b[0]);
    int rc = read_numbers(file_name, p_b, p_e);
    ck_assert_int_eq(rc, FILE_READING_ERROR);
}
END_TEST

START_TEST(test_read_numbers_read_file)
{
    char *file_name = "./unit_tests/data/pos_02_in.txt";
    int *p_b = malloc(11 * sizeof(int));
    int *p_e = p_b + 11;
    int rc = read_numbers(file_name, p_b, p_e);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    int ans_array[] = {123, 234, 56, 3, 67, 3, -1, 456, 45678, 63, -334};
    for (int i = 0; i < 11; ++i)
    {
        ck_assert_int_eq(*(p_b + i), ans_array[i]);
    }
    free(p_b);
}
END_TEST

START_TEST(test_count_records_cnt_file_name_error)
{
    char *file_name = "abracadabra";
    size_t n = 0;
    int rc = count_records_cnt(file_name, &n);
    ck_assert_int_eq(rc, FILE_OPEN_ERROR);
}
END_TEST

START_TEST(test_count_records_cnt_null_n)
{
    char *file_name = "./unit_tests/data/neg_01_in.txt";
    int rc = count_records_cnt(file_name, NULL);
    ck_assert_int_eq(rc, COUNTER_POINTER_ERROR);
}
END_TEST

START_TEST(test_count_records_cnt_file_reading_error_1)
{
    char *file_name = "./unit_tests/data/neg_02_in.txt";
    size_t n = 0;
    int rc = count_records_cnt(file_name, &n);
    ck_assert_int_eq(rc, FILE_READING_ERROR);
}
END_TEST

START_TEST(test_count_records_cnt_file_reading_error_2)
{
    char *file_name = "./unit_tests/data/neg_03_in.txt";
    size_t n = 0;
    int rc = count_records_cnt(file_name, &n);
    ck_assert_int_eq(rc, FILE_READING_ERROR);
}
END_TEST

START_TEST(test_count_records_cnt_file_empty)
{
    char *file_name = "./unit_tests/data/neg_04_in.txt";
    size_t n = 0;
    int rc = count_records_cnt(file_name, &n);
    ck_assert_int_eq(rc, FILE_EMPTY_ERROR);
}
END_TEST

START_TEST(test_count_records_cnt)
{
    char *file_name = "./unit_tests/data/pos_02_in.txt";
    size_t n = 0;
    int rc = count_records_cnt(file_name, &n);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(n, 11);
}
END_TEST

START_TEST(test_output_null_p_e)
{
    char *file_name = NULL;
    int p_b[] = {1, 2, 3, 4, 5};
    int rc = output(file_name, p_b, NULL);
    ck_assert_int_eq(rc, ARRAY_POINTER_ERROR);
}
END_TEST

START_TEST(test_output_null_p_b)
{
    char *file_name = NULL;
    int p_b[] = {1, 2, 3, 4, 5};
    int *p_e = p_b + sizeof(p_b)/sizeof(p_b[0]);
    int rc = output(file_name, NULL, p_e);
    ck_assert_int_eq(rc, ARRAY_POINTER_ERROR);
}
END_TEST

START_TEST(test_output)
{
    char *file_name = "./unit_tests/data/pos_01_output.txt";
    int p_b[] = {1, 2, 3, 4, 5};
    int *p_e = p_b + sizeof(p_b)/sizeof(p_b[0]);
    int rc = output(file_name, p_b, p_e);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

Suite *read_numbers_suite(void)
{
    Suite *s;
    TCase *tc_neg, *tc_pos;

    s = suite_create("read_numbers");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_read_numbers_file_name_error);
    tcase_add_test(tc_neg, test_read_numbers_null_p_b);
    tcase_add_test(tc_neg, test_read_numbers_null_p_e);
    tcase_add_test(tc_neg, test_read_numbers_file_read_error);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_read_numbers_read_file);

    suite_add_tcase(s, tc_neg);
    suite_add_tcase(s, tc_pos);
    return s;
}

Suite *count_records_suite(void)
{
    Suite *s;
    TCase *tc_neg, *tc_pos;

    s = suite_create("count_records");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_count_records_cnt_file_empty);
    tcase_add_test(tc_neg, test_count_records_cnt_file_name_error);
    tcase_add_test(tc_neg, test_count_records_cnt_file_reading_error_1);
    tcase_add_test(tc_neg, test_count_records_cnt_file_reading_error_2);
    tcase_add_test(tc_neg, test_count_records_cnt_null_n);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_count_records_cnt);

    suite_add_tcase(s, tc_neg);
    suite_add_tcase(s, tc_pos);
    return s;
}

Suite *output_suite(void)
{
    Suite *s;
    TCase *tc_neg, *tc_pos;

    s = suite_create("output");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_output_null_p_e);
    tcase_add_test(tc_neg, test_output_null_p_b);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_output);

    suite_add_tcase(s, tc_neg);
    suite_add_tcase(s, tc_pos);
    return s;
}