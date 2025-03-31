#include "task.h"

int calc_sums(char *file_name, double *sq_sum, double *sum, long long *n);

int calc_variance(char *file_name, double *variance)
{
    int return_code = EXIT_SUCCESS;
    double sq_sum = 0, sum = 0;
    long long n = 0;
    return_code = calc_sums(file_name, &sq_sum, &sum, &n);
    if (return_code == EXIT_SUCCESS)
    {
        *variance = sq_sum / n - sum * sum / (n * n);
    }
    return return_code;
}

int calc_sums(char *file_name, double *sq_sum, double *sum, long long *n)
{
    int return_code = EXIT_SUCCESS;
    FILE *f = fopen(file_name, "r");
    if (!f)
    {
        return_code = FILE_OPEN_ERROR;
    }
    else
    {
        double val;
        if (fscanf(f, "%lf", &val) == 1)
        {
            *sq_sum += val * val;
            *sum += val;
            (*n)++;
            while (fscanf(f, "%lf", &val) == 1)
            {
                *sq_sum += val * val;
                *sum += val;
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
    return return_code;
}
