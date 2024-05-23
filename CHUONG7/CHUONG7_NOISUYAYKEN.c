// Bảng nội suy ayken
#include <stdio.h>
#include <stdlib.h>

void Nhap(float x[], float y[], int n)
{
    printf("Nhap x[]: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }
    printf("Nhap y[]: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &y[i]);
    }
}
// bảng nội suy ayken 1
float bangNoiSuyAyken(float x[], float y[], int n, float c)
{
    float w = 1, s = 0;
    for (int i = 0; i < n; i++) {
        float d = 1;
        w *=(c - x[i]);
        d = c - x[i];
        for (int j = 0; j < n; j++)
            if (j != i) d *= x[i] - x[j];
            s += y[i]/d; 
    }
    return w*s;
}

// bảng nội suy ayken 2
float bangNoiSuyAyKen2(float x[], float y[], int n, float c) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // j < n thay vì j <= n
            y[j] = (y[i] * (x[j] - c) - y[j] * (x[i] - c)) / (x[j] - x[i]);
        }
    }
    return y[n-1]; // Trả về giá trị cuối cùng của mảng y
}

int main()
{
    float x[10], y[10], c;
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("Nhap c: ");
    scanf("%f", &c);
    Nhap(x, y, n);
    float result = bangNoiSuyAyken(x, y, n, c);
    printf("f(%.1f) = L%d(%.1f) = %f\n", c, n - 1, c, result);
    float result2 = bangNoiSuyAyKen2(x, y, n, c);
    printf("f(%.1f) = L%d(%.1f) = %f\n", c, n - 1, c, result2);

    return 0;
}