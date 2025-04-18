#include <stdlib.h>
#include <check.h>

typedef Suite *(*suite_maker)(void);

Suite *args_handler_suite(void);
Suite *read_numbers_suite(void);
Suite *count_records_suite(void);
Suite *output_suite(void);
Suite *key_suite(void);
Suite *mysort_suite(void);

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
    failed_cnt += do_tests(args_handler_suite);
    failed_cnt += do_tests(read_numbers_suite);
    failed_cnt += do_tests(count_records_suite);
    failed_cnt += do_tests(output_suite);
    failed_cnt += do_tests(key_suite);
    failed_cnt += do_tests(mysort_suite);
    return failed_cnt;
}
