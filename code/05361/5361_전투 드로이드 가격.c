#include <stdio.h>
#define A 350.34
#define B 230.90
#define C 190.55
#define D 125.30
#define E 180.90

int main() {
	int num1,num2,i,j;
	double arr[5] = { A,B,C,D,E };
	double sum=0.0;
	double arr2[100];

	scanf("%d", &num1);
	for (i = 0; i < num1; i++) {
		sum = 0.0;
		for (j = 0; j < 5; j++) {
			scanf("%d", &num2);
			sum += (double)num2*(arr[j]);
		}
		arr2[i] = sum;
	}

	for (i = 0; i < num1; i++) {

		printf("$%.2lf\n", arr2[i]);
	}

	return 0;
}