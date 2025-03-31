#include "check_create.h"
#include "check_insert.h"
#include "check_remove.h"
#include "check_clear.h"
#include "check_destroy.h"
#include "check_find.h"
#include "check_each.h"
#include "check_max.h"
#include "check_min.h"

typedef Suite *(*suite_maker)(void);

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
    failed_cnt += do_tests(assoc_array_create_suite);
    failed_cnt += do_tests(assoc_array_insert_suite);
    failed_cnt += do_tests(assoc_array_remove_suite);
    failed_cnt += do_tests(assoc_array_clear_suite);
    failed_cnt += do_tests(assoc_array_destroy_suite);
    failed_cnt += do_tests(assoc_array_find_suite);
    failed_cnt += do_tests(assoc_array_each_suite);
    failed_cnt += do_tests(assoc_array_max_suite);
    failed_cnt += do_tests(assoc_array_min_suite);

    return failed_cnt;
}