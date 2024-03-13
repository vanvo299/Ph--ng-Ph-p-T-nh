/*
5. Viết chương trình nhập vào 2 đa thức pn(x) bậc n, pm(x) bậc m và hai giá 
trị c, d. Sử dụng hàm ở câu 3 tính:
a. pn(c) + pm(c)
b. pn(c) + pm(d)
*/
#include <stdio.h>
#include <math.h>
void Nhap(float a[100], int n)
{
    printf("Nhap he so cua phuong trinh: ");
    for (int i = 0; i <= n; i++) {
        scanf("%f", &a[i]);
    }
}

float Tinh(float a[100], int n, float c)
{
    float P = a[0];
    for (int i = 1; i <= n; i++) {
        P = P * c + a[i];
    }
    return P;
}
int main()
{
    float a[100], b[100], c, d;
    int n, m;
    printf("Nhap bac cua phuong trinh dau tien: ");
    scanf("%d", &n);
    printf("Nhap bac cua phuong trinh thu hai: ");
    scanf("%d", &m);
    Nhap(a, n);
    Nhap(b, m);
    // a. pn(c) + pm(c)
    printf("Cau a : \n");
    printf("Nhap c: "); 
    scanf("%f", &c);
    
    
    printf("Pn(%.2f) + Pm(%.2f) = %.2f\n", c, c, Tinh(a, n, c) + Tinh(b, m, c));

    // b. pn(c) + pm(d)
    printf("\nCau b: \n");
    printf("Nhap c: ");
    scanf("%f", &c);
    printf("Nhap d: ");
    scanf("%f", &d);

    printf("Pn(%.2f) + Pm(%.2f) = %.2f\n", c, d, Tinh(a, n, c) + Tinh(b, m, d));

    return 0;
}