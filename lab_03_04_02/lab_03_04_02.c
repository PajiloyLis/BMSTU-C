#include "lab_03_04_02.h"

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
        long long max;
        if (solve(array, n, &max) == EXIT_SUCCESS)
        {
            output(max);
        }
        else
        {
            exit_code = EXIT_FAILURE;
            printf("There are no necessary elements\n");
        }
    }
    return exit_code;
}
