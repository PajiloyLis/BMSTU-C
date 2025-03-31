#include "lab_05_01_02.h"

int main(void)
{
    int exit_code = EXIT_SUCCESS;
    int ans = 0;
    exit_code = process(stdin, &ans);
    output(exit_code, ans);
    return exit_code;
}
