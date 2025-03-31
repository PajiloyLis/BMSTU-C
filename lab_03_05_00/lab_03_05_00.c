#include "lab_03_05_00.h"

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
        matrix_cord cord;
        size_t cord_n = 0;
        long long primes[SIZE * SIZE];
        if (solution(array, n, m, cord, &cord_n, primes) == EXIT_SUCCESS)
        {
            output(array, n, m);
        }
        else
        {
            exit_code = EXIT_FAILURE;
            printf("There are no necessary elements\n");
        }
    }
    return exit_code;
}
