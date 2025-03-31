#include "lab_03_06_02.h"

int main(void)
{
    int exit_code = EXIT_SUCCESS;
    size_t n, m;
    matrix_t array;
    if (input(&n, &m) == EXIT_FAILURE)
    {
        printf("Bad input\n");
        exit_code = EXIT_FAILURE;
    }
    else
    {
        gen_matrix(array, n, m);
        output(array, n, m);
    }
    return exit_code;
}
