#include <stdlib.h>
#include "args.h"
#include "fileio.h"
#include "array_algo.h"
#include "type.h"
#include <stdbool.h>

#define DEFAULT_ARAY_SIZE 15

int main(int argc, char **argv)
{
    int rc = EXIT_SUCCESS;
    char *file_name = NULL, *prefix = NULL;
    bool is_alocated_1 = false, is_alocated_2 = false;
    size_t total_array_n, total_ans_array_n;
    total_array_n = total_ans_array_n = DEFAULT_ARAY_SIZE;
    object_t *array, *array_buf, **ans_array, **ans_buf;

    array_buf = malloc(total_array_n * sizeof(object_t));
    if (!array_buf)
        rc = MEMORY_ALLOCATION_ERROR;
    else
    {
        array = array_buf;
        is_alocated_1 = true;
    }

    ans_buf = malloc(total_ans_array_n * sizeof(object_t *));
    if (!ans_buf)
        rc = MEMORY_ALLOCATION_ERROR;
    else
    {
        ans_array = ans_buf;
        is_alocated_2 = true;
    }
    size_t n = 0, ans_n = 0;
    rc = (rc == EXIT_SUCCESS ? take_args(argc, argv, &prefix, &file_name) : rc);
    rc = (rc == EXIT_SUCCESS ? input(&array, &n, &total_array_n, file_name) : rc);
    if (rc == EXIT_SUCCESS)
    {
        if (!prefix)
        {
            rc = insert_sort(array, n);
            if (rc == EXIT_SUCCESS)
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
                find(array, &ans_array, &ans_n, n, &total_ans_array_n, prefix);
                output_by_pointers(ans_array, ans_n);
            }
        }
    }
    if (is_alocated_1)
        array_free(array, n);
    if (is_alocated_2)
        free(ans_array);
    return rc;
}
