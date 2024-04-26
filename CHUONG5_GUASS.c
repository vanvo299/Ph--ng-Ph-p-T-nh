// Giải hệ phương trình bằng phương pháp Gauss
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 10

void nhap(float a[][max], int n)
{
    printf("Nhap ma tran can giai: \n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
}

void xuat(float a[][max], int n)
{
    printf("Ma tran sau khi nhap la: \n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            printf("%8.3f ", a[i][j]);
        }
        printf("\n");
    }
}

void swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

void doidong(float a[][max], int n, int p, int q)
{
    if (p <= n && q <= n && p != q)
    for (int k = 1; k <= n + 1; k++) swap(&a[p][k], &a[q][k]);
}

// ham bien doi ma tran thanh dang tam giac tren
int GUASS(float a[][max], int n)
{
    float m;
    int i, j, k;
    for (i = 1; i < n; i++) {
        if (a[i][i] == 0) {
            for (j = i + 1; j <= n; j++) 
            if (a[j][i] != 0) break;

            if (j <= n) doidong(a, n, i, j);
            else return 0;
        }

        for (j = i + 1; j <= n; j++) {
            m = -a[j][i] / a[i][i];
            for (k = i; k <= n + 1; k++) {
                a[j][k] += a[i][k] * m;
            }
        }
    }
    return 1;
}

void timnghiem(float a[][max], int n)
{
    float x[max];
    int i, j;
    for (i = n; i >= 1; i--) {
        float S = a[i][n + 1];
        for (j = i + 1; j <= n; j++) 
            S -= a[i][j] * x[j];
            x[i] = S / a[i][i];
    } 

    for (int i = 1; i <= n; i++) {
        printf("x%d = %.2f\t", i, x[i]);
    }
}
int main()
{
    float a[max][max];
    int n;
    printf("Nhap n: "); scanf("%d", &n);
    nhap(a, n);
    xuat(a, n);

    int result = GUASS(a, n);
    xuat(a, n);
    if (result) {
        printf("Nghiem cua ma tran la: \n");
        timnghiem(a, n);
    } else printf("ma tran vo nghiem\n");

    return 0;
}