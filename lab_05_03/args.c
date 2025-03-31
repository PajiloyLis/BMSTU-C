#include "args.h"

int check_correct_args(char *arg);

int take_agrs(int n, char *args[], char **mode, size_t *cnt, char **file_name)
{
    int return_code = EXIT_SUCCESS;
    *cnt = 0;
    *mode = NULL;
    *file_name = NULL;
    if (n < 3 || n > 4)
    {
        return_code = ARGS_COUNT_ERROR;
    }
    else
    {
        return_code = check_correct_args(args[ARG_LETTER_NUMBER]);
        if (return_code == EXIT_SUCCESS)
        {
            *file_name = args[ARG_FILE_NUMBER];
            *mode = args[ARG_LETTER_NUMBER];
            if (!strcmp(*mode, "c"))
            {
                *cnt = strtol(args[ARG_NUMBERS_CNT_NUMBER], NULL, BASE);
                if (!(*cnt))
                {
                    return_code = ARGS_NUMBERS_CNT_ERROR;
                }
                *file_name = args[ARG_FILE_NUMBER_C];
            }
        }
    }
    return return_code;
}

int check_correct_args(char *arg)
{
    int return_code = ARGS_NAME_ERROR;
    char correct_args[][ARG_LETER_LENGTH] = { "c", "p", "s" };
    for (size_t i = 0; i < sizeof(correct_args) / (ARG_LETER_LENGTH * sizeof(char)) && return_code; ++i)
    {
        if (!strcmp(arg, correct_args[i]))
        {
            return_code = EXIT_SUCCESS;
        }
    }
    return return_code;
}
