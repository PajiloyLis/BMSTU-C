#include "array.h"
#include <stdlib.h>
#include <stdio.h>

// из массива %3
// строку с максимумом
int main(void)
{
    int return_code = EXIT_SUCCESS;
    size_t n;
    long long *array;
    return_code = input_size(&n);
    return_code = return_code == EXIT_SUCCESS ? allocate_array(&array, n) : return_code;
    return_code = return_code == EXIT_SUCCESS ? input_array(array, n) : return_code;
    return_code = return_code == EXIT_SUCCESS ? delete_elems(array, &n) : return_code;
    if (return_code == EXIT_SUCCESS)
        print_array(array, n);
    if (return_code != MEMORY_ALLOC_ERROR)
        free(array);
}