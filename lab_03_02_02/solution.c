#include "solution.h"

int is_good_row(long long *row, size_t m);

int is_good_num(long long n);

void solve(matrix_t arr, size_t n, size_t m, matrix_ans_t new_arr, size_t *new_n)
{
    for (long long(*row)[SIZE] = arr; row < arr + n; ++row)
    {
        if (is_good_row(*row, m) == EXIT_SUCCESS)
        {
            for (size_t i = 0; i < m; ++i)
            {
                *(*(new_arr + (*new_n)) + i) = -1;
            }
            ++(*new_n);
        }
        for (size_t i = 0; i < m; ++i)
        {
            *(*(new_arr + (*new_n)) + i) = *((*row) + i);
        }
        ++(*new_n);
    }
}

int is_good_row(long long *row, size_t m)
{
    int cnt = 0, return_code = EXIT_FAILURE;
    for (long long *p = row; p < row + m && cnt < 2; ++p)
    {
        if (is_good_num(llabs(*p)) == EXIT_SUCCESS)
        {
            cnt++;
        }
    }
    if (cnt == 2)
    {
        return_code = EXIT_SUCCESS;
    }
    return return_code;
}

int is_good_num(long long n)
{
    int sum = 0, return_code = EXIT_SUCCESS;
    while (n)
    {
        sum += n % BASE;
        n /= BASE;
    }
    if (!(sum % 2))
    {
        return_code = EXIT_FAILURE;
    }
    return return_code;
}
