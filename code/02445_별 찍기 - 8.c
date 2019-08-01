#include <stdio.h>

int main() {
	int num1,num2;
	int i, j;

	scanf("%d", &num1);
	
	for (i = 0; i < num1 - 1; i++) {
		for (j = 0; j <= i; j++)
			printf("%c", '*');
		for (j = 0; j < (num1 - i-1) * 2; j++)
			printf(" ");
		for (j = 0; j <= i; j++)
			printf("%c", '*');
		printf("\n");
	}
	num2 = num1;
	for (i = 0; i < num1; i++) {
		for (j = 0; j < num2; j++)
			printf("%c", '*');
		for (j = 1; j < i * 2 + 1; j++)
			printf(" ");
		for (j = 0; j < num2; j++)
			printf("%c", '*');
		num2--;
		printf("\n");
	}

	return 0;
}
