#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SUCCESS_EXIT 0
#define FAILED_EXIT 1
#define SIZE 10

int input(long long *array, size_t *n);

size_t deleting(long long *array, size_t n);

int is_sqrt(long long val);

void output(long long *array, size_t n, size_t shift);

int main(void)
{
    int return_code = EXIT_SUCCESS;
    size_t n;
    long long array[10];
    if (input(array, &n) == EXIT_FAILURE)
    {
        printf("Bad input\n");
        return_code = EXIT_FAILURE;
    }
    else
    {
        size_t shift = deleting(array, n);
        if (shift == n)
        {
            printf("Array is empty\n");
            return_code = EXIT_FAILURE;
        }
        else
        {
            output(array, n, shift);
        }
    }
    return return_code;
}

int input(long long *array, size_t *n)
{
    int return_code = EXIT_SUCCESS;
    printf("Enter size: ");
    if (scanf("%zu", n) != 1 || *n > SIZE)
    {
        return_code = EXIT_FAILURE;
    }
    else
    {
        for (size_t i = 0; i < *n && return_code == EXIT_SUCCESS; ++i)
        {
            printf("Enter next element: ");
            if (scanf("%lld", array + i) != 1)
            {
                return_code = EXIT_FAILURE;
            }
        }
    }
    return return_code;
}

size_t deleting(long long *array, size_t n)
{
    size_t shift = 0;
    for (size_t i = 0; i < n; ++i)
    {
        if (array[i] < 0 || is_sqrt(array[i]))
        {
            array[i - shift] = array[i];
        }
        else
        {
            shift++;
        }
    }
    return shift;
}

int is_sqrt(long long val)
{
    int return_code = EXIT_FAILURE;
    long long sq = (int)sqrt((double)val);
    if (sq * sq == val)
    {
        return_code = EXIT_SUCCESS;
    }
    return return_code;
}

void output(long long *array, size_t n, size_t shift)
{
    printf("New array: ");
    for (size_t i = 0; i < n - shift; ++i)
    {
        printf("%lld ", array[i]);
    }
    printf("\n");
}
