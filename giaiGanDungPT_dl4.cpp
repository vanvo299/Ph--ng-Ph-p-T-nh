// GIẢI GẦN ĐÚNG PHƯƠNG TRÌNH
// TÁCH NGHIỆM: ĐỊNH LÝ 4
#include <stdio.h>
#include <math.h>
void Nhap(float arr[], int n)
{
    printf("Nhap he so cua phuong trinh: ");
    for (int i = 0; i <= n; i++) {
        scanf("%f", &arr[i]);
    }
}
void timCan(float arr[], int n)
{
    float b[10];
    int count = 0, m;
    for (int i = 0; i <= n; i++) {
        if (arr[i] < 0) {
            b[count++] = arr[i];
        }
    }
    if (count == 0) {
        printf("Phuong trinh khong co nghiem duong\n");
        return;
    }
    float a = fabs(b[0]);
    for (int i = 0; i < count; i++) {
        if (fabs(b[i]) > a) {
            a = fabs(b[i]);
        }
    }
   
    for (int i = 0; i <= n; i++) {
        if (arr[i] < 0) {
            m = i;
            break;
        }
    }
    
    float N = 1 + (float) pow(a/arr[0], 1.0/m);
    printf("Can tren cua nghiem duong la: %f\n", N);
}
int main()
{
    float arr[20];
    int n;
    printf("Nhap bac cua phuong trinh: ");
    scanf("%d", &n);
    Nhap(arr, n);
    timCan(arr, n);
    return 0;
}