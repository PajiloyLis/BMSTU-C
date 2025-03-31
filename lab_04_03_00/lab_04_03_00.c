#include "lab_04_03_00.h"

int main(void)
{
    int exit_code = EXIT_SUCCESS;
    char string[SIZE + 1];
    if (input(string) == EXIT_FAILURE)
    {
        exit_code = EXIT_FAILURE;
    }
    else
    {
        char ans[SIZE + 1] = "";
        exit_code = solution(string, ans);
        if (exit_code == EXIT_SUCCESS)
        {
            output(ans);
        }
    }
    return exit_code;
}
