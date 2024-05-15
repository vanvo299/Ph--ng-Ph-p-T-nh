// Tìm vecto riêng của ma trận
#include <stdio.h>
#include <math.h>
#define max 10

void nhap(float a[][max], int n)
{
    printf("Nhap ma tran can giai: \n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
}

void xuat(float a[][max], int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%8.3f ", a[i][j]);
        }
        printf("\n");
    }
}

void nhanHaiMaTran(float a[][max], float b[][max], int n, float c[][max])
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            c[i][j] = 0;
            for (int k = 1; k <= n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void maTranDonVi(float E[][max], int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) E[i][j] = 1;
            else E[i][j] = 0;
        }
    }
}
void giaiPTBac3(float x[], int n) {
    float delta = pow(x[2], 2) - 3 * x[1] * x[3];
    float k = (9 * x[1] * x[2] * x[3] - 2 * pow(x[2], 3) - 27 * pow(x[1], 2) * x[4]) / (2 * sqrt(fabs(pow(delta, 3))));

    if (delta > 0) {
        if (fabs(k) <= 1) {
            float x1 = (2 * sqrt(delta) * cos(acos(k) / 3) - x[2]) / (3 * x[1]);
            float x2 = (2 * sqrt(delta) * cos(acos(k) / 3 - (2 * 3.1415926535898 / 3)) - x[2]) / (3 * x[1]);
            float x3 = (2 * sqrt(delta) * cos(acos(k) / 3 + (2 * 3.1415926535898 / 3)) - x[2]) / (3 * x[1]);
            printf("Gia tri rieng: %.2f\t%.2f \t%.2f\n", x1, x2, x3);
        } else {
            float x0 = ((sqrt(delta) * fabs(k)) / (3 * x[1] * k)) * (pow(fabs(k) + sqrt(pow(k, 2) - 1), 1.0 / 3) + pow(fabs(k) - sqrt(pow(k, 2) - 1), 1.0 / 3)) - (x[2] / (3 * x[1]));
            printf("Gia tri rieng: %.2f\n", x0);
        }
    } else if (delta == 0) {
        float X = (-x[2] + pow(pow(x[2], 3) - 27 * pow(x[1], 2) * x[4], 1.0 / 3)) / (3 * x[1]);
        printf("Gia tri rieng: %.2f\n", X);
    } else {
        float X = (sqrt(fabs(delta)) / (3 * x[1])) * (pow(k + sqrt(pow(k, 2) + 1), 1.0 / 3) + pow(k - sqrt(pow(k, 2) + 1), 1.0 / 3)) - (x[2] / (3 * x[1]));
        printf("Gia tri rieng: %.2f\n", X);
    }
}

// Hàm giải hệ phương trình tuyến tính Ax = b bằng phương pháp Gauss-Jordan
void giaiHePTTuyenTinh(float a[][max], float b[], int n) {
    // Khai báo một ma trận mở rộng gồm ma trận a và vector b
    float aug[max][max + 1];

    // Sao chép ma trận a và vector b vào ma trận mở rộng
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            aug[i][j] = a[i][j];
        }
        aug[i][n + 1] = b[i];
    }

    // Áp dụng phương pháp Gauss-Jordan để biến đổi ma trận mở rộng về dạng bậc thang
    for (int i = 1; i <= n; i++) {
        // Chọn hàng chính để chia cho phần tử chính
        float pivot = aug[i][i];
        for (int j = 1; j <= n + 1; j++) {
            aug[i][j] /= pivot;
        }

        // Đưa các phần tử còn lại trong cột về 0
        for (int k = 1; k <= n; k++) {
            if (k != i) {
                float factor = aug[k][i];
                for (int j = 1; j <= n + 1; j++) {
                    aug[k][j] -= factor * aug[i][j];
                }
            }
        }
    }

    // Lưu vector kết quả vào mảng b
    for (int i = 1; i <= n; i++) {
        b[i] = aug[i][n + 1];
    }

    // In vector kết quả
    // printf("Nghiem cua he phuong trinh la:\n");
    // for (int i = 1; i <= n; i++) {
    //     printf("%.3f\n", b[i]);
    // }
}
void GTR_VTR(float a[][max], int n)
{
    float M[max][max], M1[max][max], C[max][max], b[max][max];
    maTranDonVi(C, n);
    for (int k = n - 1; k >= 1; k--) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != k) {
                    if (i == j) {
                        M[i][j] = 1; 
                        M1[i][j] = 1;
                    } else {
                        M[i][j] = 0; 
                        M1[i][j] = 0;
                    }
                } else {
                    M1[i][j] = a[k + 1][j];
                    if (j == k) M[i][j] = 1.0 / a[k + 1][k];
                    else M[i][j] = -a[k + 1][j] / a[k + 1][k];
                }
            }
        }
        nhanHaiMaTran(a, M, n, b);
        nhanHaiMaTran(M1, b, n, a);
        nhanHaiMaTran(C, M, n, b);
        // Gan lai C = b;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                C[i][j] = b[i][j];
            }
        }
    printf("Ma tran M1, M2: \n");
    xuat(b, n);
    }
    float x[n + 1];
    x[1] = 1.0;
    printf("Ma tran dang Danhilepski la: \n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%8.3f ", a[i][j]);
        }
        printf("\n");
    }  
    for (int j = 1; j <= n + 1; j++) {
        x[j + 1] = -a[1][j];
    }
    giaiPTBac3(x, n);

}
int main()
{
    float a[max][max];
    int n;
    printf("Nhap n: "); scanf("%d", &n);
    nhap(a, n);
    printf("Ma tran sau khi nhap la: \n");
    xuat(a, n);

    GTR_VTR(a, n);
    return 0;
}