#include <stdio.h>

int main() {
	int num1,num2;
	int i, j;

	scanf("%d", &num1);
	num2 = num1;
	for (i = 0; i < num1; i++) {
		for (j = 0;j<i;j++)
			printf(" ");
		for (j = 0; j < num2 * 2 - 1; j++) 
			printf("%c", '*');
		num2--;
		printf("\n");

	}
	return 0;
}