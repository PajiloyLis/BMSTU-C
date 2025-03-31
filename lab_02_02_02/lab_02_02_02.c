#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define BASE 10

int input(long long *array, size_t *n);

size_t get_new_size(long long *array, size_t n);

int check_digits(long long a);

void output(long long *array, size_t n);

void make_array(long long *array, long long *new_array, size_t n);

int main(void)
{
    int return_code = EXIT_SUCCESS;
    long long array[SIZE];
    size_t new_n;
    size_t n;
    if (input(array, &n) == EXIT_FAILURE)
    {
        printf("Failed input\n");
        return_code = EXIT_FAILURE;
    }
    else
    {
        new_n = get_new_size(array, n);
        if (new_n == 0)
        {
            printf("No suitable elements\n");
            return_code = EXIT_FAILURE;
        }
        else
        {
            long long new_array[SIZE];
            make_array(array, new_array, n);
            output(new_array, new_n);
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
            printf("Enter next elem: ");
            if (scanf("%lld", array + i) != 1)
            {
                return_code = EXIT_FAILURE;
            }
        }
    }
    return return_code;
}

size_t get_new_size(long long *array, size_t n)
{
    size_t new_n = 0;
    for (size_t i = 0; i < n; ++i)
    {
        if (check_digits(llabs(array[i])))
        {
            new_n++;
        }
    }
    return new_n;
}

int check_digits(long long a)
{
    int return_code = EXIT_SUCCESS;
    int last_sign = a % BASE, first_sign;
    while (a >= BASE)
    {
        a /= BASE;
    }
    first_sign = a;
    if (first_sign == last_sign)
    {
        return_code = EXIT_FAILURE;
    }
    return return_code;
}

void make_array(long long *array, long long *new_array, size_t n)
{
    size_t ind = 0;
    for (size_t i = 0; i < n; ++i)
    {
        if (check_digits(llabs(array[i])))
        {
            new_array[ind] = array[i];
            ind++;
        }
    }
}

void output(long long *array, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        printf("%lld ", array[i]);
    }
    printf("\n");
}
