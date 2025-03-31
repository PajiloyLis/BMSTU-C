#include "check_create.h"

START_TEST(test_assoc_array_create)
{
    assoc_array_t map = assoc_array_create();
    ck_assert_ptr_nonnull(map);
    assoc_array_destroy(&map);
    ck_assert_ptr_null(map);
}
END_TEST

Suite *assoc_array_create_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("assoc_array_create");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_assoc_array_create);

    suite_add_tcase(s, tc_pos);
    return s;
}
