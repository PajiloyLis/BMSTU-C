#include <stdlib.h>
#include <check.h>

int compare_int(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

typedef Suite *(*suite_maker)(void);

Suite *calc_value_suite(void);
Suite *calc_derivative_suite(void);
Suite *calc_sum_coef_suite(void);
Suite *split_coefs_suite(void);

int do_tests(suite_maker func)
{
    int failed_cnt = 0;
    Suite *s;
    SRunner *runner;

    s = func();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);
    failed_cnt += srunner_ntests_failed(runner);
    srunner_free(runner);
    return failed_cnt;
}

int main(void)
{
    int failed_cnt = 0;
    failed_cnt += do_tests(calc_value_suite);
    failed_cnt += do_tests(calc_derivative_suite);
    failed_cnt += do_tests(calc_sum_coef_suite);
    failed_cnt += do_tests(split_coefs_suite);
    return failed_cnt;
}