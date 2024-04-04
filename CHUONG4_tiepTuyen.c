#include <stdio.h>
#include <math.h>
const int MAX_COUNT = 1000;
const float EPS = 1e-6;

// hàm f(x)
float f(float x)
{
    float result = pow(x, 4) - 4 * x - 1;
    // float result = pow(x, 3) + x - 5;
    return result;
}
// hàm đạo hàm cấp 2 của phương trình
float fdh(float x)
{
    float result = 4 * pow(x, 3) - 4;
    // float result = 3 * pow(x, 2) + 1;
    return result;
}

// hàm tìm nghiệm gần đúng bằng phương pháp tiếp tuyến
int PPtiepTuyen(float (*f)(float), float (*fdh)(float), float x, float *q)
{
    float y;
    int count = 0;
    printf("      x       ||        f(x)/f'(x)         \n");
    printf("-----------------------------\n");
    printf("  %f   ||      %f\n", x, f(x) / fdh(x));
    while (count < MAX_COUNT) {
        y = x;
        x = y - (f(y) / fdh(y));
        printf("  %f   ||      %f\n", x, f(x) / fdh(x));
        if (fabs(x - y) <= EPS) {
            *q = x;
            return 1;
        }
        count++;
    }
    return 0;
}
int main()
{
    float x, q;
    printf("Nhap x: ");
    scanf("%f", &x);
    float ketQua = PPtiepTuyen(f, fdh, x, &q);
    if (ketQua) {
        printf("Nghiem cua phuong trinh la: %f\n", q);
    } else printf("Phuong trinh khong co nghiem\n");
    return 0;
}