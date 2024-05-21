// Bảng nội suy ayken
#include <stdio.h>
#include <stdlib.h>

void Nhap(float x[], float y[], int n)
{
    printf("Nhap x[]: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }
    printf("Nhap y[]: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &y[i]);
    }
}

float bangNoiSuyAyken(float x[], float y[], int n, float c)
{
    float w = 1, s = 0;
    for (int i = 0; i < n; i++) {
        float d = 1;
        w *=(c - x[i]);
        d = c - x[i];
        for (int j = 0; j < n; j++)
            if (j != i) d *= x[i] - x[j];
            s += y[i]/d; 
    }
    return w*s;
}
int main()
{
    float x[10], y[10], c;
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("Nhap c: ");
    scanf("%f", &c);
    Nhap(x, y, n);
    float result = bangNoiSuyAyken(x, y, n, c);
    printf("f(%.1f) = %f\n", c, result);
    return 0;
}