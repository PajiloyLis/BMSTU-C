#include <stdlib.h>
#include "args.h"
#ifndef DYN_LOAD
#include "arrlib.h"
#else
#include <dlfcn.h>

typedef (*count_records_cnt_t)(char *, size_t *);
typedef (*read_numbers_t)(char *, int *, int *);
typedef (*key_t)(const int *, const int *, const int *, size_t *);
typedef int (*cmp)(const void *, const void *);
typedef (*sort_t)(void *, size_t, size_t, cmp);
typedef (*output_t)(char *, int *, int *);

#define DYN_LIBRARY_OPEN_ERROR 10
#define DYN_LIBRARY_FUNCTION_ERROR 11

int import_function(char *func_name, void *lib_name, void *func)
{
    func = dlsym(lib_name, func_name);
    if (!func)
        return DYN_LIBRARY_FUNCTION_ERROR;
    return EXIT_CODE;
}

#endif

int main(int argc, char **argv)
{
    int exit_code = EXIT_SUCCESS;
#ifdef DYN_LOAD
    void *arrlib = dlopen("libarr.so", RTLD_NOW);
    if (!arrlib)
    {
        exit_code = DYN_LIBRARY_OPEN_ERROR;
    }
    count_records_cnt_t count_records_cnt;
    read_numbers_t read_numbers;
    key_t key;
    cmp compare_int;
    sort_t mysort;
    output_t output;
    exit_code = exit_code == EXIT_SUCCESS ? import_function("count_records_cnt", arrlib, count_records_cnt) : exit_code;
    exit_code = exit_code == EXIT_SUCCESS ? import_function("read_numbers", arrlib, read_numbers) : exit_code;
    exit_code = exit_code == EXIT_SUCCESS ? import_function("key", arrlib, key) : exit_code;
    exit_code = exit_code == EXIT_SUCCESS ? import_function("compare_int", arrlib, compare_int) : exit_code;
    exit_code = exit_code == EXIT_SUCCESS ? import_function("mysort", arrlib, mysort) : exit_code;
    exit_code = exit_code == EXIT_SUCCESS ? import_function("output", arrlib, output) : exit_code;
#endif
    char *file_in = NULL, *file_out = NULL;
    int to_be_filtered = 0;
    size_t n = 0;
    exit_code = args_handler(argc, argv, &file_in, &file_out, &to_be_filtered);
    exit_code = (exit_code == EXIT_SUCCESS ? count_records_cnt(file_in, &n) : exit_code);
    int *pb_src = (int *)malloc(n * sizeof(int)), *pe_src = NULL, *pb_dst = NULL, *pe_dst = NULL;
    if (!pb_src)
        exit_code = MEMORY_ALLOC_ERROR;
    else
    {
        pe_src = pb_src + n, pb_dst = pb_src, pe_dst = pe_src;
        size_t new_n = 0;
        exit_code = (exit_code == EXIT_SUCCESS ? read_numbers(file_in, pb_src, pe_src) : exit_code);
        if (exit_code == EXIT_SUCCESS)
        {
            if (to_be_filtered)
            {
                exit_code = key(pb_src, pe_src, pb_dst, &new_n);
                if (exit_code == EXIT_SUCCESS)
                {
                    pb_dst = malloc(new_n * sizeof(int));
                    if (!pb_dst)
                        exit_code = MEMORY_ALLOC_ERROR;
                }
                exit_code = exit_code == EXIT_SUCCESS ? key(pb_src, pe_src, pb_dst, &new_n) : exit_code;
                pe_dst = pb_dst + new_n;
            }
            if (exit_code == EXIT_SUCCESS)
            {
                mysort(pb_dst, pe_dst - pb_dst, sizeof(int), compare_int);
                exit_code = exit_code == EXIT_SUCCESS ? output(file_out, pb_dst, pe_dst) : exit_code;
                if (to_be_filtered && pb_dst)
                    free(pb_dst);
            }
        }
    }
    if (pb_src)
        free(pb_src);
#ifdef DYN_LOAD
    dlclose(arrlib);
#endif
    return exit_code;
}
