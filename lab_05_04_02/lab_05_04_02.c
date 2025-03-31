#include "lab_05_04_02.h"

int main(int argc, char **argv)
{
    int exit_code = EXIT_SUCCESS;
    char *mode = NULL, *file_name = NULL, *third_param = NULL;
    good good_2;
    good good_1;
    exit_code = take_agrs(argc, argv, &mode, &third_param, &file_name);
    if (exit_code == EXIT_SUCCESS)
    {
        exit_code = solution(mode, third_param, file_name, &good_1, &good_2);
    }
    return exit_code;
}
