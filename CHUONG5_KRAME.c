// Giải hệ phương trình bằng phương pháp Krame
#include <stdio.h>
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

// hàm tính định thức của các ma trận con
float DET(float a[][max], int n)
{
    float duongCheo = 1;
    float m;
    int i, j, k, count = 0;
    for (i = 1; i < n; i++) {
        if (a[i][i] == 0) {
            for (j = i + 1; j <= n; j++) 
            if (a[j][i] != 0) break;

            if (j <= n) {
                doidong(a, n, i, j);
                ++count;
            }
            else return 0;
        }

        for (j = i + 1; j <= n; j++) {
            m = -a[j][i] / a[i][i];
            for (k = i; k <= n + 1; k++) {
                a[j][k] += a[i][k] * m;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
            duongCheo *= a[i][i];
    }
    if (count % 2 != 0) {
        duongCheo *= -1;
    }
    return duongCheo;
}

// hàm tìm các ma trận thỏa mãn
void timMaTran(float a[][max], int n, float b[][max], int k)
{
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (j == k) b[i][j] = a[i][n+1];
            else b[i][j] = a[i][j];
        }
    }
}

// hàm tính nghiệm của hệ phuong trình (nghiệm được lưu vào mảng x)
int krame(float a[][max], int n, float x[])
{
    float b[max][max];
    timMaTran(a, n, b, 0);
    float det = DET(b, n);
    if (det != 0) {
        for (int i = 1; i <= n; i++) {
            timMaTran(a, n, b, i);
            x[i] = DET(b, n) / det;
        }
        return 1;
    } else return 0;
}
int main()
{
     float a[max][max], x[max];
    int n;
    printf("Nhap n: "); scanf("%d", &n);
    nhap(a, n);
    xuat(a, n);

    float result = DET(a, n);
    xuat(a, n);
    printf("Det = %f\n", result);

    int ketQua_krame = krame(a, n, x);
    if (ketQua_krame) {
        printf("Nghiem cua he phuong trinh la: ");
        for (int i = 1; i <= n; i++) {
            printf("x%d = %f\t", i, x[i]);
        }
    } else printf("He phuong trinh khong co nghiem\n");

    return 0;
}