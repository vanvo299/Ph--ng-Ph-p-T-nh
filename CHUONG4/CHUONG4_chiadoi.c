// CHƯƠNG 4: Chính xác hóa nghiệm bằng pp chia đôi
#include <stdio.h>
#include <math.h>
#define EPS 1e-6
int n;
float arr[100];
float a, b, c, t1, t2, t3;
void input(int n)
{
    printf("Nhap he so cua da thuc: ");
    for(int i=0; i<=n; i++) {
        scanf("%f", &arr[i]);
    }
}

// tinh da thuc
float f(float x)
{
	float value = 0;
	for (int i = n; i >= 0; i--)
	{
		value += pow(x, i) * arr[n - i];
	}
	return value;
}
// hàm tìm nghiệm chính xác bằng phương pháp chia đôi
int PPchiaDoi(float (*f)(float), float a, float b, float *q)
{
    float t1 = f(a), t2 = f(b);
    if (t1 * t2 > 0) return 0;
    if (!t1) {
        *q = a;
        return 1;
    }
    if (!t2) {
        *q = b;
        return 1;
    }
    float c;
    do {
        c = (float) (a + b) * 1.0 / 2;
        t3 = f(c);
        if (t1 * t3 < 0) b = c;
        else a = c;
    } while (fabs(t3) > EPS);
    *q = c;
    return 1;
    }
int main()
{
    printf("Nhap bac cua da thuc: ");
    scanf("%d", &n);
    input(n);
    printf("Nhap a va b: ");
    scanf("%f%f", &a, &b);
    float q;
    float result = PPchiaDoi(f, a, b, &q);
    if (result) {
        printf("Nghiem cua phuong trinh la: %f\n", q);
    } else printf("Khong co nghiem tren a, b\n");
    return 0;
}