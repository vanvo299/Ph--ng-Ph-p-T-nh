#include <stdio.h>
#include <math.h>
void Nhap(float a[], int n)
{
    printf("Nhap he so cua phuong trinh: ");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &a[i]);
    }
}
void dinhLy3(float a[], int n)
{
    float m1 = fabs(a[1]), m2 = fabs(a[0]), x1, x2;
    for (int i = 0; i <= n; i++) {
        if (i >= 1) {
            if (fabs(a[i]) > m1) {
                m1 = fabs(a[i]);
            }
        }
        if (i <= n - 1) {
            if (fabs(a[i]) > m2) {
                m2 = fabs(a[i]);
            }
        }
    }
    x1 = fabs(a[n]) / (m2 + fabs(a[n]));
    x2 = 1 + m1 / fabs(a[0]);
    printf("Nghiem cua phuong trinh thoa man %.2f <= x <= %.2f\n", x1, x2);
}
int main()
{
    float a[10];
    int n;
    printf("Nhap bac cua phuong trinh: ");
    scanf("%d", &n);
    Nhap(a, n);
    dinhLy3(a, n);
    return 0;
}