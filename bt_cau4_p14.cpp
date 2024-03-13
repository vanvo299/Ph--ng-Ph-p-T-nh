//4. Viết chương trình (có sử dụng hàm ở câu 3) nhập vào 2 giá trị a, b. Tính p(a) + p(b)
// câu 3 là câu sơ đồ hoocner để tính giá trị của biểu thức
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
    float c[100], a, b;
    int n;
    printf("Nhap bac cua phuong trinh: ");
    scanf("%d", &n);
    Nhap(c, n);
    printf("Nhap a, b: ");
    scanf("%f %f", &a, &b);
    float p = tinh(c, n, a) + tinh(c ,n, b);
    printf("Gia tri cua p(%.2f) + p(%.2f) = %.2f\n", a, b, p);
    return 0;
}