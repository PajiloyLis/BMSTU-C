#include <stdlib.h>
#include "args.h"
#include "fileio.h"
#include "algorithms.h"

int main(int argc, char **argv)
{
    int exit_code = EXIT_SUCCESS;
    char *file_in = NULL, *file_out = NULL;
    int to_be_filtered = 0;
    size_t n = 0;
    exit_code = args_handler(argc, argv, &file_in, &file_out, &to_be_filtered);
    exit_code = (exit_code == EXIT_SUCCESS ? count_records_cnt(file_in, &n) : exit_code);
    int *pb_src = (int *)malloc(n * sizeof(int)), *pe_src, *pb_dst, *pe_dst;
    if (!pb_src)
    {
        exit_code = MEMORY_ALLOC_ERROR;
    }
    else
    {
        pe_src = pb_src + n, pb_dst = pb_src, pe_dst = pe_src;
        exit_code = (exit_code == EXIT_SUCCESS ? read_numbers(file_in, pb_src, pe_src) : exit_code);
        if (exit_code == EXIT_SUCCESS)
        {
            if (to_be_filtered)
            {
                exit_code = key(pb_src, pe_src, &pb_dst, &pe_dst);
            }
            if (exit_code == EXIT_SUCCESS)
            {
                mysort(pb_dst, pe_dst - pb_dst, sizeof(int), compare_int);
                exit_code = (exit_code == EXIT_SUCCESS ? output(file_out, pb_dst, pe_dst) : exit_code);
                if (to_be_filtered)
                {
                    free(pb_dst);
                }
            }
        }
        free(pb_src);
    }
    return exit_code;
}
