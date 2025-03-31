#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int input(double *p_b, size_t *n, double **p_e);

double get_sum(double *p_b, double *p_e);

int main(void)
{
    int exit_code = EXIT_SUCCESS;
    double array[SIZE];
    double *p_begin = array, *p_end = p_begin;
    size_t n;
    if (input(p_begin, &n, &p_end) == EXIT_FAILURE)
    {
        exit_code = EXIT_FAILURE;
    }
    else
    {
        printf("Sum: %.6lf\n", get_sum(p_begin, p_end));
    }
    return exit_code;
}

int input(double *p_b, size_t *n, double **p_e)
{
    int return_code = EXIT_SUCCESS;
    printf("Enter size: ");
    if (scanf("%zu", n) != 1 || *n > SIZE)
    {
        return_code = EXIT_FAILURE;
    }
    else
    {
        for (double *p_cur = p_b; (unsigned long)(p_cur - p_b) < *n && return_code == EXIT_SUCCESS; ++p_cur)
        {
            printf("Enter next element: ");
            if (scanf("%lf", p_cur) != 1)
            {
                return_code = EXIT_FAILURE;
            }
        }
    *p_e = p_b+(*n);
    }
    return return_code;
}

double get_sum(double *p_b, double *p_e)
{
    double sum = 0.0;
    double prev_value = 1.0;
    double *p_cur;
    for (p_cur = p_b; p_cur != p_e && !(*p_cur < 0); ++p_cur)
    {
        prev_value *= *p_cur;
        sum += prev_value;
    }
    if (p_cur != p_e)
    {
        prev_value *= *p_cur;
        sum += prev_value;
    }
    return sum;
}
