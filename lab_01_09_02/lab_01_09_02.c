#include <stdio.h>
#include <math.h>
#define ERROR 1
#define NO_ERROR 0

int input(long long int *);

int get_g(long double *);

int main(void)
{
    int main_return_code = NO_ERROR;
    long double result;
    if (get_g(&result) == 0)
    {
        if (isnan(result))
        {
            main_return_code = ERROR;
        }
        else
        {
            printf("g(x): %.6Lf\n", result);
        }
    }
    else
    {
        main_return_code = ERROR;
    }
    return main_return_code;
}

int input(long long int *a)
{
    int input_return_code = NO_ERROR;
    int count;
    printf("Enter the next element\n");
    count = scanf("%lld", a);
    if (count != 1)
    {
        input_return_code = ERROR;
    }
    return input_return_code;
}

int get_g(long double *value)
{
    int return_code = NO_ERROR;
    long long cnt = 0;
    *value = 0;
    while (1)
    {
        long long int x;
        if (input(&x) == 1)
        {
            return_code = ERROR;
            break;
        }
        if (x < 0)
        {
            break;
        }
        else
        {
            cnt++;
            *value += sqrtl((long double)(cnt + x));
        }
    }
    *value /= cnt;
    return return_code;
}
