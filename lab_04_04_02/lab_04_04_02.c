#include "lab_04_04_02.h"

int main(void)
{
    int exit_code = EXIT_SUCCESS;
    char string[SIZE + 1] = "";
    if (input(string) == EXIT_FAILURE)
    {
        exit_code = EXIT_FAILURE;
    }
    else
    {
        if (solve(string) == TRUE)
        {
            output("YES");
        }
        else
        {
            output("NO");
        }
    }
    return exit_code;
}
