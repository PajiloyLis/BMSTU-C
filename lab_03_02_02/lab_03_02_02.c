#include "lab_03_02_02.h"

int main(void)
{
    int exit_code = EXIT_SUCCESS;
    size_t n, m;
    matrix_t array;
    if (input(&n, &m, array) == EXIT_FAILURE)
    {
        printf("Bad input\n");
        exit_code = EXIT_FAILURE;
    }
    else
    {
        matrix_ans_t ans;
        size_t new_n = 0;
        solve(array, n, m, ans, &new_n);
        output(ans, new_n, m);
    }
    return exit_code;
}
