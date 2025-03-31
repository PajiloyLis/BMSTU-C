#include <stdlib.h>
#include <stdio.h>

#define WORD_SIZE 16
#define ARRAY_SIZE 100

#define FILE_OPEN_ERROR -1
#define FILE_EMPTY -2
#define FILE_READING_ERROR -3

struct node
{
    char name[WORD_SIZE + 1], surname[WORD_SIZE + 1], third_name[WORD_SIZE + 1];
    long long phone;
};

int read_node(FILE *f, struct node *cur)
{
    int return_code = EXIT_SUCCESS;
    return_code = (fscanf(f, "%s", cur->name) != 1 ? FILE_READING_ERROR : EXIT_SUCCESS);
    if (return_code == EXIT_SUCCESS)
    {
        return_code = (fscanf(f, "%s", cur->surname) != 1 ? FILE_READING_ERROR : EXIT_SUCCESS);
    }
    if (return_code == EXIT_SUCCESS)
    {
        return_code = (fscanf(f, "%s", cur->third_name) != 1 ? FILE_READING_ERROR : EXIT_SUCCESS);
    }
    if (return_code == EXIT_SUCCESS)
    {
        return_code = (fscanf(f, "%lld", &(cur->phone)) != 1 ? FILE_READING_ERROR : EXIT_SUCCESS);
    }
    return return_code;
}

int file_read(char *file_name, struct node *array, size_t *n)
{
    int return_code = EXIT_SUCCESS;
    FILE *f = fopen(file_name, "r");
    if (!f)
    {
        return_code = FILE_OPEN_ERROR;
    }
    else
    {
        *n = 0;
        return_code = read_node(f, array);
        if (return_code == EXIT_SUCCESS)
        {
            *n = 1;
            while (return_code == EXIT_SUCCESS)
            {
                return_code = read_node(f, array + (*n));
                *n += (return_code == EXIT_SUCCESS ? 1 : 0);
            }
            return_code = (feof(f) ? EXIT_SUCCESS : FILE_READING_ERROR);
        }
        else
        {
            return_code = (feof(f) ? FILE_EMPTY : FILE_READING_ERROR);
        }
        fclose(f);
    }
    return return_code;
}

int file_write(char *file_name, struct node *array, size_t n)
{
    int return_code = EXIT_SUCCESS;
    FILE *f = fopen(file_name, "w");
    if (!f)
    {
        return_code = FILE_OPEN_ERROR;
    }
    else
    {
        for (size_t i = 0; i < n; ++i)
        {
            fprintf(f, "%s %s %s %lld", array[i].name, array[i].surname, array[i].third_name, array[i].phone);
        }
        fclose(f);
    }
    return return_code;
}

int main(int argc, char **argv)
{
    int exit_code = EXIT_SUCCESS;
    if (argc != 3)
    {
        exit_code = EXIT_FAILURE;
    }
    else
    {
        char *in_file = argv[1], *out_file = argv[2];
        struct node numbers[ARRAY_SIZE];
        size_t n = 0;
        exit_code = file_read(in_file, numbers, &n);
        if (exit_code == EXIT_SUCCESS)
        {
            exit_code = file_write(out_file, numbers, n);
        }
    }
    return exit_code;
}