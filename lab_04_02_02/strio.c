#include "strio.h"

int input(char *str)
{
    int return_code = EXIT_SUCCESS;
    int len, ch;
    if (!fgets(str, SIZE + 1, stdin))
    {
        return_code = EXIT_FAILURE;
    }
    else
    {
        len = strlen(str);
        if (len == SIZE && str[len - 1] != '\n')
        {
            ch = getchar();
            if (ch != EOF || ch != '\n')
            {
                return_code = EXIT_FAILURE;
            }
        }
    }
    return return_code;
}

void output(char str[][WORD_SIZE * 2], size_t n)
{
    puts("Result:");
    for (size_t i = 0; i < n; ++i)
    {
        puts(*(str + i));
    }
}
