#include "args.h"

int take_agrs(int n, char *args[], char **prefix, char **file_name)
{
    int return_code = EXIT_SUCCESS;
    *prefix = NULL;
    *file_name = NULL;
    if (n < 2 || n > 3)
    {
        return_code = ARGS_COUNT_ERROR;
    }
    else
    {
        *file_name = args[ARG_FILE_NUMBER];
        if (n == 3)
        {
            *prefix = args[ARG_PREFIX_NUMBER];
        }
    }
    return return_code;
}
