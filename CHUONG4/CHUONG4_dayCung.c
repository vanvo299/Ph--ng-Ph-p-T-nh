#include <stdio.h>
#include <math.h>
const float EPS = 1e-6;
const int MAX_COUNT = 1000;

float f(float x)
{
    // float result = pow(2, x) + x - 4;
    // float result = pow(x, 4) - 4 * x - 1;
    float result = pow(x, 3) + x - 5;
    return result;
}

int PPdayCung(float (*f)(float), float a, float b, float *q)
{
    float x;
    int count = 0;
    printf("       a           b           x          f(x) \n");
    printf("--------------------------------------------------\n");
    while(count < MAX_COUNT)
    {
        x = a - ((b - a) * f(a)) / (f(b) - f(a));
        if (f(x) < f(a)) b = x;
        else a = x;
        printf("  %f    %f     %f    %f   \n", a, b, x, f(x));
        if (fabs(f(x)) <= EPS) {
            *q = x;
            return 1;
        }
        count++;
    }
    return 0;
}
int main()
{
    float a, b, q;
    printf("Nhap khoang nghiem [a, b]: "); 
    scanf("%f%f", &a, &b);
    float ketQua = PPdayCung(f, a, b, &q);
    if (ketQua) {
        printf("Nghiem cua phuong trinh x thuoc [%.2f, %.2f] la: %f\n", a, b, q);
    } else printf("Phuong trinh khong co nghiem tren khoang [%.2f, %.2f]\n", a, b);
    return 0;
}