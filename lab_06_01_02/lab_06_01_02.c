#include "lab_06_01_02.h"

int main(int argc, char **argv)
{
    int exit_code = EXIT_SUCCESS;
    char *file_name = NULL, *prefix = NULL;
    object_t array[MAX_ARAY_SIZE];
    size_t n = 0, ans_n = 0;
    object_t *ans_array[MAX_ARAY_SIZE];
    exit_code = take_agrs(argc, argv, &prefix, &file_name);
    exit_code = (exit_code == EXIT_SUCCESS ? input(array, &n, file_name) : exit_code);
    if (exit_code == EXIT_SUCCESS)
    {
        if (!prefix)
        {
            exit_code = insert_sort(array, n);
            if (exit_code == EXIT_SUCCESS)
                output(array, n);
        }
        else
        {
            if (!strcmp(prefix, ALL))
            {
                output(array, n);
            }
            else
            {
                find(array, ans_array, &ans_n, n, prefix);
                output_by_pointers(ans_array, ans_n);
            }
        }
    }
    return exit_code;
}
