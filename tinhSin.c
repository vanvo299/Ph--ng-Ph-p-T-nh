#include <stdio.h>
#include <math.h>
#define EPS 1e-6
double tinh_Sin(double x)
{
    double q = 0;
    double t = x;
    int k = 1;
    do {
        q += t;
        k+=2;
        t = -t *pow(x, 2) / (k*(k - 1));
    } while(fabs(t) > EPS);
    return q;
}
int main()
{
    double x;
    printf("Nhap x (radian): ");
    scanf("%lf", &x);
    x = (x * M_PI) / 180; // đổi từ đơn vị radian sang đơn vị độ
    printf("Gia tri cua sinx theo khai trien: %.2lf\n", tinh_Sin(x));
    printf("Gia tri sin cua may: %.2lf\n", sin(x));
    return 0;
}