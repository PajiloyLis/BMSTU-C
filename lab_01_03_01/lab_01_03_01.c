#include <stdio.h>

double new_volume(double, double);

double new_temperature(double, double, double, double);

int main(void)
{
    double v1, v2;
    double t1, t2;
    double v, t;
    scanf("%lf %lf %lf %lf", &v1, &t1, &v2, &t2);
    v = new_volume(v1, v2);
    t = new_temperature(v1, v2, t1, t2);
    printf("Volume is: %.6f\nTemperature is: %.6f\n", v, t);
    return 0;
}

double new_volume(double first_v, double second_v)
{
    return first_v + second_v;
}

double new_temperature(double first_v, double second_v, double first_t, double second_t)
{
    double temperature = (first_v * first_t + second_v * second_t) / (first_v + second_v);
    return temperature;
}
