#include <stdio.h>
#include <math.h>
const float EPS = 1e-6;
const int MAX_COUNT = 1000;
float g(float x)
{
    // float result = (float)((x * 1.0) / (x*x + x + 1)) + 1;
    float result = pow(x + 1, 1.0/3);
    return result;
}

// int PPlap(float (*f)(float), float x, float *q)
// {
//     float y;
//     printf("      x      ||        g(x)         \n");
//     printf("-----------------------------\n");
//     printf("  %f   ||      %f\n", x, g(x));
//     do {
//         y = x;
//         x = g(y);
//         printf("  %f   ||      %f\n", x, g(x));
//     } while(fabs(g(x) - x) > EPS);
//     *q = x;
//     return 1;
// }
int PPlap(float (*f)(float), float x, float *q)
{
    float y;
    int count = 0;
    printf("      x      ||        g(x)         \n");
    printf("-----------------------------\n");
    printf("  %f   ||      %f\n", x, g(x));
    while (count < MAX_COUNT) {
        y = x;
        x = g(y);
        printf("  %f   ||      %f\n", x, g(x));
        if (fabs(x - y) <= EPS) {
            *q = x;
            return 1;
        }
        count++;
    }
    return 0;
}
int main()
{
    float x, q;
    printf("Nhap x: "); scanf("%f", &x);
    float ketQua = PPlap(g, x, &q);
    if (ketQua) {
        printf("Nghiem cua phuong trinh la: %f\n", q);
    } else printf("Phuong trinh khong co nghiem\n");
    return 0;
}