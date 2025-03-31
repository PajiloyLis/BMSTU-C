#include "lab_04_02_02.h"

int main(void)
{
    int exit_code = EXIT_SUCCESS;
    char str_1[SIZE + 1], str_2[SIZE + 1];
    if (input(str_1) == EXIT_FAILURE || input(str_2) == EXIT_FAILURE)
    {
        exit_code = EXIT_FAILURE;
    }
    else
    {
        char ans[SIZE + 1][WORD_SIZE * 2];
        size_t ans_n = 0;
        exit_code = solution(str_1, str_2, ans, &ans_n);
        if (exit_code == EXIT_SUCCESS)
        {
            output(ans, ans_n);
        }
    }
    return exit_code;
}
