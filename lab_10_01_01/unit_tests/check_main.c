#include <stdlib.h>
#include <check.h>

int compare_int(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

typedef Suite *(*suite_maker)(void);

Suite *insert_suite(void);
Suite *find_suite(void);
Suite *sorted_merge_suite(void);
Suite *sort_suite(void);
Suite *front_back_split_suite(void);
Suite *remove_duplicates_suite(void);

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
    failed_cnt += do_tests(front_back_split_suite);
    failed_cnt += do_tests(remove_duplicates_suite);
    failed_cnt += do_tests(sorted_merge_suite);
    failed_cnt += do_tests(sort_suite);
    failed_cnt += do_tests(find_suite);
    failed_cnt += do_tests(insert_suite);
    return failed_cnt;
}