#include <stdio.h>
#include <math.h>

#define max 10
#define EPS 1e-3

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

int gauss_seidel(float a[][max], int n, float x[max]) {
    int count = 0;
    float y[max];
    int t = 0;
    printf("%8.3f %8.3f %8.3f\n", x[1], x[2], x[3]);
    printf("---------------------------------------\n");
    do {
        count++;
        for (int i = 1; i <= n; i++) {
            float S = 0;
            for (int j = 1; j <= n; j++) {
                if (j != i) {
                    S += a[i][j] * x[j];
                }
            }
            y[i] = (a[i][n + 1] - S) / a[i][i];
        }

        // Kiểm tra điều kiện dừng
        for (int i = 1; i <= n; i++) {
            if (fabs(y[i] - x[i]) >= EPS) {
                t = 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            x[i] = y[i];
        }
        printf("%8.3f %8.3f %8.3f\n", x[1], x[2], x[3]);
    } while (count < 10); 

    return 1; 
}

int main() {
    float a[max][max], x[max];
    int n;

    printf("Nhap n: ");
    scanf("%d", &n);

    nhap(a, n);
    xuat(a, n);

    printf("Nhap xap xi nghiem ban dau: ");
    for (int i = 1; i <= n; i++) {
        scanf("%f", &x[i]);
    }

    if (gauss_seidel(a, n, x)) {
        printf("Nghiem cua he phuong trinh la: ");
        for (int i = 1; i <= n; i++) {
            printf("%8.3f ", x[i]);
        }
        printf("\n");
    } else {
        printf("He phuong trinh khong co nghiem\n");
    }

    return 0;
}
