#include "algorithms.h"
#include <check.h>

START_TEST(test_key_null_pb_src)
{
    int pb_src[] = {1, 2, 3, 4, 5}, *pe_src = pb_src + 5, *pb_dst = pb_src, *pe_dst = pe_src;
    int rc = key(NULL, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, NULL_FILTER_POINTER_ERROR);
}
END_TEST

START_TEST(test_key_null_pe_src)
{
    int pb_src[] = {1, 2, 3, 4, 5}, *pe_src = pb_src + 5, *pb_dst = pb_src, *pe_dst = pe_src;
    int rc = key(pb_src, NULL, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, NULL_FILTER_POINTER_ERROR);
}
END_TEST

START_TEST(test_key_null_pb_dst)
{
    int pb_src[] = {1, 2, 3, 4, 5}, *pe_src = pb_src + 5, *pe_dst = pe_src;
    int rc = key(pb_src, pe_src, NULL, &pe_dst);
    ck_assert_int_eq(rc, NULL_FILTER_POINTER_ERROR);
}
END_TEST

START_TEST(test_key_null_pe_dst)
{
    int pb_src[] = {1, 2, 3, 4, 5}, *pe_src = pb_src + 5, *pb_dst = pb_src;
    int rc = key(pb_src, pe_src, &pb_dst, NULL);
    ck_assert_int_eq(rc, NULL_FILTER_POINTER_ERROR);
}
END_TEST

START_TEST(test_key_p_e_less_p_b)
{
    int pb_src[] = {1, 2, 3, 4, 5}, *pe_src = pb_src + 5, *pb_dst = pb_src, *pe_dst = pe_src;
    int rc = key(pe_src, pb_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, ARRAY_POINTERS_ERROR);
}
END_TEST

START_TEST(test_key_empty_array_error)
{
    int pb_src[] = {-1, 2, 3, 4, 5}, *pe_src = pb_src + 5, *pb_dst = pb_src, *pe_dst = pe_src;
    int rc = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, EMPTY_ARRAY_ERROR);
}
END_TEST

START_TEST(test_key_full_array)
{
    int pb_src[] = {1, 2, 3, 4, 5}, *pe_src = pb_src + 5, *pb_dst = pb_src, *pe_dst = pe_src;
    int rc = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    for (int *p_cur = pb_dst; p_cur != pe_dst; ++p_cur)
    {
        ck_assert_int_eq(*p_cur, *(pb_src + (p_cur - pb_dst)));
    }
    free(pb_dst);
}
END_TEST

Suite *key_suite(void)
{
    Suite *s;
    TCase *tc_neg, *tc_pos;

    s = suite_create("key");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_key_empty_array_error);
    tcase_add_test(tc_neg, test_key_null_pb_dst);
    tcase_add_test(tc_neg, test_key_null_pb_src);
    tcase_add_test(tc_neg, test_key_null_pe_dst);
    tcase_add_test(tc_neg, test_key_null_pe_src);
    tcase_add_test(tc_neg, test_key_p_e_less_p_b);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_key_full_array);

    suite_add_tcase(s, tc_neg);
    suite_add_tcase(s, tc_pos);
    return s;
}