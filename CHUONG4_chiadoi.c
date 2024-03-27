// CHƯƠNG 4: Chính xác hóa nghiệm bằng pp chia đôi
#include <stdio.h>
#include <math.h>
#define EPS 1e-6
int n;
float arr[100];
float a, b, c, fa, fc;
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

void chinhXacHoaNghiem(float a, float b)
{
    do {
        c = (float)(a + b) * 1.0 / 2;
        fa = f(a);
        fc = f(c);
        if (fa * fc < 0) b = c;
        else a = c;
    } while ((fc != 0) && fabs(a - b) >= EPS);
     printf("Nghiem cua phuong trinh la: %f, %f, %f\n", a, b, c);
}
int main()
{
    printf("Nhap bac cua da thuc: ");
    scanf("%d", &n);
    input(n);
    printf("Nhap a va b: ");
    scanf("%f%f", &a, &b);
    chinhXacHoaNghiem(a, b);
    return 0;
}