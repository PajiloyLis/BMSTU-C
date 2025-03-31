#include <check.h>
#include "my_snprintf.h"
#include "stdio.h"
#include <limits.h>

START_TEST(test_snprintf_simple)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "Hello world!"), snprintf(s_2, 100, "Hello world!"));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_trailing_c)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "Hello world%c", '!'), snprintf(s_2, 100, "Hello world%c", '!'));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_middle_c)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "Hello%cworld", ' '), snprintf(s_2, 100, "Hello%cworld", ' '));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_begining_c)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "%cello world", 'H'), snprintf(s_2, 100, "%cello world", 'H'));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_trailing_s)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "Hello, %s", "insane user"), snprintf(s_2, 100, "Hello, %s", "insane user"));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_middle_s)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "Hello, %s world", "beautiful"), snprintf(s_2, 100, "Hello, %s world", "beautiful"));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_begin_s)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "%s New World", "Brave"), snprintf(s_2, 100, "%s New World", "Brave"));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_trailing_d)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "Fahrenheit %d", -451), snprintf(s_2, 100, "Fahrenheit %d", -451));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_middle_d)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "Noon: %dnd Century", 22), snprintf(s_2, 100, "Noon: %dnd Century", 22));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_begin_d)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "%d-th Century Fox", 20), snprintf(s_2, 100, "%d-th Century Fox", 20));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_trailing_o)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "Fahrenheit %o", 451), snprintf(s_2, 100, "Fahrenheit %o", 451));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_middle_o)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "Noon: %ond Century", 22), snprintf(s_2, 100, "Noon: %ond Century", 22));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_begin_o)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "%o-th Century Fox", 20), snprintf(s_2, 100, "%o-th Century Fox", 20));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_trailing_x)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "Fahrenheit %x", 451), snprintf(s_2, 100, "Fahrenheit %x", 451));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_middle_x)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "Noon: %xnd Century", 22), snprintf(s_2, 100, "Noon: %xnd Century", 22));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_begin_x)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "%x-th Century Fox", 20), snprintf(s_2, 100, "%x-th Century Fox", 20));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_trailing_hd)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "Fahrenheit %hd", -451), snprintf(s_2, 100, "Fahrenheit %hd", -451));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_middle_hd)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "Noon: %hdnd Century", 22), snprintf(s_2, 100, "Noon: %hdnd Century", 22));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_begin_hd)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "%hd-th Century Fox", 20), snprintf(s_2, 100, "%hd-th Century Fox", 20));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_trailing_ho)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "Fahrenheit %ho", 451), snprintf(s_2, 100, "Fahrenheit %ho", 451));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_middle_ho)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "Noon: %hond Century", 22), snprintf(s_2, 100, "Noon: %hond Century", 22));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_begin_ho)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "%ho-th Century Fox", 20), snprintf(s_2, 100, "%ho-th Century Fox", 20));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_trailing_hx)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "Fahrenheit %hx", 451), snprintf(s_2, 100, "Fahrenheit %hx", 451));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_middle_hx)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "Noon: %hxnd Century", 22), snprintf(s_2, 100, "Noon: %hxnd Century", 22));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_begin_hx)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "%hx-th Century Fox", 20), snprintf(s_2, 100, "%hx-th Century Fox", 20));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_trailing_ld)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "Fahrenheit %ld", -451L), snprintf(s_2, 100, "Fahrenheit %ld", -451L));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_middle_ld)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "Noon: %ldnd Century", 22L), snprintf(s_2, 100, "Noon: %ldnd Century", 22L));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_begin_ld)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "%ld-th Century Fox", 20L), snprintf(s_2, 100, "%ld-th Century Fox", 20L));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_trailing_lo)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "Fahrenheit %lo", 451L), snprintf(s_2, 100, "Fahrenheit %lo", 451L));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_middle_lo)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "Noon: %lond Century", 22L), snprintf(s_2, 100, "Noon: %lond Century", 22L));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_begin_lo)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "%lo-th Century Fox", 20L), snprintf(s_2, 100, "%lo-th Century Fox", 20L));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_trailing_lx)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "Fahrenheit %lx", 451L), snprintf(s_2, 100, "Fahrenheit %lx", 451L));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_middle_lx)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "Noon: %lxnd Century", 22L), snprintf(s_2, 100, "Noon: %lxnd Century", 22L));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_begin_lx)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "%lx-th Century Fox", 20L), snprintf(s_2, 100, "%lx-th Century Fox", 20L));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_0_n)
{
    ck_assert_int_eq(my_snprintf(NULL, 0, "%lx-th Century Fox", 20L), snprintf(NULL, 0, "%lx-th Century Fox", 20L));
}
END_TEST

