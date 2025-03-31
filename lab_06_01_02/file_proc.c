#include "file_proc.h"

int compare_by_dencity(object_t *item_1, object_t *item_2);

int min(size_t a, size_t b);

void find(object_t *array, object_t *ans_array[], size_t *ans_n, size_t n, char *prefix)
{
    *ans_n = 0;
    size_t len = strlen(prefix);
    for (size_t i = 0; i < n; ++i)
    {
        if (!strncmp((array + i)->name, prefix, len))
        {
            ans_array[*ans_n] = array + i;
            (*ans_n)++;
        }
    }
}

int min(size_t a, size_t b)
{
    return a < b ? a : b;
}

int insert_sort(object_t *array, size_t n)
{
    int return_code = EXIT_SUCCESS;
    for (size_t i = 1 && return_code == EXIT_SUCCESS; i < n; ++i)
    {
        int swapped = 1;
        for (int j = i - 1; j >= 0 && swapped && return_code == EXIT_SUCCESS; j--)
        {
            swapped = 0;
            if (compare_by_dencity(array + j + 1, array + j) < 0)
            {
                object_t buf = array[j];
                array[j] = array[j + 1];
                array[j + 1] = buf;
                swapped = 1;
            }
        }
    }
    return return_code;
}

int compare_by_dencity(object_t *item_1, object_t *item_2)
{
    double dencity_1 = item_1->mass / item_1->volume, dencity_2 = item_2->mass / item_2->volume;
    int result = 0;
    if (dencity_1 < dencity_2 - EPS)
    {
        result = -1;
    }
    else if (dencity_1 > dencity_2 + EPS)
    {
        result = 1;
    }
    return result;
}
