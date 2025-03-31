#include "matrix_t.h"
#include "matrix_io.h"
#include "matrix_algo.h"
#include "matrix_alloc.h"
#include <stdio.h>

#define INPUT_SIZE_ERROR 61
#define POW_READING_ERROR 60

int main(void)
{
    int return_code = EXIT_SUCCESS;
    matrix_t matr_1, matr_2;
    matr_1.is_allocated = matr_2.is_allocated = false;
    long long buf_m, buf_n;
    if (scanf("%lld%lld", &buf_n, &buf_m) != 2 || buf_n <= 0 || buf_m <= 0)
        return_code = INPUT_SIZE_ERROR;
    return_code = return_code == EXIT_SUCCESS ? allocate_matrix(&matr_1, buf_n, buf_m) : return_code;
    return_code = return_code == EXIT_SUCCESS ? input_matrix(&matr_1) : return_code;
    if (return_code == EXIT_SUCCESS && (scanf("%lld%lld", &buf_n, &buf_m) != 2 || buf_n <= 0 || buf_m <= 0))
        return_code = INPUT_SIZE_ERROR;
    return_code = return_code == EXIT_SUCCESS ? allocate_matrix(&matr_2, buf_n, buf_m) : return_code;
    return_code = return_code == EXIT_SUCCESS ? input_matrix(&matr_2) : return_code;
    return_code = return_code == EXIT_SUCCESS ? make_quadratic(&matr_1) : return_code;
    return_code = return_code == EXIT_SUCCESS ? make_quadratic(&matr_2) : return_code;
    size_t new_n;
    return_code = return_code == EXIT_SUCCESS ? calc_expanded_size(&matr_1, &matr_2, &new_n) : return_code;
    return_code = (return_code == EXIT_SUCCESS && matr_1.n < new_n) ? reallocate_matrix(&matr_1, new_n) : return_code;
    return_code = (return_code == EXIT_SUCCESS && matr_2.n < new_n) ? reallocate_matrix(&matr_2, new_n) : return_code;
    return_code = (return_code == EXIT_SUCCESS && matr_1.n < new_n) ? make_equal_size(&matr_1, new_n) : return_code;
    return_code = (return_code == EXIT_SUCCESS && matr_2.n < new_n) ? make_equal_size(&matr_2, new_n) : return_code;
    unsigned int pow_1, pow_2;
    long long buf_1, buf_2;
    return_code = (scanf("%lld %lld", &buf_1, &buf_2) != 2 || buf_1 < 0 || buf_2 < 0) ? POW_READING_ERROR : return_code;
    if (return_code == EXIT_SUCCESS)
    {
        pow_1 = buf_1;
        pow_2 = buf_2;
    }
    matrix_t ans_1, ans_2, ans;
    ans.is_allocated = ans_1.is_allocated = ans_2.is_allocated = false;
    ans.n = ans.m = ans_1.n = ans_2.n = ans_1.m = ans_2.m = matr_1.n;
    return_code = return_code == EXIT_SUCCESS ? allocate_matrix(&ans, ans.n, ans.n) : return_code;
    return_code = return_code == EXIT_SUCCESS ? allocate_matrix(&ans_1, ans_1.n, ans_1.m) : return_code;
    return_code = return_code == EXIT_SUCCESS ? allocate_matrix(&ans_2, ans_2.n, ans_2.m) : return_code;
    return_code = return_code == EXIT_SUCCESS ? matrix_pow(&matr_1, pow_1, &ans_1) : return_code;
    return_code = return_code == EXIT_SUCCESS ? matrix_pow(&matr_2, pow_2, &ans_2) : return_code;
    return_code = return_code == EXIT_SUCCESS ? matrix_multiply(&ans_1, &ans_2, &ans) : return_code;
    if (return_code == EXIT_SUCCESS)
        output_matrix(&ans);
    if (matr_1.is_allocated)
        free_matrix(&matr_1);
    if (matr_2.is_allocated)
        free_matrix(&matr_2);
    if (ans.is_allocated)
        free_matrix(&ans_1);
    if (ans_1.is_allocated)
        free_matrix(&ans_2);
    if (ans_2.is_allocated)
        free_matrix(&ans);
    return return_code;
}
