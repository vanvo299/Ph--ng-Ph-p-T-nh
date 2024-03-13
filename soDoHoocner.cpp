#include <stdio.h>
#include <math.h>
void Nhap(float a[100], int n)
{
    printf("Nhap he so cua phuong trinh: ");
    for (int i = 0; i <= n; i++) {
        scanf("%f", &a[i]);
    }
}
float tinh(float a[100], int n, float c)
{
    float P = a[0];
    for (int i = 1; i <= n; i++) {
        P = P*c + a[i];
    }
    return P;
}
int main()
{
    float a[100], c;
    int n;
    printf("Nhap bac cua phuong trinh: "); scanf("%d", &n);
    Nhap(a, n);
    printf("Nhap c: ");
    scanf("%f", &c);
    printf("Gia tri cua P(%.1f) la: %.2f\n", c, tinh(a, n, c));
    return 0;
}