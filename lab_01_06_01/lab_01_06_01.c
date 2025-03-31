#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define ERROR 1
#define NO_ERROR 0

int input(long long int *, long long int *, long long int *, long long int *, long long int *, long long int *);

void make_vector(long long int *, long long int *, long long int, long long int, long long int, long long int);

long double get_square(long long int, long long int, long long int, long long int);

int main(void)
{
    int main_return_code = NO_ERROR;
    long long int x1, x2, x3, y1, y2, y3;
    long long int vector_1_x, vector_1_y, vector_2_x, vector_2_y;
    long double square;
    if (input(&x1, &x2, &x3, &y1, &y2, &y3) == 0)
    {
        make_vector(&vector_1_x, &vector_1_y, x1, x2, y1, y2);
        make_vector(&vector_2_x, &vector_2_y, x1, x3, y1, y3);
        if (vector_1_x * vector_2_y - vector_2_x * vector_1_y == 0)
        {
            main_return_code = ERROR;
        }
        else
        {
            square = get_square(vector_1_x, vector_1_y, vector_2_x, vector_2_y);
            printf("square = %.6Lf\n", square);
        }
    }
    else
    {
        main_return_code = ERROR;
    }
    return main_return_code;
}

int input(long long int *x1, long long int *x2, long long int *x3, long long int *y1, long long int *y2, long long int *y3)
{
    int count;
    int return_code = NO_ERROR;
    printf("Enter the coordinates (x, y) of the first, second and third points\n");
    count = scanf("%lld %lld %lld %lld %lld %lld", x1, y1, x2, y2, x3, y3);
    if (count != 6)
    {
        return_code = ERROR;
    }
    return return_code;
}

void make_vector(long long int *x, long long int *y, long long int start_x, long long int end_x, long long int start_y, long long int end_y)
{
    *x = end_x - start_x;
    *y = end_y - start_y;
    return;
}

long double get_square(long long int first_x, long long int first_y, long long int second_x, long long int second_y)
{
    long double res = llabs(first_x * second_y - second_x * first_y) / 2.0;
    return res;
}
