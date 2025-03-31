#include "lab_03_03_02.h"

int main(void)
{
    int exit_code = EXIT_SUCCESS;
    size_t n, m;
    matrix array;
    if (input(&n, &m, array) == EXIT_FAILURE)
    {
        printf("Bad input\n");
        exit_code = EXIT_FAILURE;
    }
    else
    {
        isort(array, n, m);
        output(array, n, m);
    }
    return exit_code;
}
