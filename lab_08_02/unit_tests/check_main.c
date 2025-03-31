#include <stdlib.h>
#include <check.h>

typedef Suite *(*suite_maker)(void);

Suite *matrix_alloc_suite(void);
Suite *matrix_algo_suite(void);

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
    failed_cnt += do_tests(matrix_alloc_suite);
    failed_cnt += do_tests(matrix_algo_suite);
    return failed_cnt;
}