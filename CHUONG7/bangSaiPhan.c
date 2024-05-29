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

void inBangSaiPhan(float x[], float y[], float a[][10], int n)
{
    for (int i = 0; i < n; i++) {
        a[i][0] = y[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i; j++) {
            a[i][j] = a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%8.2f ", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Nhap n: "); 
    scanf("%d", &n);
        

    float x[n], y[n], a[n][10]; 
    Nhap(x, y, n);
    inBangSaiPhan(x, y, a, n);
    return 0;
}
