#include <stdio.h>

int main() {
	int num1, num2, num3;
	int i,j,sum=0;
	int arr[10];

	scanf("%d", &num1);
	for (i = 0; i < num1; i++) {
		scanf("%d", &num2);
		for (j = 0; j < num2; j++) {
			scanf("%d", &num3);
			sum += num3;
		}
		arr[i] = sum;
		sum = 0;
	}
	for (i = 0; i < num1; i++)
		printf("%d\n", arr[i]);
	return 0;
}