#include "args.h"

int args_handler(int argc, char **argv, char **file_in, char **file_out, int *to_be_filtered)
{
    int return_code = EXIT_SUCCESS;
    if (argv == NULL || file_in == NULL || file_out == NULL || to_be_filtered == NULL)
    {
        return_code = ARGS_POINTER_ERROR;
    }
    else if (argc < AGRS_CNT_MIN || argc > ARGS_CNT_MAX)
    {
        return_code = ARGS_COUNT_ERROR;
    }
    else
    {
        *file_in = argv[FILE_IN_NUM];
        *file_out = argv[FILE_OUT_NUM];
        if (argc == ARGS_CNT_MAX)
        {
            if (!strcmp(argv[FILTER_ARG_NUM], "f"))
                *to_be_filtered = 1;
            else
                return_code = ARG_LETTER_ERROR;
        }
    }
    return return_code;
}
