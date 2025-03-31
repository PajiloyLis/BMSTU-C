#include <stdio.h>
#include <math.h>

double get_length(double, double, double, double);

double perimetr(double, double, double, double, double, double);

int main(void)
{
    double xa, ya, xb, yb, xc, yc;
    double ans;
    scanf("%lf%lf%lf%lf%lf%lf", &xa, &ya, &xb, &yb, &xc, &yc);
    ans = perimetr(xa, ya, xb, yb, xc, yc);
    printf("Perimetr is %.6lf", ans);
}

double perimetr(double xa, double ya, double xb, double yb, double xc, double yc)
{
    double first = get_length(xa, ya, xb, yb), second = get_length(xa, ya, xc, yc), third = get_length(xb, yb, xc, yc);
    return first + second + third;
}

double get_length(double xa, double ya, double xb, double yb)
{
    return sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
}
