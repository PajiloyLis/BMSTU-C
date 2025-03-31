#include "fileio.h"

int read_numbers(char *file_name, int *p_b, int *p_e)
{
    int return_code = EXIT_SUCCESS;
    if (p_b == NULL || p_e == NULL)
    {
        return_code = ARRAY_POINTER_ERROR;
    }
    else
    {
        FILE *f = fopen(file_name, "r");
        if (!f)
        {
            return_code = FILE_OPEN_ERROR;
        }
        else
        {
            for (int *p_cur = p_b; p_cur != p_e && return_code == EXIT_SUCCESS; ++p_cur)
            {
                if (fscanf(f, "%d\n", p_cur) != 1)
                {
                    return_code = FILE_READING_ERROR;
                }
            }
            fclose(f);
        }
    }
    return return_code;
}

int count_records_cnt(char *file_name, size_t *n)
{
    int return_code = EXIT_SUCCESS;
    if (n == NULL)
        return_code = COUNTER_POINTER_ERROR;
    else
    {
        FILE *f = fopen(file_name, "r");
        if (!f)
        {
            return_code = FILE_OPEN_ERROR;
        }
        else
        {
            int buf;
            if (fscanf(f, "%d\n", &buf) == 1)
            {
                (*n)++;
                while (fscanf(f, "%d\n", &buf) == 1)
                {
                    (*n)++;
                }
                return_code = (feof(f) ? EXIT_SUCCESS : FILE_READING_ERROR);
            }
            else
            {
                return_code = (feof(f) ? FILE_EMPTY_ERROR : FILE_READING_ERROR);
            }
            fclose(f);
        }
    }
    return return_code;
}

int output(char *file_name, int *p_b, int *p_e)
{
    int return_code = EXIT_SUCCESS;
    if (p_b == NULL || p_e == NULL)
        return_code = ARRAY_POINTER_ERROR;
    else
    {
        FILE *f = fopen(file_name, "w");
        if (!f)
        {
            return_code = FILE_OPEN_ERROR;
        }
        else
        {
            for (int *p_cur = p_b; p_cur != p_e; ++p_cur)
            {
                fprintf(f, "%d ", *p_cur);
            }
            fclose(f);
        }
    }
    return return_code;
}
