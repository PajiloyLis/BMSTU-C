#include <stdio.h>
#include <stdlib.h>
#define BITS 32
#define ERROR 1
#define NO_ERROR 0

int input(unsigned int *, long long int *);

unsigned int get_ans(unsigned int, long long int);

void output(unsigned int);

int main(void)
{
    int main_return_code = NO_ERROR;
    unsigned int a;
    long long int n;
    unsigned int new_value;
    if (input(&a, &n) == 0)
    {
        n %= BITS;
        new_value = get_ans(a, n);
        output(new_value);
    }
    else
    {
        main_return_code = ERROR;
    }
    return main_return_code;
}

int input(unsigned int *a, long long int *n)
{
    int cnt;
    long long tmp;
    int return_code = NO_ERROR;
    cnt = scanf("%lld %lld", &tmp, n);
    if (cnt == 2 && (tmp >= (1ll << BITS) || *n < 0))
    {
        printf("Error: input error\n");
        return_code = ERROR;
    }
    if (cnt != 2)
    {
        printf("Error: input error, try again!\n");
        return_code = ERROR;
    }
    *a = (unsigned int)tmp;
    return return_code;
}

unsigned int get_ans(unsigned int a, long long int n)
{
    unsigned int ans = (a << n) + (a >> (BITS - n));
    return ans;
}

void output(unsigned int a)
{
    printf("Result: ");
    unsigned int mask = (1 << (BITS - 1));
    for (int i = 0; i < BITS; ++i)
    {
        long long int curv = ((a & (mask >> i)) >> (BITS - i - 1));
        printf("%lld", curv);
    }
}
