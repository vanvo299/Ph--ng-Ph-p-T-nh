// Giải hệ phương trình bằng phương pháp giảm dư
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

int GIAMDU(float a[][max], int n, float x[])
{
    float r[n];

    // Biến đổi hệ phương trình từ dạng (1) về dạng (2)`
    for (int i = 1; i <= n; i++) {
        float h = a[i][i];
        for (int j = 1; j <= n + 1; j++) {
            if (i != j) {
                a[i][j] = a[i][j] / h;
            }
            a[i][i] = 1;
        }
    }

    // Tính r[i] ban đầu
        for (int i = 1; i <= n; i++) {
            r[i] = a[i][n + 1];
            for (int j = 1; j <= n; j++) {
                r[i] = r[i] - a[i][j] * x[j];
            }
        }
            int t;
            int count = 0;
            do {
                t = 0;

                // Tìm |Rs| = max{|r[i|} và tính lại Xs
                float lonNhat = fabs(r[1]);
                int pos = 1;
                for (int i = 2; i <= n; i++) {
                    if (fabs(r[i]) > lonNhat) {
                        lonNhat = fabs(r[i]);
                        pos = i;
                    }
                }
                    float d = r[pos];
                    x[pos] = x[pos] + r[pos];

                    // Tính lại r[i] kiểm tra khả năng tiếp theo
                    r[pos] = 0; 
                    for (int i = 1; i <= n; i++) {
                        if (i != pos) {
                            r[i] -= a[i][pos] * d;
                            if (fabs(r[i]) > EPS) t = 1;
                        }
                    }
                count++;
                if (count == 10000) return 0;
            } while(t);
            return 1;
        }


int main()
{
    float a[max][max], x[max];
    int n;
    printf("Nhap n: "); scanf("%d", &n);
    nhap(a, n);
    printf("Nhap xap xi nghiem ban dau: ");
    for (int i = 1; i <= n; i++) {
        scanf("%f", &x[i]);
    }
    xuat(a, n);

    int result = GIAMDU(a, n, x);
    if (result) {
        printf("Nghiem cua he phuong trinh la: ");
        for (int i = 1; i <= n; i++) {
            printf("%8.3f ", x[i]);
        }
    } else printf("Khong co nghiem\n");
    return 0;
}