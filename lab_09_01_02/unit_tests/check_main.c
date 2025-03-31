#include <stdlib.h>
#include <check.h>

typedef Suite *(*suite_maker)(void);

Suite *take_args_suite(void);
Suite *find_suite(void);
Suite *sort_suite(void);

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
    failed_cnt += do_tests(take_args_suite);
    failed_cnt += do_tests(find_suite);
    failed_cnt += do_tests(sort_suite);
    return failed_cnt;
}
