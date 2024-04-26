#include <stdio.h>
#include <math.h>
#include <limits.h>
#define EPS 1e-6
double tinh_Cos(double x)
{
    double q = 0;
    double t = 1;
    int k = 0;
    do {
        q += t;
        k += 2;
        t = -t * pow(x, 2) / (k*(k - 1));
    } while (fabs(t) > EPS);
    return q;
}
int main()
{
    double x;
    printf("Nhap x (radian): ");
    scanf("%lf", &x);
        x = (x * M_PI) / 180;
    printf("cos(%.2lf) = %.2lf\n", x, tinh_Cos(x));
    printf("COS(%.2lf) = %.2lf\n", x, cos(x));
    return 0;
}