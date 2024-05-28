#include <stdio.h>
#include <math.h>
#include <string.h>
#define max 10

char readfile(float x[], float y[], int *n, char filename[]){
	FILE *file;
	file = fopen(filename, "r");
	if(file == NULL){
		return 'k';
	}
	fscanf(file, "%d", n);
	for(int i = 0; i < *n; i++){
		fscanf(file, "%f", &x[i]);
	}
	for(int i = 0; i < *n; i++){
		fscanf(file, "%f", &y[i]);
	}
	fclose(file);
	return 'c';
}

float Ayken_dang1(float x[], float y[], int n, float c){
	float w = 1, s = 0, d;
	for(int i = 0; i < n; i++){
		if(c == x[i]){
			return y[i];
		}
	}
    for (int i = 0; i < n; i++){ 
        w = w * (c - x[i]);
        d = c - x[i];
            for (int j = 0; j < n; j++){
                if (j != i){
                    printf("%8.3f", x[i] - x[j]);
                    d *= x[i] - x[j];
                }else{
                    printf("%8.3f", c - x[i]);
                }
            }
        printf("%8.3f", d);
        printf("%8.3f\n", y[i]/d);
        s+=y[i]/d;
    }
    printf(" W(%.3f) = %.3f\n", c, w);
	return w * s;
}

void xuat(float a[], int n){
	for(int i = 0; i <= n; i++){
		printf("%8.3f", a[i]);
	}
	printf("\n");
}

int main(){
	float x[max], y[max], c;
	int n;
	char filename[50], q[5], e[1];
	do{
		printf(" Nhap ten file: ");
		gets(filename);
		if(readfile(x, y, &n, filename) == 'k'){
			printf(" File %c khong co data hoac khong ton tai\n", filename);
			continue;
		}
		printf(" Nhap c = ");
		scanf("%f", &c);
		printf("\n f(%.3f) = %.3f", c, Ayken_dang1(x, y, n, c));
		
		printf("\n Nhap q de ket thuc: ");
		gets(q);
		scanf("%c", &q);
		printf("\n\n");
	}while(q[5] != 'q');
	
	return 0;
}