START_TEST(test_snprintf_zero_d)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "%d-th Century Fox", 0), snprintf(s_2, 100, "%d-th Century Fox", 0));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_zero_ld)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "%ld-th Century Fox", 0L), snprintf(s_2, 100, "%ld-th Century Fox", 0L));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_zero_hd)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "%hd-th Century Fox", 0), snprintf(s_2, 100, "%hd-th Century Fox", 0));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_zero_o)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "%o-th Century Fox", 0), snprintf(s_2, 100, "%o-th Century Fox", 0));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_zero_ho)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "%ho-th Century Fox", 0), snprintf(s_2, 100, "%ho-th Century Fox", 0));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_zero_lo)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "%lo-th Century Fox", 0L), snprintf(s_2, 100, "%lo-th Century Fox", 0L));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_zero_x)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "%x-th Century Fox", 0), snprintf(s_2, 100, "%x-th Century Fox", 0));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_zero_lx)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "%lx-th Century Fox", 0L), snprintf(s_2, 100, "%lx-th Century Fox", 0L));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_zero_hx)
{
    char s_1[100], s_2[100];
    ck_assert_int_eq(my_snprintf(s_1, 100, "%hx-th Century Fox", 0), snprintf(s_2, 100, "%hx-th Century Fox", 0));
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_min_d)
{
    char s_1[100], s_2[100];
    int n_1 = my_snprintf(s_1, 100, "%d-th Century Fox", INT_MIN), n_2 = snprintf(s_2, 100, "%d-th Century Fox", INT_MIN);
    ck_assert_int_eq(n_1, n_2);
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_max_d)
{
    char s_1[100], s_2[100];
    int n_1 = my_snprintf(s_1, 100, "%d-th Century Fox", INT_MAX), n_2 = snprintf(s_2, 100, "%d-th Century Fox", INT_MAX);
    ck_assert_int_eq(n_1, n_2);
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_min_hd)
{
    char s_1[100], s_2[100];
    int n_1 = my_snprintf(s_1, 100, "%hd-th Century Fox", SHRT_MIN), n_2 = snprintf(s_2, 100, "%hd-th Century Fox", SHRT_MIN);
    ck_assert_int_eq(n_1, n_2);
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_max_hd)
{
    char s_1[100], s_2[100];
    int n_1 = my_snprintf(s_1, 100, "%hd-th Century Fox", SHRT_MAX), n_2 = snprintf(s_2, 100, "%hd-th Century Fox", SHRT_MAX);
    ck_assert_int_eq(n_1, n_2);
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_min_ld)
{
    char s_1[100], s_2[100];
    int n_1 = my_snprintf(s_1, 100, "%ld-th Century Fox", LONG_MIN), n_2 = snprintf(s_2, 100, "%ld-th Century Fox", LONG_MIN);
    ck_assert_int_eq(n_1, n_2);
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_max_ld)
{
    char s_1[100], s_2[100];
    int n_1 = my_snprintf(s_1, 100, "%ld-th Century Fox", LONG_MAX), n_2 = snprintf(s_2, 100, "%ld-th Century Fox", LONG_MAX);
    ck_assert_int_eq(n_1, n_2);
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_min_o)
{
    char s_1[100], s_2[100];
    int n_1 = my_snprintf(s_1, 100, "%o-th Century Fox", INT_MIN), n_2 = snprintf(s_2, 100, "%o-th Century Fox", INT_MIN);
    ck_assert_int_eq(n_1, n_2);
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_max_o)
{
    char s_1[100], s_2[100];
    int n_1 = my_snprintf(s_1, 100, "%o-th Century Fox", INT_MAX), n_2 = snprintf(s_2, 100, "%o-th Century Fox", INT_MAX);
    ck_assert_int_eq(n_1, n_2);
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_min_ho)
{
    char s_1[100], s_2[100];
    int n_1 = my_snprintf(s_1, 100, "%ho-th Century Fox", SHRT_MIN), n_2 = snprintf(s_2, 100, "%ho-th Century Fox", SHRT_MIN);
    ck_assert_int_eq(n_1, n_2);
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_max_ho)
{
    char s_1[100], s_2[100];
    int n_1 = my_snprintf(s_1, 100, "%ho-th Century Fox", SHRT_MAX), n_2 = snprintf(s_2, 100, "%ho-th Century Fox", SHRT_MAX);
    ck_assert_int_eq(n_1, n_2);
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_min_lo)
{
    char s_1[100], s_2[100];
    int n_1 = my_snprintf(s_1, 100, "%lo-th Century Fox", LONG_MIN), n_2 = snprintf(s_2, 100, "%lo-th Century Fox", LONG_MIN);
    ck_assert_int_eq(n_1, n_2);
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_max_lo)
{
    char s_1[100], s_2[100];
    int n_1 = my_snprintf(s_1, 100, "%lo-th Century Fox", LONG_MAX), n_2 = snprintf(s_2, 100, "%lo-th Century Fox", LONG_MAX);
    ck_assert_int_eq(n_1, n_2);
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_min_x)
{
    char s_1[100], s_2[100];
    int n_1 = my_snprintf(s_1, 100, "%x-th Century Fox", INT_MIN), n_2 = snprintf(s_2, 100, "%x-th Century Fox", INT_MIN);
    ck_assert_int_eq(n_1, n_2);
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_max_x)
{
    char s_1[100], s_2[100];
    int n_1 = my_snprintf(s_1, 100, "%x-th Century Fox", INT_MAX), n_2 = snprintf(s_2, 100, "%x-th Century Fox", INT_MAX);
    ck_assert_int_eq(n_1, n_2);
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_min_hx)
{
    char s_1[100], s_2[100];
    int n_1 = my_snprintf(s_1, 100, "%hx-th Century Fox", SHRT_MIN), n_2 = snprintf(s_2, 100, "%hx-th Century Fox", SHRT_MIN);
    ck_assert_int_eq(n_1, n_2);
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_max_hx)
{
    char s_1[100], s_2[100];
    int n_1 = my_snprintf(s_1, 100, "%hx-th Century Fox", SHRT_MAX), n_2 = snprintf(s_2, 100, "%hx-th Century Fox", SHRT_MAX);
    ck_assert_int_eq(n_1, n_2);
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_min_lx)
{
    char s_1[100], s_2[100];
    int n_1 = my_snprintf(s_1, 100, "%lx-th Century Fox", LONG_MIN), n_2 = snprintf(s_2, 100, "%lx-th Century Fox", LONG_MIN);
    ck_assert_int_eq(n_1, n_2);
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

START_TEST(test_snprintf_max_lx)
{
    char s_1[100], s_2[100];
    int n_1 = my_snprintf(s_1, 100, "%lx-th Century Fox", LONG_MAX), n_2 = snprintf(s_2, 100, "%lx-th Century Fox", LONG_MAX);
    ck_assert_int_eq(n_1, n_2);
    ck_assert_str_eq(s_1, s_2);
}
END_TEST

// START_TEST(test_snprintf_less_then_min_d)
// {
//     char s_1[100], s_2[100];
//     int n_1 = my_snprintf(s_1, 100, "%d-th Century Fox", (long long)(INT_MIN - 1)), n_2 = snprintf(s_2, 100, "%d-th Century Fox", (long long)(INT_MIN - 1));
//     ck_assert_int_eq(n_1, n_2);
//     ck_assert_str_eq(s_1, s_2);
// }
// END_TEST

// START_TEST(test_snprintf_more_then_max_d)
// {
//     char s_1[100], s_2[100];
//     int n_1 = my_snprintf(s_1, 100, "%d-th Century Fox", (long long)(INT_MAX + 1)), n_2 = snprintf(s_2, 100, "%d-th Century Fox", (long long)(INT_MAX + 1));
//     ck_assert_int_eq(n_1, n_2);
//     ck_assert_str_eq(s_1, s_2);
// }
// END_TEST

// START_TEST(test_snprintf_n_less_then_format_len)
// {
//     char s_1[100], s_2[100];
//     int n_1 = my_snprintf(s_1, 13, "Fahrenheit %d", -451), n_2 = snprintf(s_2, 13, "Fahrenheit %d", -451);
//     ck_assert_int_eq(n_1, n_2);
//     ck_assert_str_eq(s_1, s_2);
// }
// END_TEST

Suite *snprintf_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("snprintf");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_snprintf_simple);
    tcase_add_test(tc_pos, test_snprintf_trailing_c);
    tcase_add_test(tc_pos, test_snprintf_middle_c);
    tcase_add_test(tc_pos, test_snprintf_begining_c);
    tcase_add_test(tc_pos, test_snprintf_trailing_s);
    tcase_add_test(tc_pos, test_snprintf_middle_s);
    tcase_add_test(tc_pos, test_snprintf_begin_s);
    tcase_add_test(tc_pos, test_snprintf_trailing_d);
    tcase_add_test(tc_pos, test_snprintf_middle_d);
    tcase_add_test(tc_pos, test_snprintf_begin_d);
    tcase_add_test(tc_pos, test_snprintf_trailing_o);
    tcase_add_test(tc_pos, test_snprintf_middle_o);
    tcase_add_test(tc_pos, test_snprintf_begin_o);
    tcase_add_test(tc_pos, test_snprintf_trailing_x);
    tcase_add_test(tc_pos, test_snprintf_middle_x);
    tcase_add_test(tc_pos, test_snprintf_begin_x);
    tcase_add_test(tc_pos, test_snprintf_trailing_hd);
    tcase_add_test(tc_pos, test_snprintf_middle_hd);
    tcase_add_test(tc_pos, test_snprintf_begin_hd);
    tcase_add_test(tc_pos, test_snprintf_trailing_ho);
    tcase_add_test(tc_pos, test_snprintf_middle_ho);
    tcase_add_test(tc_pos, test_snprintf_begin_ho);
    tcase_add_test(tc_pos, test_snprintf_trailing_hx);
    tcase_add_test(tc_pos, test_snprintf_middle_hx);
    tcase_add_test(tc_pos, test_snprintf_begin_hx);
    tcase_add_test(tc_pos, test_snprintf_trailing_ld);
    tcase_add_test(tc_pos, test_snprintf_middle_ld);
    tcase_add_test(tc_pos, test_snprintf_begin_ld);
    tcase_add_test(tc_pos, test_snprintf_trailing_lo);
    tcase_add_test(tc_pos, test_snprintf_middle_lo);
    tcase_add_test(tc_pos, test_snprintf_begin_lo);
    tcase_add_test(tc_pos, test_snprintf_trailing_lx);
    tcase_add_test(tc_pos, test_snprintf_middle_lx);
    tcase_add_test(tc_pos, test_snprintf_begin_lx);
    tcase_add_test(tc_pos, test_snprintf_0_n);
    tcase_add_test(tc_pos, test_snprintf_zero_d);
    tcase_add_test(tc_pos, test_snprintf_zero_ld);
    tcase_add_test(tc_pos, test_snprintf_zero_hd);
    tcase_add_test(tc_pos, test_snprintf_zero_o);
    tcase_add_test(tc_pos, test_snprintf_zero_ho);
    tcase_add_test(tc_pos, test_snprintf_zero_lo);
    tcase_add_test(tc_pos, test_snprintf_zero_x);
    tcase_add_test(tc_pos, test_snprintf_zero_lx);
    tcase_add_test(tc_pos, test_snprintf_zero_hx);
    tcase_add_test(tc_pos, test_snprintf_max_d);
    tcase_add_test(tc_pos, test_snprintf_min_d);
    tcase_add_test(tc_pos, test_snprintf_max_hd);
    tcase_add_test(tc_pos, test_snprintf_min_hd);
    tcase_add_test(tc_pos, test_snprintf_max_ld);
    tcase_add_test(tc_pos, test_snprintf_min_ld);
    tcase_add_test(tc_pos, test_snprintf_max_o);
    tcase_add_test(tc_pos, test_snprintf_min_o);
    tcase_add_test(tc_pos, test_snprintf_max_ho);
    tcase_add_test(tc_pos, test_snprintf_min_ho);
    tcase_add_test(tc_pos, test_snprintf_max_lo);
    tcase_add_test(tc_pos, test_snprintf_min_lo);
    tcase_add_test(tc_pos, test_snprintf_max_x);
    tcase_add_test(tc_pos, test_snprintf_min_x);
    tcase_add_test(tc_pos, test_snprintf_max_hx);
    tcase_add_test(tc_pos, test_snprintf_min_hx);
    tcase_add_test(tc_pos, test_snprintf_max_lx);
    tcase_add_test(tc_pos, test_snprintf_min_lx);
    // tcase_add_test(tc_pos, test_snprintf_less_then_min_d);
    // tcase_add_test(tc_pos, test_snprintf_more_then_max_d);
    // tcase_add_test(tc_pos, test_snprintf_n_less_then_format_len);

    suite_add_tcase(s, tc_pos);

    return s;
}
