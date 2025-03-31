#include "fileio.h"

int str_input(char *str, FILE *f, size_t n);

int object_input(object_t *elem, FILE *f);

void eof_handler(int *return_code, FILE *f);

void object_print(object_t *elem);

int input(object_t *array, size_t *n, char *file_name)
{
    int return_code = EXIT_SUCCESS;
    *n = 0;
    FILE *f = fopen(file_name, "r");
    if (!f)
    {
        return_code = FILE_OPEN_ERROR;
    }
    else
    {
        if ((return_code = object_input(array + *n, f)) == EXIT_SUCCESS)
        {
            (*n)++;
            while (*n < MAX_ARAY_SIZE && (return_code = object_input(array + *n, f)) == EXIT_SUCCESS)
            {
                (*n)++;
            }
            if (*n == MAX_ARAY_SIZE)
            {
                return_code = (feof(f) ? EXIT_SUCCESS : ARRAY_SIZE_ERROR);
            }
            else
            {
                eof_handler(&return_code, f);
            }
        }
        fclose(f);
    }
    return return_code;
}

void eof_handler(int *return_code, FILE *f)
{
    if (*return_code != NEGATIVE_NUMBERS_ERROR && *return_code != EXIT_SUCCESS)
    {
        *return_code = (feof(f) ? EXIT_SUCCESS : *return_code);
    }
}

void output(object_t *array, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        object_print(array + i);
    }
}

void output_by_pointers(object_t *array[], size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        object_print(*(array + i));
    }
}

int object_input(object_t *elem, FILE *f)
{
    int return_code = EXIT_SUCCESS;
    return_code = str_input(elem->name, f, NAME_SIZE);
    if (return_code == EXIT_SUCCESS)
    {
        if (fscanf(f, "%lf\n%lf\n", &(elem->mass), &(elem->volume)) == 2)
        {
            if (elem->mass < EPS || elem->volume < EPS)
            {
                return_code = NEGATIVE_NUMBERS_ERROR;
            }
        }
        else
        {
            return_code = FILE_READING_ERROR;
        }
    }
    return return_code;
}

int str_input(char *str, FILE *f, size_t n)
{
    int return_code = EXIT_SUCCESS;
    size_t len;
    char ch;
    if (!fgets(str, n + 1, f))
    {
        return_code = FILE_READING_ERROR;
    }
    else
    {
        len = strlen(str);
        if (len == n && str[len - 1] != '\n')
        {
            ch = getchar();
            if (ch != EOF && ch != '\n')
            {
                return_code = FILE_VALUE_ERROR;
            }
        }
        else if (len == 1)
        {
            return_code = FILE_VALUE_ERROR;
        }
        if (str[len - 1] == '\n')
        {
            str[len - 1] = '\0';
        }
    }
    return return_code;
}

void object_print(object_t *elem)
{
    printf("%s\n%.6lf\n%.6lf\n", elem->name, elem->mass, elem->volume);
}
