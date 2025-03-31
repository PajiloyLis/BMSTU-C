#include <stdio.h>
#include <math.h>
#define ERROR 1
#define NO_ERROR 0

int input(double *, double *);

double get_approximate_value(double, double);

void output(double, double, double, double);

int main(void)
{
    int main_return_code = NO_ERROR;
    double x;
    double eps;
    double f_value, s_value;
    double delta, rel_delta;
    if (input(&x, &eps) == 0)
    {
        f_value = sin(x);
        s_value = get_approximate_value(x, eps);
        delta = fabs(f_value - s_value);
        rel_delta = delta / fabs(f_value);
        printf("Approximate value s(x): %.6lf\n", f_value);
        printf("Exact value f(x): %.6lf\n", s_value);
        printf("Absolute error: %.6lf\n", delta);
        if (isnan(rel_delta))
        {
            printf("Relative error: 0\n");
        }
        else
        {
            printf("Relative error: %.6lf\n", rel_delta);
        }
    }
    else
    {
        main_return_code = ERROR;
    }
    return main_return_code;
}

int input(double *x, double *eps)
{
    int count;
    int return_code = NO_ERROR;
    printf("Enter value of x and value of precision\n");
    count = scanf("%lf %lf", x, eps);
    if (count != 2)
    {
        return_code = ERROR;
    }
    else
    {
        if (*eps <= 0.0 || *eps > 1.0)
        {
            return_code = ERROR;
        }
    }
    return return_code;
}

double get_approximate_value(double x, double eps)
{
    double s_value = 0;
    double cur_value = x;
    int iteration = 1;
    while (fabs(cur_value) >= eps)
    {
        s_value += cur_value;
        iteration += 2;
        cur_value = (-1) * cur_value * x * x / (iteration * (iteration - 1));
    }
    return s_value;
}
