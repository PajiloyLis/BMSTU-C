#include "lab_05_02_02.h"

int main(int argc, char **argv)
{
    int exit_code = EXIT_SUCCESS;
    double variance = 0;
    if (argc != 2)
    {
        exit_code = EXIT_FAILURE;
    }
    else
    {
        exit_code = calc_variance(argv[1], &variance);
    }
    output(exit_code, variance);
    return exit_code;
}
