#include <stdio.h>
#define ERROR 1
#define NO_ERROR 0

int input(long long int *, long long int *);

long long int div(long long int, long long int);

int main(void)
{
    int main_return_code = NO_ERROR;
    long long int a, d;
    long long int q, r;
    if (input(&a, &d) == 0)
    {
        q = div(a, d);
        r = a - q * d;
        printf("%lld %lld", q, r);
    }
    else
    {
        main_return_code = ERROR;
    }
    return main_return_code;
}

int input(long long int *a, long long int *d)
{
    int return_code = NO_ERROR;
    int count = scanf("%lld %lld", a, d);
    if (count != 2)
    {
        return_code = ERROR;
    }
    else
    {
        if (*a <= 0 || *d <= 0)
        {
            return_code = ERROR;
        }
    }
    return return_code;
}

long long int div(long long int a, long long int d)
{
    long long int res = 0;
    while (a >= d)
    {
        a -= d;
        res++;
    }
    return res;
}
