#include "lab_03_01_02.h"

int main(void)
{
    int exit_code = EXIT_SUCCESS;
    size_t n, m;
    matrix_t array;
    if (input(&n, &m, array) == 1)
    {
        printf("Bad input\n");
        exit_code = EXIT_FAILURE;
    }
    else
    {
        int result[SIZE];
        make_array(n, m, array, result);
        output(result, m);
    }
    return exit_code;
}
