#include <stdio.h>
#include <math.h>
void Nhap(double a[], int n)
{
    printf("Nhap cac he so cua da thuc: ");
    for (int i = 0; i <= n; i++) {
        scanf("%lf", &a[i]);
    }
}
void calculate(double vao[], int n, double c, double ra[])
{
   
    for (int i = 0; i <= n; i++) {
        ra[i] = vao[i];
    }
        for (int k = n; k >= 0; k--) {
            printf("%.0lf\t", vao[0]);
            for (int j = 1; j <= k; j++) {
                ra[j] = ra[j - 1] * c + ra[j];
                printf("%.0lf\t", ra[j]);
            }
            printf("\n");
        }
        printf("\nCac he so cua da thuc la: ");
        for (int i = 0; i <= n; i++) {
            printf("%.0lf\t", ra[i]);
        }
    }

int main()
{
    double vao[100], ra[100], c;
    int n;
    printf("Nhap bac cua da thuc: ");
    scanf("%d", &n);
    Nhap(vao, n);
    printf("Nhap he so can tinh: ");
    scanf("%lf", &c);
    calculate(vao, n, c, ra);

    return 0;
}