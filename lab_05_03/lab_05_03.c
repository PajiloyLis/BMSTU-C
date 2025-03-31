#include "lab_05_03.h"

int main(int argc, char **argv)
{
    int exit_code = EXIT_SUCCESS;
    char *mode = NULL, *file_name = NULL;
    size_t cnt = 0;
    exit_code = take_agrs(argc, argv, &mode, &cnt, &file_name);
    if (exit_code == EXIT_SUCCESS)
    {
        exit_code = solution(mode, file_name, cnt);
    }
    return exit_code;
}
