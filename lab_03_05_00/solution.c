#include "solution.h"

int find_primes(matrix_t arr, size_t n, size_t m, matrix_cord cord, size_t *cord_n, long long *primes);

void arr_reverse(long long *arr, size_t n);

void insertion(matrix_t arr, matrix_cord cord, size_t cord_n, long long *primes);

int is_prime(long long val);

void swap(long long *a, long long *b);

int solution(matrix_t array, size_t n, size_t m, matrix_cord cord, size_t *cord_n, long long *primes)
{
    int return_code = find_primes(array, n, m, cord, cord_n, primes);
    if (return_code == EXIT_SUCCESS)
    {
        arr_reverse(primes, *cord_n);
        insertion(array, cord, *cord_n, primes);
    }
    return return_code;
}

int find_primes(matrix_t arr, size_t n, size_t m, matrix_cord cord, size_t *cord_n, long long *primes)
{
    int return_code = EXIT_FAILURE;
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
        {
            if (is_prime(*(*(arr + i) + j)))
            {
                **(cord + *cord_n) = (long long)i;
                *(*(cord + *cord_n) + 1) = (long long)j;
                *(primes + *cord_n) = *(*(arr + i) + j);
                ++(*cord_n);
                return_code = EXIT_SUCCESS;
            }
        }
    }
    return return_code;
}

void arr_reverse(long long *arr, size_t n)
{
    for (size_t i = 0; i < n / 2; ++i)
    {
        swap(arr + i, arr + n - i - 1);
    }
}

void insertion(matrix_t arr, matrix_cord cord, size_t cord_n, long long *primes)
{
    for (size_t k = 0; k < cord_n; ++k)
    {
        size_t i = **(cord + k), j = *(*(cord + k) + 1);
        *(*(arr + i) + j) = *(primes + k);
    }
}

int is_prime(long long val)
{
    int is_prime = 1;
    if (val <= 1)
    {
        is_prime = 0;
    }
    else
    {
        for (long long i = 2; i * i <= val && is_prime; ++i)
        {
            if (val % i == 0)
            {
                is_prime = 0;
            }
        }
    }
    return is_prime;
}

void swap(long long *a, long long *b)
{
    long long buf = *a;
    *a = *b;
    *b = buf;
}
