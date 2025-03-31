#include "fileio.h"

int get_from_pos(good *val, int pos, FILE *f)
{
    int return_code = EXIT_SUCCESS;
    if (!f)
    {
        return_code = NULL_POINTER_ERROR;
    }
    else
    {
        return_code = fseek(f, pos * sizeof(good), SEEK_SET);
        if (return_code == EXIT_SUCCESS)
        {
            if (fread(val, sizeof(good), 1, f) != 1)
            {
                return_code = FILE_READING_ERROR;
            }
        }
        else
        {
            return_code = FILE_READING_ERROR;
        }
    }
    return return_code;
}

int set_by_pos(good *val, int pos, FILE *f)
{
    int return_code = EXIT_SUCCESS;
    if (!f)
    {
        return_code = EXIT_FAILURE;
    }
    else
    {
        return_code = fseek(f, sizeof(good) * pos, SEEK_SET);
        if (return_code == EXIT_SUCCESS)
        {
            if (fwrite(val, sizeof(good), 1, f) != 1)
            {
                return_code = FILE_WRITING_ERROR;
            }
        }
        else
        {
            return_code = FILE_WRITING_ERROR;
        }
    }
    return return_code;
}

void output(good *val)
{
    printf("%s\n%s\n%" PRIu32 "\n%" PRIu32 "\n", val->name, val->maker, val->cost, val->count);
}

int input(good *val)
{
    int return_code = EXIT_SUCCESS;
    if (scanf("%s %s %" PRIu32 " %" PRIu32 "\n", val->name, val->maker, &val->cost, &val->count) != 4)
    {
        return_code = INPUT_ERROR;
    }
    return return_code;
}
