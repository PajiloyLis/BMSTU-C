#include "fileio.h"

int input_element(object_t *record, FILE *f);

void eof_handler(int *return_code, FILE *f);

void print_object(object_t *elem);

int input(object_t **array, size_t *n, size_t *total_n, char *file_name)
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
        if ((return_code = input_element((*array) + *n, f)) == EXIT_SUCCESS)
        {
            (*n)++;
            if (*n == *total_n)
                return_code = array_reallocate(array, total_n);
            while (return_code == EXIT_SUCCESS && (return_code = input_element((*array) + *n, f)) == EXIT_SUCCESS)
            {
                (*n)++;
                if (*n == *total_n)
                    return_code = array_reallocate(array, total_n);
            }
            if (return_code != NEGATIVE_NUMBERS_ERROR)
                return_code = feof(f) ? EXIT_SUCCESS : FILE_READING_ERROR;
        }
        else if (return_code != NEGATIVE_NUMBERS_ERROR)
            return_code = feof(f) ? FILE_EMPTY_ERROR : FILE_READING_ERROR;
        fclose(f);
    }
    return return_code;
}

void output(object_t *array, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        print_object(array + i);
    }
}

void output_by_pointers(object_t *array[], size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        print_object(*(array + i));
    }
}

int input_element(object_t *record, FILE *f)
{
    int return_code = EXIT_SUCCESS;
    record->name = NULL;
    record->name_len = 0;
    size_t memory = 0;
    return_code = (record->name_len = getline(&record->name, &memory, f)) == -1 ? FILE_READING_ERROR : EXIT_SUCCESS;
    if (return_code == EXIT_SUCCESS)
    {
        if (record->name_len == 0)
            return_code = EMPTY_STRING_ERROR;
        else if (record->name[record->name_len - 1] == '\n')
        {
            record->name[--record->name_len] = 0;
            if (record->name_len == 0)
                return_code = EMPTY_STRING_ERROR;
        }
        if (fscanf(f, "%lf\n%lf\n", &(record->mass), &(record->volume)) == 2)
        {
            if (record->mass < EPS || record->volume < EPS)
            {
                return_code = NEGATIVE_NUMBERS_ERROR;
            }
        }
        else
        {
            return_code = FILE_READING_ERROR;
        }
    }
    if (return_code != EXIT_SUCCESS)
        free(record->name);
    return return_code;
}

void print_object(object_t *elem)
{
    printf("%s\n%.6lf\n%.6lf\n", elem->name, elem->mass, elem->volume);
}
