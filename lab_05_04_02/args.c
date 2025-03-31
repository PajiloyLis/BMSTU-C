#include "args.h"

int check_correct_args(char *arg);

int take_agrs(int n, char *args[], char **mode, char **third_param, char **file_name)
{
    int return_code = EXIT_SUCCESS;
    *third_param = NULL;
    *mode = NULL;
    *file_name = NULL;
    if (n < 3 || n > 4)
    {
        return_code = FAIL;
    }
    else
    {
        return_code = check_correct_args(args[ARG_LETTER_NUMBER]);
        if (return_code == EXIT_SUCCESS)
        {
            *file_name = args[ARG_FILE_NUMBER];
            *mode = args[ARG_LETTER_NUMBER];
            if (strcmp(*mode, "ab"))
            {
                if (n == 4)
                    *third_param = args[ARG_THIRD_NUMBER];
                else
                    return_code = FAIL;
            }
            else if (n == 4)
            {
                return_code = FAIL;
            }
        }
    }
    return return_code;
}

int check_correct_args(char *arg)
{
    int return_code = FAIL;
    char correct_args[][ARG_LETER_LENGTH] = { "sb", "fb", "ab" };
    for (size_t i = 0; i < sizeof(correct_args) / (ARG_LETER_LENGTH * sizeof(char)) && return_code; ++i)
    {
        if (!strcmp(arg, correct_args[i]))
        {
            return_code = EXIT_SUCCESS;
        }
    }
    return return_code;
}
